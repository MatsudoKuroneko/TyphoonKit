#include "DxLib.h"
#include "FPS.h"

static int mStartTime;				//測定開始時刻
static float mFps;					//fps
static int frame;
static const int N = 120;   //平均を取るサンプル数
static const int FPS = 120; //設定したFPS
int c;



bool FPS_Update()
{
	if (frame == 0)
	{ //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	if (frame % N == 0)
	{ //60フレーム目なら平均を計算する
		int t = GetNowCount();
		mFps = 1000.f / ((t - mStartTime) / (float)N);
		mStartTime = t;
	}
	frame++;
	return true;
}

void FPS_Draw()
{
	SetFontSize(12);
	if (mFps > 57) {
		c = GetColor(230, 179, 0);
	}
	else if (mFps < 30) {
		c = GetColor(64, 64, 255);
	}
	else {
		c = GetColor(255, 255, 255);
	}
	DrawFormatString(1120, 797, c, "%.1f", mFps);
}

void FPS_Wait()
{
	int tookTime = GetNowCount() - mStartTime; //かかった時間
}