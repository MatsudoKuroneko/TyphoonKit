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

	void load() {}//�R���X�g���N�^�N���p�BSceneManager�ŋN��������悤�ɂ���B

	const int Get(StartLoads data);
};