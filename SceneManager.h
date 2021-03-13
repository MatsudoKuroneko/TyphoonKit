#pragma once
#include <stack> //��ɂ���񂶂�������Ă����
#include <memory>
#include "BaseScene.h"
#include "IOnSceneChangedListener.h"

class SceneManager final : public IOnSceneChangedListener
{
public:
	SceneManager();
	~SceneManager() = default;
	bool loop() const;
	void onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear) override; // Scene�J�ڌ��o�ʒm

private:
	std::stack<std::shared_ptr<BaseScene>> _sceneStack; //�V�[���̃X�^�b�N
};