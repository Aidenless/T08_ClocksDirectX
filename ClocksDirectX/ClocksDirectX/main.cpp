#include <windows.h>
#include <string>
#include <cassert>
#include <d3d11.h>
#include <iomanip>

#include "WindowUtils.h"
#include "D3DUtil.h"
#include "D3D.h"
#include "SimpleMath.h"
#include "SpriteFont.h"
#include "game.h"

using namespace std;
using namespace DirectX;
using namespace DirectX::SimpleMath;


/*
Blank solution - setup DX11 and blank the screen
*/

const int MAX_COLOURS = 8;
Vector4 gColours[MAX_COLOURS];
int gCycle = 0;
float gTime = 0;
DirectX::SpriteFont *gpFont = nullptr, *gpFont2 = nullptr;
DirectX::SpriteBatch *gpSpriteBatch = nullptr;
float gResTimer = 0;
int gFrameCounter = 0;
float gFrameTimer = 0;


//if ALT+ENTER or resize or drag window we might want do
//something like pause the game perhaps, but we definitely
//need to let D3D know what's happened (OnResize_Default).
void OnResize(int screenWidth, int screenHeight, MyD3D& d3d)
{
	gResTimer = GetClock() + 2;
	d3d.OnResize_Default(screenWidth, screenHeight);
}

//messages come from windows all the time, should we respond to any specific ones?
LRESULT CALLBACK MainWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//do something game specific here
	switch (msg)
	{
		// Respond to a keyboard event.
	case WM_CHAR:
		switch (wParam)
		{
		case 27:
		case 'q':
		case 'Q':
			PostQuitMessage(0);
			return 0;
		}
	case WM_INPUT:
		Game::sMKIn.MessageEvent((HRAWINPUT)lParam);
		break;
	}


	//default message handling (resize window, full screen, etc)
	return WinUtil::Get().DefaultMssgHandler(hwnd, msg, wParam, lParam);
}

//main entry point for the game
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
				   PSTR cmdLine, int showCmd)
{

	int w(1200), h(800);
	if (!WinUtil::Get().InitMainWindow(w, h, hInstance, "Clocks", MainWndProc, true))
		assert(false);

	MyD3D d3d;
	if (!d3d.InitDirect3D(OnResize))
		assert(false);
	WinUtil::Get().SetD3D(d3d);
	d3d.GetCache().SetAssetPath("data/");
	Game game(d3d);

	bool canUpdateRender;
	float dTime = 0;
	while (WinUtil::Get().BeginLoop(canUpdateRender))
	{
		if (canUpdateRender)
		{
			game.Update(dTime);
			game.Render(dTime);
		}
		dTime = WinUtil::Get().EndLoop(canUpdateRender);
		gFrameCounter++;
	}

	game.Release();
	d3d.ReleaseD3D(true);	
	return 0;
}