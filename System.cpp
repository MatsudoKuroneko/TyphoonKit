#include "DxLib.h"
#include "FPS.h"
#include "SceneManager.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	/*
		‰ŠúÝ’è
	*/

	SetGraphMode(1280, 960, 16, 60);
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowSizeChangeEnableFlag(TRUE);
	SetOutApplicationLogValidFlag(FALSE);
	SetMainWindowText("Danmaku Template");
	//SetWindowSizeExtendRate(0.75);
	DxLib_Init();
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING);
	SetFontThickness(0);



	if (ChangeWindowMode(TRUE) != 0) {
		return 0;
	}
	if (DxLib_Init() != 0) {
		return 0;
	}
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) {
		DxLib_End();
		return 0;
	}

	/*
		ƒƒCƒ“ˆ—
	*/

	SceneManager sman;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		if (CheckHitKey(KEY_INPUT_P)) {
			DATEDATA Date;
			SaveDrawScreen(0, 0, 1280, 960, "ss.bmp");
			DrawFormatString(1200, 600, GetColor(255, 255, 255), "Shot!->ss.bmp");
		}
		FPS_Update();
		FPS_Draw();
		FPS_Wait();

		if (!sman.loop()) {
			break;
		}
	}

	DxLib_End();
	return 0;
}