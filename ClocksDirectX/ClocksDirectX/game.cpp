#include <ctime>	
#include <iostream>	
#include <sstream>	
#include <string>	
#include <iomanip>	
#include <assert.h>
#include <vector>

#include "game.h"
#include "SpriteFont.h"
#include "SpriteBatch.h"
#include "WindowUtils.h"
#include "CommonStates.h"
#include "Windows.h"
#include "D3DUtil.h"
#include "random.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;

MouseAndKeys Game::sMKIn;

Game::Game(MyD3D& d3d)
	:mD3D(d3d), mpSB(nullptr), digitalClock(d3d)
{
	sMKIn.Initialise(WinUtil::Get().GetMainWnd(), true, false);
	mpSB = new SpriteBatch(&mD3D.GetDeviceCtx());
	mpF = new SpriteFont(&mD3D.GetDevice(), L"data/fonts/digital-7.spritefont");
	Game::init(d3d);
}

void Game::Release()
{
	delete mpSB;
	mpSB = nullptr;
	delete mpF;
	mpF = nullptr;
}

void Game::init(MyD3D& d3d) {
	ID3D11ShaderResourceView* p = mD3D.GetCache().LoadTexture(&mD3D.GetDevice(), "digital_clock.dds");

	digitalClock.SetTex(*p);
	digitalClock.SetScale(Vector2(0.5, 0.5));
	digitalClock.mPos = Vector2(480, 50);

	clockFace.insert(clockFace.begin(), CLOCKS, Sprite(mD3D));
	p = mD3D.GetCache().LoadTexture(&mD3D.GetDevice(), "clock_face.dds");
	int offset = 0;
	int offsetIncrease = 300;
	for (int i = 0; i < CLOCKS; i++) {
		clockFace[i].SetTex(*p);
		clockFace[i].SetScale(Vector2(0.5, 0.5));
		clockFace[i].mPos = Vector2(180 + offset, 300);
		offset += offsetIncrease;
	}

	minuteHand.insert(minuteHand.begin(), CLOCKS, Sprite(mD3D));
	p = mD3D.GetCache().LoadTexture(&mD3D.GetDevice(), "minute_hand.dds");
	offset = 0;
	for (int i = 0; i < CLOCKS; i++) {
		minuteHand[i].SetTex(*p);
		minuteHand[i].SetScale(Vector2(0.25, 0.25));
		minuteHand[i].origin = Vector2(23, 451);
		minuteHand[i].mPos = Vector2(308 + offset, 430);
		offset += offsetIncrease;
	}

	hourHand.insert(hourHand.begin(), CLOCKS, Sprite(mD3D));
	p = mD3D.GetCache().LoadTexture(&mD3D.GetDevice(), "hour_hand.dds");
	offset = 0;
	for (int i = 0; i < CLOCKS; i++) {
		hourHand[i].SetTex(*p);
		hourHand[i].SetScale(Vector2(0.25, 0.25));
		hourHand[i].origin = Vector2(37, 317);
		hourHand[i].mPos = Vector2(308 + offset, 430);
		offset += offsetIncrease;
	}

	mRandom.seedGetRandom();
}

