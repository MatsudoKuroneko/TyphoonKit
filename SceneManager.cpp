#include "SceneManager.h"
#include "TitleScene.h"

using namespace std;

SceneManager::SceneManager()
{
    Parameter parameter;
    _sceneStack.push(make_shared<TitleScene>(this, parameter));
}

bool SceneManager::loop() const
{
    _sceneStack.top()->update();
    _sceneStack.top()->draw();
    return true;
}


/*!
@brief シーン変更(各シーンからコールバックされる)
@param scene 変更するシーンのenum
@param parameter 前のシーンから引き継ぐパラメータ
@param stackClear 現在のシーンのスタックをクリアするか
*/
void SceneManager::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear)
{
}