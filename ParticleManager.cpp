#include "ParticleManager.h"

void ParticleManager::update()
{
	for (auto& e : _particles) {
		e->update();
	}
	return;
}

void ParticleManager::draw() const
{
	for (auto& e : _particles) {
		e->draw();
	}
	return;
}

void ParticleManager::Particle_Create(float x, float y, Colors color,int type)
{
	_particles.emplace_back(std::make_shared<Particle>(x, y, color, type));
}
