#include "Bullet.h"

bool Bullet::update()
{
    _x += cos(_angle) * 1;
    _y += sin(_angle) * 1;
    return true;
}

void Bullet::draw() const
{
    DrawRotaGraph(_x, _y, 1.5, (_angle + 90), ShotData::Instance()->Get(_id), true);
}
