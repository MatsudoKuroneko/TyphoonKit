#pragma once

#include "BaseScene.h"

class GameScene : public BaseScene
{
public:
	const static char* ParameterTagLevel;
	
	GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
	virtual ~GameScene() = default;

	void update() override;
	void draw() const override; // co

private:
	int _level;
};

