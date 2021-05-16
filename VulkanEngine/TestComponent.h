#ifndef TESTCOMPONENT_H
# define TESTCOMPONENT_H

#include "ComponentBehavior.h"

namespace scene {
class TestComponent :
	public scene::ComponentBehavior
{
private:
	glm::vec3 _pow;
	glm::vec3 _startPow;
public:
	TestComponent();
	void setUp() override;
	void release() override;
	void update(GameObject& gameObejct) override;
};
};

#endif

