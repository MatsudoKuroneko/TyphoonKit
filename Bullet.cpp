#include "Bullet.h"

bool Bullet::update()
{
    _x += cos(_angle) * _speed;
    _y += sin(_angle) * _speed;
    return true;
}

void Bullet::draw() const
{
    DrawRotaGraph(_x, _y, 1, _angle, _id, true);
}