void Game::Update(float dTime) {
	switch (state) {
	case INITIALIZE:
		correctClock = mRandom.getRandomNum(0, 2);

		for (int i = 0; i < CLOCKS; i++) {
			min[i] = mUtility.getRandomMinute();
			hour[i] = mUtility.getRandomHour();
			minR = mUtility.minuteToRotation(min[i]);
			hourR = mUtility.hourToRotation(min[i], hour[i]);
			minuteHand[i].rotation = (minR * PI) / 180;
			hourHand[i].rotation = (hourR * PI) / 180;
		}

		digitalTime = mUtility.getTimeString(min[correctClock], hour[correctClock]);

		gameInfo = "Which clock shows the same time as the digital one? 1 or 2 or 3";
		answer = 3;

		state = PLAYING;
		break;

	case PLAYING:
		if (answer == 3) {
			if (sMKIn.IsPressed(VK_1)) {
				answer = 0;
			}
			if (sMKIn.IsPressed(VK_2)) {
				answer = 1;
			}
			if (sMKIn.IsPressed(VK_3)) {
				answer = 2;
			}
		}
		else {
			if (answer == correctClock) {
				gameInfo = "Correct! Try again?  y or n";
			}
			else {
				gameInfo = "Wrong! Try again?  y or n";
			}

			if (sMKIn.IsPressed(VK_Y)) {
				firstRound = false;
				state = INITIALIZE;
			}
			else if (sMKIn.IsPressed(VK_N)) {
				state = GAMEOVER;
			}
		}
		break;

	case GAMEOVER:
		PostQuitMessage(0);
		break;
	}

	if (firstRound) {
		digitalTime = mUtility.getTimeString(mUtility.getCurrentMinutes(), mUtility.getCurrentHours());
		AMorPM = mUtility.getAM_PM(mUtility.getCurrentHours());
		minuteHand[correctClock].rotation = (mUtility.getCorrectMinuteRotation() * PI) / 180;
		hourHand[correctClock].rotation = (mUtility.getCorrectHourRotation() * PI) / 180;

		for (int i = 0; i < CLOCKS; i++) {
			if (i != correctClock) {
				min[i] = mUtility.UpdateMinute(min[i], update);
				hour[i] = mUtility.UpdateHour(hour[i], min[i], update);
				minR = mUtility.minuteToRotation(min[i]);
				hourR = mUtility.hourToRotation(min[i], hour[i]);
				minuteHand[i].rotation = (minR * PI) / 180;
				hourHand[i].rotation = (hourR * PI) / 180;
			}
		}
	}
	else {
		for (int i = 0; i < CLOCKS; i++) {
			min[i] = mUtility.UpdateMinute(min[i], update);
			hour[i] = mUtility.UpdateHour(hour[i], min[i], update);
			minR = mUtility.minuteToRotation(min[i]);
			hourR = mUtility.hourToRotation(min[i], hour[i]);
			minuteHand[i].rotation = (minR * PI) / 180;
			hourHand[i].rotation = (hourR * PI) / 180;
		}

		digitalTime = mUtility.getTimeString(min[correctClock], hour[correctClock]);
		AMorPM = mUtility.getAM_PM(hour[correctClock]);
	}

	if (mUtility.getCurrentSeconds() == 0) {
		update = false;
	}
	else {
		update = true;
	}
}

void Game::Render(float dTime) {
	mD3D.BeginRender(Colours::Black);


	CommonStates dxstate(&mD3D.GetDevice());
	mpSB->Begin(SpriteSortMode_Deferred, dxstate.NonPremultiplied(), &mD3D.GetWrapSampler());

	digitalClock.Draw(*mpSB);

	for (auto& a : clockFace) {
		a.Draw(*mpSB);
	}

	for (auto& a : hourHand) {
		a.Draw(*mpSB);
	}

	for (auto& a : minuteHand) {
		a.Draw(*mpSB);
	}

	RenderText(*mpSB, *mpF);

	mpSB->End();

	mD3D.EndRender();
}

void Game::RenderText(DirectX::SpriteBatch& batch, DirectX::SpriteFont& font) {
	RECT r = font.MeasureDrawBounds(header.c_str(), Vector2(0, 0));
	Vector2 pos{ 20, 25 };
	font.DrawString(&batch, header.c_str(), pos, Colours::White, 0.f, Vector2(0, 0), 0.8f);

	r = font.MeasureDrawBounds(gameInfo.c_str(), Vector2(0, 0));
	pos = { 20, 600 };
	font.DrawString(&batch, gameInfo.c_str(), pos, Colours::White, 0.f, Vector2(0, 0), 0.5f);

	r = font.MeasureDrawBounds(digitalTime.c_str(), Vector2(0, 0));
	pos = { 499, 100 };
	font.DrawString(&batch, digitalTime.c_str(), pos, Colours::White, 0.f, Vector2(0, 0), 0.7f);

	r = font.MeasureDrawBounds(AMorPM.c_str(), Vector2(0, 0));
	pos = { 650, 150 };
	font.DrawString(&batch, AMorPM.c_str(), pos, Colours::White, 0.f, Vector2(0, 0), 0.55f);

	float offset = 0;
	float offsetIncrease = 300;
	for (int i = 1; i <= 3; i++) {
		string msg = to_string(i);
		r = font.MeasureDrawBounds(msg.c_str(), Vector2(0, 0));
		pos = { 175 + offset, 295 };
		font.DrawString(&batch, msg.c_str(), pos, Colours::White, 0.f, Vector2(0, 0), 0.8f);
		offset += offsetIncrease;
	}
}

