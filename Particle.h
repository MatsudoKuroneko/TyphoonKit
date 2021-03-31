#pragma once
#include "Sprite.h"
#include "Score.h"
#include <DXLib.h>
#include <vector>

static enum Colors {
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	SKY,
	BLUE,
	PURPLE,
	WHITE,
};

class ParticleBaseImage
{
private:
	ParticleBaseImage() {
		addGroup("Resource/img/particle/reikon.png", 9, 9, 1, 16, 16, N);
	};
	~ParticleBaseImage() = default;
	std::vector<int> _imgs;
	int N[9];
public:

	static ParticleBaseImage* Instance() {
		static ParticleBaseImage inst;
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

	const int Get(Colors data) {

			return _imgs[data];

	};
};

class Particle : public Sprite
{
public:
	Particle(float x, float y, Colors color,int type) {
		if (type == 0) {
			_x = Score::Instance()->GetScore(CameraX) + x + ((GetRand(800) - 800) / 100);
			_y = Score::Instance()->GetScore(CameraY) + y + ((GetRand(400) - 1000) / 100);
			_color = color;
			_accel = 0.001;
			_imgsize = 1.1 - (GetRand(100) / 100);
		}
		_type = type;
	}
	~Particle() = default;

	virtual bool update() override;
	virtual void draw() const override;

private:
	Colors _color;
	int _type;
	float _x, _y, _accel,_imgsize;
};