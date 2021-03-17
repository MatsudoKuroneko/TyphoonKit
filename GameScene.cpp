#include "GameScene.h"
#include "Sprite.h"
#include <DxLib.h>
#include "Score.h"
#include "StartLoad.h"

bool loaded;
static int frame,firebullet;


const char* GameScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter):BaseScene(impl, parameter)
{
	_player = std::make_shared<Player>();
	_level = parameter.get(ParameterTagLevel);
	Score::Instance()->ResetScore();
}

void GameScene::update()

{
	_player->update();
	Score::Instance()->AddScore(Gametime, 1);
}


void GameScene::draw() const
{
	DrawGraph(0, 0, StartLoad::Instance()->Get(Frame), FALSE);
	_player->draw();
	DrawFormatString(100, 200, GetColor(255, 255, 255), "%d", Score::Instance()->GetScore(Gametime));
}