#pragma once
#include <vector>
#include <DxLib.h>

enum Loads {
	Frame,
	bg,
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