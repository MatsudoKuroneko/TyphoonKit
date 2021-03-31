#pragma once

#include "Sprite.h"
#include "Particle.h"
#include <vector>
#include <memory>

class ParticleManager
{
private:
	ParticleManager() {

	};
	~ParticleManager() = default;

	std::vector<std::shared_ptr<Particle>> _particles;
public:
	static ParticleManager* Instance() {
		static ParticleManager inst;
		return &inst;
	};

	void load() {  }//�R���X�g���N�^�N���p�BSceneManager�ŋN��������悤�ɂ���B

	void update();
	void draw() const;
	void Particle_Create(float x, float y, Colors color, int type = 0);
};