#pragma once

// それぞれの処理の基本形式。

class Sprite
{
public:
	Sprite() = default;
	virtual ~Sprite() = default;
	virtual bool update() = 0;
	virtual void draw() const = 0;
};

