#include "GameScene.h"
#include "Sprite.h"
#include <DxLib.h>

bool loaded;
static int frame,firebullet;


const char* GameScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter):BaseScene(impl, parameter)
{
	_player = std::make_shared<Player>();
	_level = parameter.get(ParameterTagLevel);
}

void GameScene::update()

{
	_player->update();
	DrawString(100, 200, "Moving on TitleScene", GetColor(255, 255, 255));
}


void GameScene::draw() const
{
	_player->draw();
}