#include "DxLib.h"
#include "FPS.h"
#include "SceneManager.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	/*
		初期設定
	*/

	SetGraphMode(1280, 720, 16, 60);
	ChangeWindowMode(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	//SetWindowStyleMode(9);
	SetAlwaysRunFlag(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
	//SetOutApplicationLogValidFlag(FALSE);
	SetMainWindowText("東方輝幻郷 Ver0.01a (まちカドまぞく2期放送記念バージョン)");
	//SetWindowSizeExtendRate(0.75);
	ChangeFont("Russell Square");
	if (DxLib_Init()) {
		return false;
	}
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
		メイン処理
	*/

	SceneManager sman;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		if (!sman.loop()) {
			break;
		}

		if (CheckHitKey(KEY_INPUT_P)) {
			DATEDATA Date;
			SaveDrawScreen(0, 0, 1280, 960, "ss.bmp");
			DrawFormatString(1200, 600, GetColor(255, 255, 255), "Shot!->ss.bmp");
		}

		FPS_Update();
		FPS_Draw();
		FPS_Wait();
	}

	DxLib_End();
	return 0;
}