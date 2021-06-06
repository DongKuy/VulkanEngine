#include "Rigdbody.h"
#include "GameObject.h"
#include "GameMain.h"

scene::Rigdbody::Rigdbody()
{
}

void scene::Rigdbody::setUp()
{
	_isInit = true;
	_energy = (_pos.y + 10) * _gravity;
	_velocity.y = 10.f;
}

void scene::Rigdbody::release()
{
}

void scene::Rigdbody::update(GameObject& gameObejct)
{
	/*scene::GameMain& app = scene::GameMain::Get();
	if (!app.GetKeyDown(GLFW_KEY_ENTER))
	{
		return;
	}*/

	_pos = gameObejct.getPosition();
	if (!_isInit)
	{
		timer_ = glfwGetTime();
		setUp();
		gameObejct.setVelocity(_velocity);
	}
	if (_energy <= 0)
	{
		_energy = 0;
		_velocity = glm::vec3(0, 0, 0);
		return;
	}
	_velocity = gameObejct.getVelocity();

	double currentTime = glfwGetTime();
	float frameTime = currentTime - timer_;
	timer_ = currentTime;
	/*static float counter = 0.f;
	counter += frameTime;
	if (counter >= 0.2)
	{
		std::cout << _pos.y << std::endl;
		counter = 0;
	}*/

	_pos += _velocity * frameTime;
	_velocity.y -= _gravity * frameTime;
	auto p = (_pos.y+10) * _gravity;
	if (p <= 0)
	{
		_energy -= _deceleration;
		_velocity.y = glm::sqrt(_energy * 2);
		_velocity.x = (rand() % 2) - 1;
		_velocity.z = (rand() % 2) - 1;
	}

	gameObejct.setPosition(_pos);
	gameObejct.setVelocity(_velocity);
}