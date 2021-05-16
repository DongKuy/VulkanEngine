#include "Bullet.h"
#include "GameObject.h"
#include "GameMain.h"


scene::Bullet::Bullet()
{
	setUp();
}

void scene::Bullet::setUp()
{
}

void scene::Bullet::release()
{
}

void scene::Bullet::update(GameObject& gameObejct)
{
	if (!_isSetup)
	{
		_isSetup = true;
		_gameobject = &gameObejct;
		gameObejct.setActivation(false);
	}

	double currentTime = glfwGetTime();
	double frameTime = currentTime - _timer;
	_timer = currentTime;
	static float counter = 0.f;

	if (IsAlive)
	{
		counter += frameTime;
		if (counter > 1.f)
		{
			_gameobject->setActivation(false);
			IsAlive = false;
			counter = 0.f;
		}
		auto pos = gameObejct.getPosition();
		pos += glm::vec3(0, 0, -0.1f * 2.f);
		gameObejct.setPosition(pos);
	}
}

void scene::Bullet::OnBullet(glm::vec3 pos)
{
	if (_gameobject == nullptr|| IsAlive)
		return;

	_gameobject->setActivation(true);
	_gameobject->setPosition(pos);
	IsAlive = true;
}
