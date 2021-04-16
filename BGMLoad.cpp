#include "BGMLoad.h"

void BGMLoad::LoadBGM(int stage)
{
    if (stage == 1) {
        _road = LoadSoundMem("Resource/bgm/th18_02.mp3");
        _boss = LoadSoundMem("Resource/bgm/th18_03.mp3");
    }

    return;
}

int BGMLoad::GetRoad()
{
    return _road;
}


int BGMLoad::GetBoss()
{
    return _boss;
}
