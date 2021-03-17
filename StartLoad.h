#pragma once

enum StartLoads {
	Frame,
};

class StartLoad
{
private:
	int _frame;
public:

	StartLoad();
	~StartLoad() = default;

	static StartLoad* Instance() {
		static StartLoad inst;
		return &inst;
	};

	void load() {}//コンストラクタ起動用。SceneManagerで起動させるようにする。

	const int Get(StartLoads data);
};


