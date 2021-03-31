#include "Particle.h"

bool Particle::update()
{
	if(_type == 0){
		_x -= (GetRand(8) - 8) / 10.0;
		_y -= (GetRand(8) + 3) / 10.0 + 0.5;
		_imgsize -= 0.04 + (GetRand(2) / 100);
	}
	return true;
}

void Particle::draw() const
{
	SetDrawBlendMode(DX_BLENDMODE_ADD, 192);
	if (_imgsize > 0) {
		DrawRotaGraphF(_x, _y, _imgsize, 0, ParticleBaseImage::Instance()->Get(_color), true);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
