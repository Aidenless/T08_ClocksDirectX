#pragma once

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "D3D.h"
#include "SpriteFont.h"
#include "Sprite.h"
#include "SpriteBatch.h"
#include "Input.h"
#include "random.h"
#include "utility.h"

class Game {
private:
	MyD3D& mD3D;
	DirectX::SpriteBatch* mpSB = nullptr;
	DirectX::SpriteFont* mpF = nullptr;
	Sprite digitalClock;
	std::vector<Sprite> clockFace;
	std::vector<Sprite> minuteHand;
	std::vector<Sprite> hourHand;

	static const int CLOCKS = 3;

	std::string digitalTime = "HH:MM:SS";
	std::string AMorPM = "AM";
	std::string header = "Ready to play ? ";
	std::string gameInfo = "Which clock shows the same time as the digital one? 1 or 2 or 3";

	int correctClock = 0;
	int answer = 3;
	bool firstRound = true;
	bool update = true;

	int min[3];
	int hour[3];

	int hourR;
	int minR;

	random mRandom;
	Utility mUtility;

public:
	Game(MyD3D& d3d);
	static MouseAndKeys sMKIn;

	void init(MyD3D& d3d);

	void Update(float dTime);
	void Render(float dTime);
	void Release();

	void RenderText(DirectX::SpriteBatch& batch, DirectX::SpriteFont& font);

	enum gameStates { INITIALIZE, PLAYING, GAMEOVER };
	gameStates state = INITIALIZE;
};