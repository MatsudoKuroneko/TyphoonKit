#pragma once

#include "Sprite.h"
#include "Enemy.h"
#include <vector>
#include <memory>

class EnemyManager
{
private:
	EnemyManager() {

	};
	~EnemyManager() = default;

	std::vector<std::shared_ptr<Enemy>> _enemies;
public:
	static EnemyManager* Instance() {
		static EnemyManager inst;
		return &inst;
	};

	void load() {  }//�R���X�g���N�^�N���p�BSceneManager�ŋN��������悤�ɂ���B

	void update();
	void draw() const;
	void Enemy_Create(int x, int y, float speed, int hp, EnemyDatas image, int pattern, int delay, int custom);
};