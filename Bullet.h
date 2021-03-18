#pragma once
#include <vector>
#include <DxLib.h>
#include "Score.h"
#include "Sprite.h"
#include "Score.h"
#include "Define.h"

enum ShotDatas {
	DS_BALL_SS_RED,
	DS_FIRE_RED,
};

class ShotData
{
private:
	ShotData() {
		addGroup("Resource/img/bullet/fire.png", 4, 4, 1, 32, 32, FIRE);
	};
	~ShotData() = default;
	std::vector<int> _imgs;
public:

	static ShotData* Instance() {
		static ShotData inst;
		return &inst;
	};

	int FIRE[4];

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
		case(DS_FIRE_RED):
			if (Score::Instance()->GetScore(Gametime) % 32 >= 0 && Score::Instance()->GetScore(Gametime) % 32 < 8)
				return _imgs[0];
			if (Score::Instance()->GetScore(Gametime) % 32 >= 8 && Score::Instance()->GetScore(Gametime) % 32 < 16)
				return _imgs[1];
			if (Score::Instance()->GetScore(Gametime) % 32 >= 16 && Score::Instance()->GetScore(Gametime) % 32 < 24)
				return _imgs[2];
			if (Score::Instance()->GetScore(Gametime) % 32 >= 24 && Score::Instance()->GetScore(Gametime) % 32 < 32)
				return _imgs[3];
		}
		return 0;
	};
};

class Bullet : public Sprite
{
public:
	Bullet(int x, int y, float speed, int angle, int accel, int maxspeed, ShotDatas id, int special = 0) {
		_x = 352 + Score::Instance()->GetScore(CameraX) + x;
		_y = Score::Instance()->GetScore(CameraY) + y;
		_speed = speed;
		_angle = angle + Define::PI / 2;
		_id = ShotData::Instance()->Get(id);
		_special = special;
	}
	~Bullet() = default;

	virtual bool update() override;
	virtual void draw() const override;
	
	//void CreateShotA1(int x,int y,float speed,int angle,int id,int delay);
	//void CreateShotA2(int x, int y, float speed, int angle, int accel,int maxspeed, int delay);
private:
	int _x, _y, _id, _special;
	float _angle, _speed;
};

