#include "GameScene.h"
#include <DxLib.h>

const char* GameScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter):BaseScene(impl, parameter)
{
	_level = parameter.get(ParameterTagLevel);
}

void GameScene::update()

{
	DrawString(100, 200, "Moving on TitleScene", GetColor(255, 255, 255));
}


void GameScene::draw() const
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "Scene 2");
}