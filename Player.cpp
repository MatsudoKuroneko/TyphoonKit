
#include "Player.h"
#include <DxLib.h>
#include <iostream>
#include "Score.h"
#include "GameScene.h"

Player::Player()
{
	//Player�����ݒ�
	x = 720;
	y = 600;
	anime = 0;
	allanime = 1;

	_img = LoadDivGraph("Resource/img/spdot/player_reimu.png", 6, 2, 3, 48, 48, _IMAGES);
	std::cout << "���@�摜�ǂݍ��݊���";
	
}

bool Player::update()
{
	if (Score::Instance()->GetScore(Gametime) % 4 == 0) {
		if (allanime <= anime) {
			anime = 0;
		}
		else {
			anime++;
		}
	}

	return true;
}

void Player::draw() const
{
	DrawRotaGraphF(x, y, 1, 0, _IMAGES[anime], true);
}
