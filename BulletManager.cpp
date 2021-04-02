#include "BulletManager.h"

void BulletManager::update()
{


	auto it = _bullets.begin();
	while (it != _bullets.end())
	{
		(*it)->update();


		if ((*it)->_exist == false)
		{
			BulletBreakManager::Instance()->Create_BB((*it)->_x, (*it)->_y, BB_PURPLE);
			it = _bullets.erase(it);
		}
		else
		{
			it++;
		}

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

void BulletManager::CreateShotA1(int x, int y, float speed, float angle, ShotDatas id, int delay, bool rad,int pattern,float custom)
{
	_bullets.emplace_back(std::make_shared<Bullet>(x, y, 0, angle, 0, speed, id,delay,rad,pattern,custom));
}
