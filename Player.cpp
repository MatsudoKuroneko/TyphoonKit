
#include "Player.h"
#include <DxLib.h>
#include <iostream>
#include "Score.h"
#include "GameScene.h"
#include "Load.h"

Player::Player()
{

}

bool Player::update()
{
	x = Score::Instance()->GetScore(PlayerX);
	y = Score::Instance()->GetScore(PlayerY);

	if (CheckHitKey(KEY_INPUT_LEFT)) {
		if (CheckHitKey(KEY_INPUT_LSHIFT))
		{
			Score::Instance()->AddScore(PlayerX,-3.4);
		}
		else
		{
			Score::Instance()->AddScore(PlayerX, -9);
		}
	}

	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		if (CheckHitKey(KEY_INPUT_LSHIFT))
		{
			Score::Instance()->AddScore(PlayerX, 3.4);
		}
		else
		{
			Score::Instance()->AddScore(PlayerX, 9);
		}
	}

	if (CheckHitKey(KEY_INPUT_UP)) {
		if (CheckHitKey(KEY_INPUT_LSHIFT))
		{
			Score::Instance()->AddScore(PlayerY, -3.4);
		}
		else
		{
			Score::Instance()->AddScore(PlayerY, -9.25);
		}
	}

	if (CheckHitKey(KEY_INPUT_DOWN)) {
		if (CheckHitKey(KEY_INPUT_LSHIFT))
		{
			Score::Instance()->AddScore(PlayerY, 3.4);
		}
		else
		{
			Score::Instance()->AddScore(PlayerY, 8.75);
		}
	}
	return true;
}

void Player::draw() const
{
	DrawFormatString(352 + x, y - 120, GetColor(255, 255, 255), "Bouns Failed", Score::Instance()->GetScore(PlayerX));

	SetDrawBlendMode(DX_BLENDMODE_ADD, 128);
	DrawFormatString(352 + x, y + 60, GetColor(255, 255, 255), "%d", Score::Instance()->GetScore(PlayerX));
	DrawFormatString(352 + x, y + 72, GetColor(255, 255, 255), "%d", Score::Instance()->GetScore(PlayerY));
	DrawRotaGraphF(352 + Score::Instance()->GetScore(CameraX) + x, Score::Instance()->GetScore(CameraY) + y, 0.75, 0, GameLoad::Instance()->Get(Compass_RED), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawRotaGraphF(352 + Score::Instance()->GetScore(CameraX) + x, Score::Instance()->GetScore(CameraY) + y, 1.5, 0, GameLoad::Instance()->Get(PlayerImg), true);
}