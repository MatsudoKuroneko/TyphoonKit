#pragma once

// ���ꂼ��̏����̊�{�`���B

class Sprite
{
public:
	Sprite() = default;
	virtual ~Sprite() = default;
	virtual bool update() = 0;
	virtual void draw() const = 0;
};

