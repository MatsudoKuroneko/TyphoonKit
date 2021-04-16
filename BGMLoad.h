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

	void load() {}//�R���X�g���N�^�N���p�BSceneManager�ŋN��������悤�ɂ���B

	void LoadBGM(int stage);
	int GetRoad();
	int GetBoss();
};