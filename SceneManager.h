#pragma once
#include <stack> //上にじゃんじゃん乗っけてくやつ
#include <memory>
#include "BaseScene.h"
#include "IOnSceneChangedListener.h"

class SceneManager final : public IOnSceneChangedListener
{
public:
	SceneManager();
	~SceneManager() = default;
	bool loop() const;
	void onSceneChanged(const eScene scene, const Parameter & parameter, const bool stackClear) override; // Scene遷移検出通知

private:
	std::stack<std::shared_ptr<BaseScene>> _sceneStack; //シーンのスタック
};