#include "PlayerController.h"
#include "GameObject.h"
#include "GameMain.h"
#include "Bullet.h"

double timer = glfwGetTime();
scene::PlayerController::PlayerController()
{
	setUp();
}

void scene::PlayerController::setUp()
{
	std::cout << "palyer controller setup" << std::endl;
}

void scene::PlayerController::release()
{
	std::cout << "palyer controller release" << std::endl;
}

bool isPressKey = false;
void scene::PlayerController::update(GameObject& gameObejct)
{
	double currentTime = glfwGetTime();
	double frameTime = currentTime - timer;
	timer = currentTime;

	scene::GameMain& app = scene::GameMain::Get();
	auto pos = gameObejct.getPosition();

	float maxSpeed = 0.9f;
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

	static float counter = 0.f;
	counter += frameTime;
	if (app.GetKeyDown(GLFW_KEY_LEFT_CONTROL)&&!isPressKey&& counter>0.1f)
	{
		counter = 0.f;
		for(auto &item : _bulletList)
		{
			if (!item->IsAlive)
			{
				item->OnBullet(pos);
				break;
			}
		}
	}
	

	gameObejct.setPosition(pos);
	app.LightPos = pos;
}

void scene::PlayerController::AddBullet(Bullet* newBullet)
{
	_bulletList.push_back(newBullet);
}
