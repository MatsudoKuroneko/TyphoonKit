#pragma once

#include "BaseScene.h"
#include <memory>
#include "Load.h"
#include "Player.h"

class GameScene : public BaseScene
{
public:
	const static char* ParameterTagLevel;
	
	GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
	virtual ~GameScene() = default;

	void update() override;
	void draw() const override;
	int GetImage(Loads data) const;

private:
	int _level;
	std::shared_ptr<Player> _player;
};

