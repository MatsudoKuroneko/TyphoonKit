#include "BulletBreakManager.h"

void BulletBreakManager::update()
{


	auto it = _bbs.begin();
	while (it != _bbs.end())
	{
		(*it)->update();


		if ((*it)->_i == 10)
		{
			it = _bbs.erase(it);
		}
		else
		{
			it++;
		}

	}


	return;
}

void BulletBreakManager::draw() const
{
	for (auto& e : _bbs) {
		e->draw();
	}
	return;
}

void BulletBreakManager::Create_BB(int x, int y, BBColors color)
{
	_bbs.emplace_back(std::make_shared<BulletBreak>(x, y, color));

}