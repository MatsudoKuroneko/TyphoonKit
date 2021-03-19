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
			
			if ((Score::Instance()->GetScore(Gametime) % 14 >= 0 && Score::Instance()->GetScore(Gametime) % 14 < 2)|| (Score::Instance()->GetScore(Gametime) % 14 >= 12 && Score::Instance()->GetScore(Gametime) % 14 < 14)) {
				return _imgs[0];
			}
			if ((Score::Instance()->GetScore(Gametime) % 14 >=2 && Score::Instance()->GetScore(Gametime) % 14 < 4) || (Score::Instance()->GetScore(Gametime) % 14 >= 10 && Score::Instance()->GetScore(Gametime) % 14 < 12))
				return _imgs[1];
			if ((Score::Instance()->GetScore(Gametime) % 14 >= 4 && Score::Instance()->GetScore(Gametime) % 14 < 6) || (Score::Instance()->GetScore(Gametime) % 14 >= 8 && Score::Instance()->GetScore(Gametime) % 14 < 10))
				return _imgs[2];
			if (Score::Instance()->GetScore(Gametime) % 14 >= 6 && Score::Instance()->GetScore(Gametime) % 14 < 8)
				return _imgs[3];
			
		}
		return 0;
	};
};

class Bullet : public Sprite
{
public:
	Bullet(int x, int y, float speed, int angle, float accel, int maxspeed, ShotDatas id, int special = 0) {
		_x = 352 + Score::Instance()->GetScore(CameraX) + x;
		_y = Score::Instance()->GetScore(CameraY) + y;
		_speed = accel;
		_angle = angle * Define::PI / 180;
		_id = id;
		_special = special;
	}
	~Bullet() = default;

	virtual bool update() override;
	virtual void draw() const override;

private:
	ShotDatas _id;
	int _special;
	float _x, _y, _angle, _speed;
};

