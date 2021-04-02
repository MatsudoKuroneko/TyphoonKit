#pragma once
#include "Sprite.h"
#include "Score.h"
#include <DXLib.h>
#include <vector>

static enum BBColors {
	BB_RED,
	BB_PINK,
	BB_YELLOW,
	BB_ORANGE,
	BB_GREEN1,
	BB_GREEN2,
	BB_SKY,
	BB_BLUE,
	BB_PURPLE,
	BB_WHITE,
};

class BulletBreakImage
{
private:
	BulletBreakImage() {
		addGroup("Resource/img/particle/bulletbreak.png", 80, 8, 10, 64, 64, BR);
	};
	~BulletBreakImage() = default;
	std::vector<int> _imgs;
	int BR[80];
public:

	static BulletBreakImage* Instance() {
		static BulletBreakImage inst;
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

	const int Get(BBColors data,int i) {

		return _imgs[i + 8 * data];

	};
};

class BulletBreak : public Sprite
{
public:
	BulletBreak(float x, float y, BBColors color) {
		_x = x;
		_y = y;
		_i = 0;
		_color = color;
	}
	~BulletBreak() = default;

	virtual bool update() override;
	virtual void draw() const override;
	int _i;

private:
	BBColors _color;
	int _x, _y;
};