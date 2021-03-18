#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Load.h"

using namespace std;

SceneManager::SceneManager()
{
    Parameter parameter;
    onSceneChanged(eScene::Title, parameter, false);

    StartLoad::Instance()->load();
}

bool SceneManager::loop() const
{
    _sceneStack.top()->update();
    _sceneStack.top()->draw();
    return true;
}


/*!
@brief シーン変更
@param scene 変更するシーンのenum
@param parameter 前のシーンから引き継ぐパラメータ
@param stackClear 現在のシーンのスタックをクリアするか(ストーリーorメニュー&プラクティス)
*/
void SceneManager::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear)
{
    if (stackClear) {//ストーリー
        while (!_sceneStack.empty()) {//スタックを全部ポップする(スタックを空にする)
            _sceneStack.pop();
        }
    }

    switch (scene) {
    case Title:
        _sceneStack.push(make_shared<TitleScene>(this, parameter));
        break;
    case Game:
        _sceneStack.push(make_shared<GameScene>(this, parameter));
        break;
    default:
        //例外処理
        /*while (!_sceneStack.empty()) {//スタックを全部ポップする(スタックを空にする)
            _sceneStack.pop();
        }
        _sceneStack.push(make_shared<TitleScene>(this, parameter));*/
        break;
    }
}

