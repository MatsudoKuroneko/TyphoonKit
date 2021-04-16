#include "GameScene.h"
#include "Sprite.h"
#include <DxLib.h>
#include "Score.h"
#include "BulletManager.h"
#include "ParticleManager.h"
#include "BulletBreakManager.h"
#include "BGMLoad.h"


bool loaded;
static int frame, stage,firebullet,threedsize;
VECTOR CameraPos;
VERTEX3D Vertex[6];


const char* GameScene::ParameterTagLevel = "ParameterTagLevel";//パラメータのタグ「レベル」

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter):BaseScene(impl, parameter)
{
	
	threedsize = 0;
	_player = std::make_shared<Player>();
	_level = parameter.get(ParameterTagLevel);
	Score::Instance()->ResetScore();
	Score::Instance()->ConfirmScore(Stage,1);
	GameLoad::Instance()->load();
	GameLoadSE::Instance()->load();
	St1Load::Instance()->load();
	BulletManager::Instance()->load();
	EnemyManager::Instance()->load();
	ParticleManager::Instance()->load();
	BulletBreakManager::Instance()->load();
	BGMLoad::Instance()->load();
	
}

void GameScene::update()

{

	gametime = Score::Instance()->GetScore(Gametime);
	stage = Score::Instance()->GetScore(Stage);

	_player->update();

	BulletManager::Instance()->update();
	EnemyManager::Instance()->update();
	ParticleManager::Instance()->update();
	BulletBreakManager::Instance()->update();


	Score::Instance()->AddScore(Gametime, 1);

	if(stage == 1){
		if (gametime == 0) {
			BGMLoad::Instance()->LoadBGM(1);
			PlaySoundMem(BGMLoad::Instance()->GetRoad(), DX_PLAYTYPE_LOOP);
		}

	if(gametime == 100){
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 1, -20, 0, 100, REIKON_RED,   0, 0, 90 - 30);
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 3, -10, 0, 100, REIKON_ORANGE,0, 50, 90 + 30);
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 5, 0, 0, 100, REIKON_YELLOW,  0, 100, 90);
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 7, 0, 0, 100, REIKON_GREEN,   0, 100, 90);
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 9, -10, 0, 100, REIKON_SKY,   0, 50, 90 - 30);
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 11, -20, 0, 100, REIKON_BLUE, 0, 0, 90 + 30);
	}

	if (gametime == 600) {
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 1, -20, 0, 100, REIKON_RED, 0, 100, 90 - 30);
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 3, -10, 0, 100, REIKON_ORANGE, 0, 50, 90 + 30);
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 5, 0, 0, 100, REIKON_YELLOW, 0, 0, 90);
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 7, 0, 0, 100, REIKON_GREEN, 0, 0, 90);
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 9, -10, 0, 100, REIKON_SKY, 0, 50, 90 - 30);
		EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 12 * 11, -20, 0, 100, REIKON_BLUE, 0, 100, 90 + 30);
	}

	}

	if (stage == 7) {
		if (gametime == 50) {
			EnemyManager::Instance()->Enemy_Create(Define::AREA_X / 2, 200, 0, 100, Boss_StEX, 1, 100, 0);
		}
	}
	
}


void GameScene::draw() const
{

	//DrawBillboard3D(VGet(320.0f, 240.0f, 0), 0.5f, 0.5f, 1200, 0.0f, St1Load::Instance()->Get(bg), TRUE);
	_player->draw();
	DrawGraph(0, 0, GameLoad::Instance()->Get(bg), FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	EnemyManager::Instance()->draw();
	ParticleManager::Instance()->draw();
	BulletManager::Instance()->draw();
	BulletBreakManager::Instance()->draw();
	DrawFormatString(100, 200, GetColor(255, 255, 255), "%d", gametime);
	DrawFormatString(100, 244, GetColor(255, 255, 255), "%d", threedsize);
	DrawGraph(0, 0, StartLoad::Instance()->Get(Frame), TRUE);

}

int GameScene::GetImage(Loads data) const {
	return (StartLoad::Instance()->Get(data));
}
