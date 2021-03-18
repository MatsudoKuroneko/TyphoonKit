
#include "Player.h"
#include <DxLib.h>
#include <iostream>
#include "Score.h"
#include "GameScene.h"

Player::Player()
{
	//Player‰ŠúÝ’è
	x = 576/2;
	y = 672/4 * 3;
	anime = 0;
	allanime = 1;

	_img = LoadDivGraph("Resource/img/spdot/player_reimu.png", 6, 2, 3, 48, 48, _IMAGES);
	_compassimg = LoadDivGraph("Resource/img/spdot/compass.png", 3, 3, 1, 300, 300, _COMPASSIMAGES);
	printfDx("Player: _imgLoaded.\n");
	
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
	SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
	DrawRotaGraphF(352 + Score::Instance()->GetScore(CameraX) + x, Score::Instance()->GetScore(CameraY) + y, 0.75, 0, _COMPASSIMAGES[1], true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawRotaGraphF(352 + Score::Instance()->GetScore(CameraX) + x, Score::Instance()->GetScore(CameraY) + y, 1.5, 0, _IMAGES[anime], true);
}
