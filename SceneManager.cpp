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
@brief �V�[���ύX(�e�V�[������R�[���o�b�N�����)
@param scene �ύX����V�[����enum
@param parameter �O�̃V�[����������p���p�����[�^
@param stackClear ���݂̃V�[���̃X�^�b�N���N���A���邩
*/
void SceneManager::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear)
{
}