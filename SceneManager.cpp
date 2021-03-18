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
@brief �V�[���ύX
@param scene �ύX����V�[����enum
@param parameter �O�̃V�[����������p���p�����[�^
@param stackClear ���݂̃V�[���̃X�^�b�N���N���A���邩(�X�g�[���[or���j���[&�v���N�e�B�X)
*/
void SceneManager::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear)
{
    if (stackClear) {//�X�g�[���[
        while (!_sceneStack.empty()) {//�X�^�b�N��S���|�b�v����(�X�^�b�N����ɂ���)
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
        //��O����
        /*while (!_sceneStack.empty()) {//�X�^�b�N��S���|�b�v����(�X�^�b�N����ɂ���)
            _sceneStack.pop();
        }
        _sceneStack.push(make_shared<TitleScene>(this, parameter));*/
        break;
    }
}

