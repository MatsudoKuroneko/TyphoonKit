#include "GameScene.h"
#include <DxLib.h>

bool loaded;
static int frame,firebullet;


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
	if (loaded == false) {
		frame = LoadGraph("Resource/img/frame.png");
		loaded = true;
	}else{

		DrawGraph(0, 0, frame, false);
		DrawFormatString(100, 100, GetColor(255, 255, 255), "Scene 2");

	}
}