#include "BulletManager.h"

void BulletManager::update()
{
	for (auto& e : _bullets) {
		e->update();
	}
	return;
}

void BulletManager::draw() const
{
	for (auto& e : _bullets) {
		e->draw();
	}
	return;
}

int BulletManager::CreateShotA1(int x, int y, float speed, int angle, ShotDatas id, int delay)
{
	_bullets.emplace_back(std::make_shared<Bullet>(x, y, 0, angle, 0, speed, id));
	return 0;
}
