#include "GameScene.h"
#include "Sprite.h"
#include <DxLib.h>
#include "Score.h"


bool loaded;
static int frame,firebullet,threedsize;
VECTOR CameraPos;
VERTEX3D Vertex[6];


const char* GameScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter):BaseScene(impl, parameter)
{
	threedsize = 0;
	_player = std::make_shared<Player>();
	_level = parameter.get(ParameterTagLevel);
	Score::Instance()->ResetScore();
	St1Load::Instance()->load();
}

void GameScene::update()

{

	_player->update();
	Score::Instance()->AddScore(Gametime, 1);
}


void GameScene::draw() const
{

	DrawBillboard3D(VGet(320.0f, 240.0f, 0), 0.5f, 0.5f, 1200, 0.0f, St1Load::Instance()->Get(bg), TRUE);


	_player->draw();
	DrawFormatString(100, 200, GetColor(255, 255, 255), "%d", Score::Instance()->GetScore(Gametime));
	DrawFormatString(100, 244, GetColor(255, 255, 255), "%d", threedsize);
	DrawGraph(0, 0, StartLoad::Instance()->Get(Frame), TRUE);
}

int GameScene::GetImage(Loads data) const {
	return (StartLoad::Instance()->Get(data));
}