#include "BulletBreak.h"

bool BulletBreak::update() {
	if (Score::Instance()->GetScore(Gametime) % 2 == 0)
	{
		_i++;
	}
	return true;
}

void BulletBreak::draw() const
{
	SetDrawBlendMode(DX_BLENDMODE_ADD, 128);

	if (_i < 9)
	{
		if (_i <= 5)
			DrawRotaGraph(352 + Score::Instance()->GetScore(CameraX) +_x, _y, 1, 0, BulletBreakImage::Instance()->Get(_color,_i), true);
		if (_i == 6)
			DrawRotaGraph(352 + Score::Instance()->GetScore(CameraX) + _x, _y, 0.8, 0, BulletBreakImage::Instance()->Get(_color, 5), true);
		if (_i == 7)
			DrawRotaGraph(352 + Score::Instance()->GetScore(CameraX) + _x, _y, 0.6, 0, BulletBreakImage::Instance()->Get(_color, 5), true);
		if (_i == 8 || _i == 9)
			DrawRotaGraph(352 + Score::Instance()->GetScore(CameraX) + _x, _y, 0.4, 0, BulletBreakImage::Instance()->Get(_color, 5), true);
	};

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}