#include "TitleScene.h"
#include <DxLib.h>

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) : BaseScene(impl, parameter)
{
}

void TitleScene::update()
{
}

void TitleScene::draw()
{
    DrawString(100, 100, "TitleScene", GetColor(255, 255, 255));
}
