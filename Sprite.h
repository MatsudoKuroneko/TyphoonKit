#pragma once

// ‚»‚ê‚¼‚ê‚Ìˆ—‚ÌŠî–{Œ`®B

class Sprite
{
public:
	Sprite() = default;
	virtual ~Sprite() = default;
	virtual bool update() = 0;
	virtual void draw() const = 0;
};

