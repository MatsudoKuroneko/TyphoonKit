#pragma once
#include <vector>
#include <DxLib.h>
#include "Score.h"
#include "Sprite.h"
#include "Score.h"
#include "Define.h"
#include "DammakuUtil.h"
#include "BulletBreakManager.h"

enum ShotDatas {
	DS_BALL_S_RED,
	DS_BALL_S_ORANGE,
	DS_BALL_S_YELLOW,
	DS_BALL_S_GREEN,
	DS_BALL_S_SKY,
	DS_BALL_S_BLUE,
	DS_BALL_S_PURPLE,
	DS_BALL_S_PINK,
	DS_BALL_S_WHITE,
	DS_BALL_M_RED,
	DS_BALL_M_ORANGE,
	DS_BALL_M_YELLOW,
	DS_BALL_M_GREEN,
	DS_BALL_M_SKY,
	DS_BALL_M_BLUE,
	DS_BALL_M_PURPLE,
	DS_BALL_M_PINK,
	DS_BALL_M_WHITE,
	DS_DIA_RED,
	DS_DIA_PINK,
	DS_DIA_YELLOW,
	DS_DIA_ORANGE,
	DS_DIA_LEAF,
	DS_DIA_GREEN,
	DS_DIA_BLUE,
	DS_DIA_DARKBLUE,
	DS_DIA_SKY,
	DS_DIA_PURPLE,
	DS_DIA_REDPURPLE,
	DS_DIA_DARK_RED,
	DS_DIA_DARK_PINK,
	DS_DIA_DARK_YELLOW,
	DS_DIA_DARK_ORANGE,
	DS_DIA_DARK_LEAF,
	DS_DIA_DARK_GREEN,
	DS_DIA_DARK_BLUE,
	DS_DIA_DARK_DARKBLUE,
	DS_DIA_DARK_SKY,
	DS_DIA_DARK_PURPLE,
	DS_DIA_DARK_REDPURPLE,
	DS_DIA_BLACK,
	DS_DIA_WHITE,
	DS_FIRE_RED,
};

class ShotData
{
private:
	ShotData() {
		addGroup("Resource/img/bullet/normal.png", 9, 9, 1, 24, 24, N);
		addGroup("Resource/img/bullet/medium.png", 9, 9, 1, 48, 48, M);
		addGroup("Resource/img/bullet/dia.png", 22, 22, 1, 16, 32, D);
		addGroup("Resource/img/bullet/diamono.png", 2, 2, 1, 16, 32, DM);
		addGroup("Resource/img/bullet/firepurple.png", 4, 4, 1, 48, 48, FIRE);
	};
	~ShotData() = default;
	std::vector<int> _imgs;
	int N[9],M[9],D[22],DM[2], FIRE[4];
public:

	static ShotData* Instance() {
		static ShotData inst;
		return &inst;
	};

	void load() {  }//コンストラクタ起動用。SceneManagerで起動させるようにする。

	void release()
	{
		const int size = _imgs.size();
		for (int i = 0; i < size; i++) {
			DeleteGraph(_imgs[i]);
		}
		_imgs.clear();
	};

	void addSingle(const char* fileName)
	{
		int ret = LoadGraph(fileName);
		_imgs.push_back(ret);

		return;
	};


	void addGroup(const char* fileName, int n, int xn, int yn, int w, int h, int* buf)
	{
		int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
		for (int i = 0; i < n; i++) {
			_imgs.push_back(buf[i]);
		}
		return;
	};

