#include "HardTestCPUandGPU.hpp"

#include "../../objects/ParticleSystemCPUandGPU.hpp"

void HardTestCPUandGPU::Initialize()
{
	AddObject(new ParticleSystemCPUandGPU("Particle system", 350000, 1000, {
		30.0f,                               // lifespan
		0.0f,                                // lifespan variation
		glm::vec3(0.0f),                     // position
		glm::vec3(200.0f, 200.0f, 0.0f),     // position variation
		glm::vec3(0.0f),                     // velocity
		glm::vec3(15.0f, 15.0f, 0.0f),       // velocity variation
		glm::vec3(0.0f),                     // rotation
		glm::vec3(0.0f),                     // rotation variation
		glm::vec3(0.0f, 0.0f, 15.0f),        // angular velocity
		glm::vec3(0.0f, 0.0f, 30.0f),        // angular velocity variation
		glm::vec4(0.647f, 0.0f, 1.0f, 1.0f), // color begin
		glm::vec4(0.0f, 0.772f, 1.0f, 0.0f), // color end
		0.1f,                                // size begin
		0.35f,                               // size end
		0.0f                                 // size variation
		}, 350000));

	Camera& camera = GetCamera();
	camera.SetOrhographicProperties(110);
}
