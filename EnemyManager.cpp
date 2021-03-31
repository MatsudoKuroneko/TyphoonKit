#include "EnemyManager.h"

void EnemyManager::update()
{
	for (auto& e : _enemies) {
		e->update();
	}
	return;
}

void EnemyManager::draw() const
{
	for (auto& e : _enemies) {
		e->draw();
	}
	return;
}

void EnemyManager::Enemy_Create(int x, int y, float speed, int hp, EnemyDatas image, int pattern, int delay, int custom)
{
	_enemies.emplace_back(std::make_shared<Enemy>( x,  y,   speed,  hp,   image,  pattern, delay,custom));
}
