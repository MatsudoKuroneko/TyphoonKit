#pragma once

#include "Sprite.h"
#include "BulletBreak.h"
#include <vector>
#include <memory>

class BulletBreakManager
{
private:
	BulletBreakManager() {

	};
	~BulletBreakManager() = default;

	std::vector<std::shared_ptr<BulletBreak>> _bbs;
public:
	static BulletBreakManager* Instance() {
		static BulletBreakManager inst;
		return &inst;
	};

	void load() {  }//�R���X�g���N�^�N���p�BSceneManager�ŋN��������悤�ɂ���B

	void update();
	void draw() const;
	void Create_BB(int x, int y, BBColors color);
};