#pragma once
#include <vector>
#include <DxLib.h>
#include "Score.h"

enum Loads {
	Frame,
	bg,
	PlayerImg,
	Compass_RED,
	Compass_GREEN,
	Compass_BLUE,
};

enum LoadSEs {
	PUpAvailable,
	Charge00,
	Charge01,
	Miss,
	PShot,
	Shot1,
};

class StartLoad
{
private:
	StartLoad();
	~StartLoad() = default;
	int _frame;
public:

	static StartLoad* Instance() {
		static StartLoad inst;
		return &inst;
	};

	void load() {}//コンストラクタ起動用。SceneManagerで起動させるようにする。

	const int Get(Loads data);
};


class GameLoad
{
private:
	GameLoad();
	~GameLoad() = default;
	std::vector<int> _imgs;
	int panime = 0;
	int pallanime = 1;
public:

	static GameLoad* Instance() {
		static GameLoad inst;
		return &inst;
	};

	void load() {  }//コンストラクタ起動用。SceneManagerで起動させるようにする。
	void release();
	void addSingle(const char* fileName);
	void addGroup(const char* fileName, int n, int xn, int yn, int w, int h, int* buf);

	const int Get(Loads data);
	int _IMAGES[6], _COMPASSIMAGES[3];
};

class GameLoadSE
{
private:
	GameLoadSE();
	~GameLoadSE() = default;
	std::vector<int> _ses;

public:

	static GameLoadSE* Instance() {
		static GameLoadSE inst;
		return &inst;
	};

	void load() {  }//コンストラクタ起動用。SceneManagerで起動させるようにする。
	void release();
	void addSingle(const char* fileName);

	const int Get(LoadSEs data);
};


class St1Load
{
private:
	St1Load();
	~St1Load() = default;
	std::vector<int> _imgs;
public:

	static St1Load* Instance() {
		static St1Load inst;
		return &inst;
	};

	void load() {  }//コンストラクタ起動用。SceneManagerで起動させるようにする。
	void release();
	void addSingle(const char* fileName);
	void addGroup(const char* fileName, int n, int xn, int yn, int w, int h, int* buf);
	
	const int Get(Loads data);
};