#pragma once

#include "Sprite.h"
#include "Bullet.h"
#include "BulletBreakManager.h"
#include <vector>
#include <memory>

class BulletManager
{
private:
	BulletManager() {
		
	};
	~BulletManager() = default;

	std::vector<std::shared_ptr<Bullet>> _bullets;
public:
	static BulletManager* Instance() {
		static BulletManager inst;
		return &inst;
	};

	void load() {  }//コンストラクタ起動用。SceneManagerで起動させるようにする。

	void update();
	void draw() const;
	void CreateShotA1(int x, int y, float speed, float angle, ShotDatas id, int delay,bool rad = false, int pattern = 0, float custom = 0);
	int CreateShotA2(int x, int y, float speed, float angle, int accel, int maxspeed, ShotDatas id, int delay);
};