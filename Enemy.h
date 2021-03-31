
#pragma once
#include <vector>
#include <DxLib.h>
#include "Score.h"
#include "Sprite.h"
#include "Score.h"
#include "Load.h"
#include "Define.h"
#include "BulletManager.h"
#include "ParticleManager.h"
#include "DammakuUtil.h"

enum EnemyDatas {
	REIKON_RED,
	REIKON_ORANGE,
	REIKON_YELLOW,
	REIKON_GREEN,
	REIKON_SKY,
	REIKON_BLUE,
	REIKON_PURPLE,
	REIKON_PINK,
	REIKON_WHITE,
	Boss_StEX,
};

class EnemyImage
{
private:
	EnemyImage() {
		addGroup("Resource/img/particle/reikon.png", 9, 9, 1, 16, 16, N);
		addGroup("Resource/img/bossdot/ex.png", 1, 1, 1, 49, 64, B);
	};
	~EnemyImage() = default;
	std::vector<int> _imgs;
	int N[9],B[1];
public:

	static EnemyImage* Instance() {
		static EnemyImage inst;
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

	void addGroup(const char* fileName, int n, int xn, int yn, int w, int h, int* buf)
	{
		int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);
		for (int i = 0; i < n; i++) {
			_imgs.push_back(buf[i]);
		}
		return;
	};

	const int Get(EnemyDatas data) {

		return _imgs[data];

	};
};

class Enemy:public Sprite
{
public:
	Enemy(int x, int y, float speed, int hp, EnemyDatas image, int pattern, int delay, int custom) {
		_x = x;
		_y = y;
		_showx = 352 + Score::Instance()->GetScore(CameraX) + _x;
		_speed = speed;
		_hp = hp;
		_image = image;
		_pattern = pattern;
		_delay = Score::Instance()->GetScore(Gametime) + delay;
		_imgsize = 1.6;
		_age = 0;
		_custom = custom;
		_bulletcount = 0;
		_rotation = 0;
		_upcount = 0;
		_showyd = 0;
		if (_pattern == 0) {
			_mx = 0;
			_my = 40;
		}
	}
	~Enemy() = default;

	virtual bool update() override;
	virtual void draw() const override;
private:
	EnemyDatas _image;
	int _x,_showx,_hp,_pattern,_age, _delay, _rotation, _custom, _bulletcount;
	short int _upcount;
	float _y,_showyd,_speed, _imgsize, _mx, _my;
	bool exist, _updirection = true;

};

