#pragma once
#include "Sprite.h"
#include "Score.h"
class Player : public Sprite
{
public:
	Player();
	virtual ~Player() = default;
	virtual bool update() override;
	virtual void draw() const override;
	float x, y;
};