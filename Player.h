#pragma once
#include "Sprite.h"
class Player : public Sprite
{
public:
	Player();
	virtual ~Player() = default;
	virtual bool update() override;
	virtual void draw() const override;
	float x, y;
private:
	int _img,_IMAGES[6],anime,allanime;
};