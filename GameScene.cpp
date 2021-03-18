#include "GameScene.h"
#include "Sprite.h"
#include <DxLib.h>
#include "Score.h"
#include "BulletManager.h"


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
	BulletManager::Instance()->load();
}

void GameScene::update()

{

	gametime = Score::Instance()->GetScore(Gametime);

	_player->update();
	BulletManager::Instance()->update();
	Score::Instance()->AddScore(Gametime, 1);
	if(gametime == 10){
	BulletManager::Instance()->CreateShotA1(576 / 2, 672 / 4 * 3, 2.5, 0, DS_FIRE_RED, 0);
	BulletManager::Instance()->CreateShotA1(576 / 2, 672 / 4 * 3, 2.5, 10, DS_FIRE_RED, 0);
	BulletManager::Instance()->CreateShotA1(576 / 2, 672 / 4 * 3, 2.5, 20, DS_FIRE_RED, 0);
	BulletManager::Instance()->CreateShotA1(576 / 2, 672 / 4 * 3, 2.5, 30, DS_FIRE_RED, 0);
	BulletManager::Instance()->CreateShotA1(576 / 2, 672 / 4 * 3, 2.5, 40, DS_FIRE_RED, 0);
	BulletManager::Instance()->CreateShotA1(576 / 2, 672 / 4 * 3, 2.5, 50, DS_FIRE_RED, 0);
	BulletManager::Instance()->CreateShotA1(576 / 2, 672 / 4 * 3, 2.5, 60, DS_FIRE_RED, 0);
	}
	
}


void GameScene::draw() const
{

	DrawBillboard3D(VGet(320.0f, 240.0f, 0), 0.5f, 0.5f, 1200, 0.0f, St1Load::Instance()->Get(bg), TRUE);

	BulletManager::Instance()->draw();
	_player->draw();
	DrawFormatString(100, 200, GetColor(255, 255, 255), "%d", gametime);
	DrawFormatString(100, 244, GetColor(255, 255, 255), "%d", threedsize);
	DrawGraph(0, 0, StartLoad::Instance()->Get(Frame), TRUE);
}

int GameScene::GetImage(Loads data) const {
	return (StartLoad::Instance()->Get(data));
}

void GameScene::CreateShotA1(int x, int y, float speed, int angle, ShotDatas id, int delay) {
	CreateShotA1(x, y, speed, angle, id, delay);
}