#include "Enemy.h"

bool Enemy::update()
{

	if (_delay <= Score::Instance()->GetScore(Gametime)) {
		_age++;

		if (_pattern == 0) {
			_rotation++;
			if (_age < 300) {
				if (_my > 1) {
					_my -= _my / 8;
					_y += _my;
				}
				else {
					if (_age % 5 == 0 && _bulletcount <= 3) {
						BulletManager::Instance()->CreateShotA1(_x, _y, 4, DKHorming(Score::Instance()->GetScore(PlayerX), Score::Instance()->GetScore(PlayerY), _x, _y), DS_FIRE_RED, 0, true);
						_bulletcount++;
					}

					if (_bulletcount == 4) {
						BulletManager::Instance()->CreateShotA1(_x, _y, 5, _custom, DS_FIRE_RED, 0);
						BulletManager::Instance()->CreateShotA1(_x, _y, 5, _custom, DS_FIRE_RED, 10);
						BulletManager::Instance()->CreateShotA1(_x, _y, 5, _custom, DS_FIRE_RED, 20);

						BulletManager::Instance()->CreateShotA1(_x, _y, 5, 180 + _custom, DS_FIRE_RED, 0);
						BulletManager::Instance()->CreateShotA1(_x, _y, 5, 180 + _custom, DS_FIRE_RED, 10);
						BulletManager::Instance()->CreateShotA1(_x, _y, 5, 180 + _custom, DS_FIRE_RED, 20);
						_bulletcount++;
					}
				}
			}
			else {
				_y += 5;
			}
		}

		if (_image < 9) {


			if (_age % 5 == 0) {
				if (_imgsize > 1.25 && _imgsize < 1.75)
					_imgsize += (GetRand(60) - 30) / 100;
			}
			else {
				if (GetRand(1) == 0) {
					_imgsize = 1.3;
				}
				else {
					_imgsize = 1.7;
				}
			}

		}

		if (_image == 9) {
			_imgsize = 2;


			if (_age % 100 >= 0 && _age % 100 <= 40) {
					_showyd += 0.2;
			}
			if (_age % 100 >= 50 && _age % 100 <= 90) {
				_showyd -= 0.2;
			}


			if (_age % 50 == 0 && _age <= 250) {

				for (int i = 0; i < 360; i += 45) {
					BulletManager::Instance()->CreateShotA1(_x, _y, 5.5, i, DS_FIRE_RED, 100, false, 1, -1);
				}
			}

			if (_age % 20 == 0 && _age <= 100) {
				for (int i = 0; i < 360; i += 20) {
					BulletManager::Instance()->CreateShotA1(_x, _y, 4.1, i, DS_FIRE_RED, 100, false, 1, 1);
				}
			}

			if (_age % 20 == 0 && _age <= 400 && _age >= 300) {
				for (int i = 0; i < 360; i += 20) {
					BulletManager::Instance()->CreateShotA1(_x, _y, 3.9, i, DS_FIRE_RED, 100, false, 1, -1);
				}
			}



		}
		_showx = 352 + Score::Instance()->GetScore(CameraX) + _x;
		return true;
	}
}

void Enemy::draw() const
{
	if (_delay <= Score::Instance()->GetScore(Gametime)) {


		if (_image < 9) {
			//DrawFormatString(_showx, _y - 10, GetColor(255, 255, 255), "x %d", _age);

			SetDrawBlendMode(DX_BLENDMODE_ADD, 64);

			if (_image == REIKON_RED) {
				DrawRotaGraph(_showx, _y + 5, 0.25, (_rotation)*Define::PI / 180, GameLoad::Instance()->Get(Compass_RED), true);
			}
			if (_image == REIKON_ORANGE) {
				DrawRotaGraph(_showx, _y + 5, 0.25, (_rotation)*Define::PI / 180, GameLoad::Instance()->Get(Compass_RED), true);
			}
			if (_image == REIKON_YELLOW) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, YELLOW);
			}
			if (_image == REIKON_GREEN) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, GREEN);
			}
			if (_image == REIKON_SKY) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, SKY);
			}
			if (_image == REIKON_BLUE) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, BLUE);
			}
			if (_image == REIKON_PURPLE) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, PURPLE);
			}
			if (_image == REIKON_WHITE) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, WHITE);
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

			if (_image == REIKON_RED) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, RED);
				DrawRotaGraph(_showx, _y + 5, 0.25, (_rotation)*Define::PI / 180, GameLoad::Instance()->Get(Compass_RED), true);
			}
			if (_image == REIKON_ORANGE) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, ORANGE);
				DrawRotaGraph(_showx, _y + 5, 0.25, (_rotation)*Define::PI / 180, GameLoad::Instance()->Get(Compass_RED), true);
			}
			if (_image == REIKON_YELLOW) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, YELLOW);
				DrawRotaGraph(_showx, _y + 5, 0.25, (_rotation)*Define::PI / 180, GameLoad::Instance()->Get(Compass_GREEN), true);
			}
			if (_image == REIKON_GREEN) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, GREEN);
				DrawRotaGraph(_showx, _y + 5, 0.25, (_rotation)*Define::PI / 180, GameLoad::Instance()->Get(Compass_GREEN), true);
			}
			if (_image == REIKON_SKY) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, SKY);
				DrawRotaGraph(_showx, _y + 5, 0.25, (_rotation)*Define::PI / 180, GameLoad::Instance()->Get(Compass_BLUE), true);
			}
			if (_image == REIKON_BLUE) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, BLUE);
				DrawRotaGraph(_showx, _y + 5, 0.25, (_rotation)*Define::PI / 180, GameLoad::Instance()->Get(Compass_BLUE), true);
			}
			if (_image == REIKON_PURPLE) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, PURPLE);
			}
			if (_image == REIKON_WHITE) {
				if (_age % 4 == 0)ParticleManager::Instance()->Particle_Create(_showx, _y, WHITE);
			}

			DrawRotaGraph(_showx, _y, _imgsize, 0, EnemyImage::Instance()->Get(_image), true);
		}
		else {

			DrawRotaGraphF(_showx, _y + _showyd, _imgsize, 0, EnemyImage::Instance()->Get(_image), true);
		}


	}

}