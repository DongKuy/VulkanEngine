#include "PlayerController.h"
#include "GameObject.h"
#include "GameMain.h"

void scene::PlayerController::setUp()
{
	std::cout << "palyer controller setup" << std::endl;
}

void scene::PlayerController::release()
{
	std::cout << "palyer controller release" << std::endl;
}

void scene::PlayerController::update(GameObject& gameObejct)
{
	scene::GameMain& app = scene::GameMain::Get();
	auto pos = gameObejct.getPosition();

	float maxSpeed = 0.5f;
	if (app.GetKeyDown(GLFW_KEY_UP))
	{
		pos += glm::vec3(0, 0, -0.1f * maxSpeed);
	}
	if (app.GetKeyDown(GLFW_KEY_DOWN))
	{
		pos += glm::vec3(0, 0, 0.1f * maxSpeed);
	}
	if (app.GetKeyDown(GLFW_KEY_LEFT))
	{
		pos += glm::vec3(-0.1f * maxSpeed, 0, 0);
	}
	if (app.GetKeyDown(GLFW_KEY_RIGHT))
	{
		pos += glm::vec3(0.1f * maxSpeed, 0, 0);
	}

	if (app.GetKeyDown(GLFW_KEY_SPACE))
	{
		pos += glm::vec3(0, 0.1f * maxSpeed, 0);
	}
	if (app.GetKeyDown(GLFW_KEY_LEFT_SHIFT))
	{
		pos += glm::vec3(0, -0.1f * maxSpeed, 0);
	}

	gameObejct.setPosition(pos);

	app.SetCameraLookAtTarget(true);
	app.SetCameraTarget(pos);
	app.SetCameraPosition(pos + glm::vec3(0.f, 1.3f, 3.5f));
	app.LightPos = pos;
}
