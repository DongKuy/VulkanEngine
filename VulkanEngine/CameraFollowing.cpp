#include "CameraFollowing.h"
#include "GameObject.h"
#include "GameMain.h"

scene::CameraFollowing::CameraFollowing()
{
}

void scene::CameraFollowing::setUp()
{
	scene::GameMain& app = scene::GameMain::Get();
	_cameraArm = glm::vec3(0.f, 8.3f, 5.5f);
	auto pos = glm::vec3(1.0f, 3.f, 2.f);
	app.SetCameraLookAtTarget(true);
	_isSetup = true;
}

void scene::CameraFollowing::release()
{
}
static glm::vec3 Lerp(glm::vec3 p1, glm::vec3 p2, float t)
{
	return p1 * (1 - t) + p2 * t;
}

void scene::CameraFollowing::update(GameObject& gameObejct)
{
	scene::GameMain& app = scene::GameMain::Get();
	static auto armPos = gameObejct.getPosition() + _cameraArm;
	if (!_isSetup)
	{
		setUp();
		app.SetCameraPosition(armPos);
	}

	double currentTime = glfwGetTime();
	double frameTime = currentTime - _timer;
	_timer = currentTime;

	auto pos = app.GetCameraPosition();
	auto target = gameObejct.getPosition();
	armPos = Lerp(armPos, target + _cameraArm, frameTime*4.f);
	app.SetCameraPosition(armPos);
	app.SetCameraTarget(target);

	//app.SetCameraLookAtTarget(true);
	/*app.SetCameraTarget(pos);
	app.SetCameraPosition(pos );
	app.SetCameraTarget(pos);
	app.SetCameraPosition(pos );*/

}
