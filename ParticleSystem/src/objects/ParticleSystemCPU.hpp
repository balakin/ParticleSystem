#pragma once

#include <string>
#include <random>
#include <glm/glm.hpp>

#include "EmitParticleSystem.hpp"

class ParticleSystemCPU : public EmitParticleSystem
{
private:
	struct Particle
	{
		float lifespan;
		float lifeRemaining;
		glm::vec3 position;
		glm::vec3 velocity;
		glm::vec3 rotation;
		glm::vec3 angularVelocity;
		glm::vec4 colorBegin;
		glm::vec4 colorEnd;
		float sizeBegin;
		float sizeEnd;

		struct Particle* left;
		struct Particle* right;
	};

	struct Particle* pool = nullptr;
	struct Particle* firstParticle = nullptr;
	struct Particle* freeParticle = nullptr;
	unsigned int poolSize = 0;
	unsigned int activeCount = 0;
	std::mt19937_64 randomGenerator;
	std::uniform_real_distribution<float> distribution;

	float Random();
protected:
	void Compute(float deltaTime);
	void Emit(unsigned int count);
public:
	ParticleSystemCPU(
		const std::string& name,
		unsigned int poolSize,
		unsigned int particlesPerFrame,
		ParticleProperties particleProperties
	);

	void SetPoolSize(unsigned int size);

	void UI();
	void Render();
};
