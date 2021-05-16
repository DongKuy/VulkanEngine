#ifndef CAMERAFOLLOWING_H
# define CAMERAFOLLOWING_H

#include "ComponentBehavior.h"

namespace scene {
	class CameraFollowing :
		public scene::ComponentBehavior
{
private:
	glm::vec3 _cameraArm;
	bool _isSetup = false;
	double _timer = glfwGetTime();
public:
	CameraFollowing();
	void setUp() override;
	void release() override;
	void update(GameObject& gameObejct) override;
};
};

#endif