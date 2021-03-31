#include "TitleScene.h"
#include <DxLib.h>
#include "GameScene.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) : BaseScene(impl, parameter)
{
}

void TitleScene::update()
{
    DrawString(100, 200, "Moving on TitleScene", GetColor(255, 255, 255));
    if (CheckHitKey(KEY_INPUT_E)) {
        Parameter parameter;
        parameter.set(GameScene::ParameterTagLevel, 0);
        _implSceneChanged->onSceneChanged(eScene::Game, parameter, true);
        return;
    }
    if (CheckHitKey(KEY_INPUT_N)) {
        Parameter parameter;
        parameter.set(GameScene::ParameterTagLevel, 1);
        _implSceneChanged->onSceneChanged(eScene::Game, parameter, true);
        return;
    }
}

void TitleScene::draw() const
{

}