	const int Get(ShotDatas data) {
		switch (data)
		{
					/*
		case(DS_BALL_S_RED):
		case(DS_BALL_S_ORANGE):
		case(DS_BALL_S_YELLOW):
		case(DS_BALL_S_GREEN):
		case(DS_BALL_S_SKY):
		case(DS_BALL_S_BLUE):
		case(DS_BALL_S_PURPLE):
		case(DS_BALL_S_PINK):
		case(DS_BALL_S_WHITE):
		case(DS_BALL_M_RED):
		case(DS_BALL_M_ORANGE):
		case(DS_BALL_M_YELLOW):
		case(DS_BALL_M_GREEN):
		case(DS_BALL_M_SKY):
		case(DS_BALL_M_BLUE):
		case(DS_BALL_M_PURPLE):
		case(DS_BALL_M_PINK):
		case(DS_BALL_M_WHITE):
		case(DS_DIA_RED):
		case(DS_DIA_PINK):
		case(DS_DIA_YELLOW):
		case(DS_DIA_ORANGE):
		case(DS_DIA_GREEN):
		case(DS_DIA_BLUE):
		case(DS_DIA_DARKBLUE):
		case(DS_DIA_SKY):
		case(DS_DIA_PURPLE):
		case(DS_DIA_WHITE):*/
		case(DS_FIRE_RED):
			
			if ((Score::Instance()->GetScore(Gametime) % 28 >= 0 && Score::Instance()->GetScore(Gametime) % 28 < 4)|| (Score::Instance()->GetScore(Gametime) % 28 >= 24 && Score::Instance()->GetScore(Gametime) % 28 < 28)) {
				return _imgs[42];
			}
			if ((Score::Instance()->GetScore(Gametime) % 28 >=4 && Score::Instance()->GetScore(Gametime) % 28 < 8) || (Score::Instance()->GetScore(Gametime) % 28 >= 20 && Score::Instance()->GetScore(Gametime) % 28 < 24))
				return _imgs[43];
			if ((Score::Instance()->GetScore(Gametime) % 28 >= 8 && Score::Instance()->GetScore(Gametime) % 28 < 12) || (Score::Instance()->GetScore(Gametime) % 28 >= 16 && Score::Instance()->GetScore(Gametime) % 28 < 20))
				return _imgs[44];
			if (Score::Instance()->GetScore(Gametime) % 28 >= 12 && Score::Instance()->GetScore(Gametime) % 28 < 16)
				return _imgs[45];
		
		default:
			return _imgs[data];

		}
	};
};

class Bullet : public Sprite
{
public:
	Bullet(int x, int y, float speed, float angle, float accel, int maxspeed, ShotDatas id, int delay,bool rad,int pattern,float custom) {
		_x = x;
		_y = y;
		_speed = speed;
		_accel = accel;
		_maxspeed = maxspeed;
		_age = 0;
		if (rad == false) {
			_angle = angle * Define::PI / 180;
			_showangle = (angle + 90) * Define::PI / 180;
		}
		else {
			_angle = angle;
			_showangle = (angle*180/ Define::PI + 90) * Define::PI / 180;
		}

		_id = id;
		_custom = custom;
		_delay = Score::Instance()->GetScore(Gametime) + delay;
		_pattern = pattern;

		if (_id == DS_BALL_S_RED || _id == DS_BALL_S_ORANGE || _id == DS_BALL_S_PINK || _id == DS_BALL_M_RED || _id == DS_BALL_M_ORANGE || _id == DS_BALL_M_PINK || _id == DS_DIA_RED || _id == DS_DIA_ORANGE || _id == DS_DIA_PINK || _id == DS_DIA_DARK_RED || _id == DS_DIA_DARK_ORANGE || _id == DS_DIA_DARK_PINK) {
			_systemcolor = 0;
		}
		else if (_id == DS_BALL_S_SKY || _id == DS_BALL_S_BLUE || _id == DS_BALL_S_PURPLE || _id == DS_BALL_M_SKY || _id == DS_BALL_M_BLUE || _id == DS_BALL_M_PURPLE || _id == DS_DIA_SKY || _id == DS_DIA_BLUE || _id == DS_DIA_PURPLE || _id == DS_DIA_DARK_SKY || _id == DS_DIA_DARK_BLUE || _id == DS_DIA_DARK_PURPLE || _id == DS_DIA_DARKBLUE || _id == DS_DIA_DARK_DARKBLUE) {
			_systemcolor = 1;
		}
		else if (_id == DS_BALL_S_GREEN || _id == DS_BALL_S_YELLOW || _id == DS_BALL_M_GREEN || _id == DS_BALL_M_YELLOW || _id == DS_DIA_GREEN || _id == DS_DIA_YELLOW || _id == DS_DIA_DARK_GREEN || _id == DS_DIA_DARK_YELLOW || _id == DS_DIA_LEAF || _id == DS_DIA_DARK_LEAF) {
			_systemcolor = 2;
		}
		else {
			_systemcolor = 3;
		}
	}
	~Bullet() = default;

	virtual bool update() override;
	virtual void draw() const override;
	bool _exist = true;
	float _x, _y;

private:
	ShotDatas _id;
	int _pattern,_delay,_age;
	float _showangle, _speed,_accel, _maxspeed, _angle, _custom;
	bool _bomb, _systemcolor;
};

