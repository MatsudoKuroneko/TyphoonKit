#pragma once
#include <DxLib.h>

/*
enum BGMLoads {
	Frame,
	bg,
	PlayerImg,
	Compass_RED,
	Compass_GREEN,
	Compass_BLUE,
};*/

class BGMLoad
{
private:
	BGMLoad() = default;
	~BGMLoad() = default;
	int _road, _boss = 0;
public:

	static BGMLoad* Instance() {
		static BGMLoad inst;
		return &inst;
	};

	void load() {}//コンストラクタ起動用。SceneManagerで起動させるようにする。

	void LoadBGM(int stage);
	int GetRoad();
	int GetBoss();
};