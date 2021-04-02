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

	void load() {  }//コンストラクタ起動用。SceneManagerで起動させるようにする。

	void update();
	void draw() const;
	void Create_BB(int x, int y, BBColors color);
};