#include "Bullet.h"



bool Bullet::update()
{

    if (_delay <= Score::Instance()->GetScore(Gametime)) {
        _age++;
        _x += cos(_angle) * _maxspeed;
        _y += sin(_angle) * _maxspeed;

        if (CheckHitKey(KEY_INPUT_C) && DKDistance(Score::Instance()->GetScore(PlayerX), Score::Instance()->GetScore(PlayerY), _x, _y) < 30 * Score::Instance()->GetScore(NowSlotLv)) {
            if (Score::Instance()->GetScore(NowSlotColor) == _systemcolor) {
                _exist = false;
            }
        }

        if (_pattern == 1) {
            _angle = (_angle * 180 / Define::PI + _custom) * Define::PI / 180;
            _showangle = (_angle * 180 / Define::PI + 90 + _custom) * Define::PI / 180;

            if (_age > 715) {
                // ParticleManager::Instance()->Particle_Create(_x, _y, YELLOW);
                _exist = false;

            }

        }



    }
    return true;
}

void Bullet::draw() const
{
    if (_delay <= Score::Instance()->GetScore(Gametime) && _exist == true) {
        if (_id > 18) {
            SetDrawBlendMode(DX_BLENDMODE_ADD, 192);
            DrawRotaGraphF(352 + Score::Instance()->GetScore(CameraX) + _x, _y, 1, _showangle, ShotData::Instance()->Get(_id), true);
        }

        DrawRotaGraphF(352 + Score::Instance()->GetScore(CameraX) + _x, _y, 1, _showangle, ShotData::Instance()->Get(_id), true);

        if (_id > 18)
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }


}
