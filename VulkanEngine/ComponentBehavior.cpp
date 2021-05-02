#include "ComponentBehavior.h"

scene::ComponentBehavior::ComponentBehavior()
{
	std::cout << "test" << std::endl;
	Init();
	setUp();
}

void scene::ComponentBehavior::Init()
{
}

void scene::ComponentBehavior::update(GameObject& gameObejct)
{
}
