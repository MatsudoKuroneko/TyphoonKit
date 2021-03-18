#pragma once

enum StartLoads {
	Frame,
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

	const int Get(StartLoads data);
};