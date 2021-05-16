#include "TestComponent.h"
#include "GameObject.h"
#include "GameMain.h"

scene::TestComponent::TestComponent()
{
	setUp();
}

void scene::TestComponent::setUp()
{
	_startPow = _pow = glm::vec3(0, (rand() % 3)+0.1f, 0);
}

void scene::TestComponent::release()
{
}

void scene::TestComponent::update(GameObject& gameObejct)
{
	_pow = _pow * 1.2f;
	gameObejct.setOrientation(_pow);

	if (_pow.x >= 360) _pow.x = _startPow.x;
	if (_pow.y >= 360) _pow.y = _startPow.y;
	if (_pow.z >= 360) _pow.z = _startPow.z;
}
