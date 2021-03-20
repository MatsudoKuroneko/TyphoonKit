#include "Bullet.h"

bool Bullet::update()
{
    if (_delay <= Score::Instance()->GetScore(Gametime)) {
        _x += cos(_angle) * _maxspeed;
        _y += sin(_angle) * _maxspeed;
        return true;
    }
}

void Bullet::draw() const
{
    if (_delay <= Score::Instance()->GetScore(Gametime)) {
        if (_id > 18)
            SetDrawBlendMode(DX_BLENDMODE_ADD, 192);

        DrawRotaGraphF(_x, _y, 1, _showangle, ShotData::Instance()->Get(_id), true);

        if (_id > 18)
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

}
