#include "DxLib.h"
#include "FPS.h"

static int mStartTime;				//����J�n����
static float mFps;					//fps
static int frame;
static const int N = 120;   //���ς����T���v����
static const int FPS = 120; //�ݒ肵��FPS
int c;



bool FPS_Update()
{
	if (frame == 0)
	{ //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (frame % N == 0)
	{ //60�t���[���ڂȂ畽�ς��v�Z����
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
	int tookTime = GetNowCount() - mStartTime; //������������
}