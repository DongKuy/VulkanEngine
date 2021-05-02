#include "CharacterController.h"
#include "GameMain.h"

void scene::CharacterController::setUp()
{
}

void scene::CharacterController::release()
{
}

void scene::CharacterController::update(scene::GameObject& gameObject)
{
	std::cout << "aaa" << std::endl;
    auto pos = gameObject.getPosition();
    float speed = 15.f;

    scene::GameMain& app = scene::GameMain::Get();
    if (app.GetKeyDown(GLFW_KEY_UP))
    {
        pos += glm::vec3(0, 0, -0.1f * speed);
    }
    if (app.GetKeyDown(GLFW_KEY_DOWN))
    {
        pos += glm::vec3(0, 0, 0.1f * speed);
    }
    if (app.GetKeyDown(GLFW_KEY_LEFT))
    {
        pos += glm::vec3(-0.1f * speed, 0, 0);
    }
    if (app.GetKeyDown(GLFW_KEY_RIGHT))
    {
        pos += glm::vec3(0.1f * speed, 0, 0);
    }

    if (app.GetKeyDown(GLFW_KEY_SPACE))
    {
        pos += glm::vec3(0, 0.1f * speed, 0);
    }
    if (app.GetKeyDown(GLFW_KEY_LEFT_SHIFT))
    {
        pos += glm::vec3(0, -0.1f * speed, 0);
    }

    gameObject.setPosition(pos);

    app.SetCameraLookAtTarget(true);
    app.SetCameraTarget(pos);
    app.SetCameraPosition(pos + glm::vec3(0.f, 1.3f, 3.5f));
    app.LightPos = pos;

    if (app.GetKeyDown(GLFW_KEY_INSERT))
    {
        app.LightColor.x += 0.01f;
    }
    if (app.GetKeyDown(GLFW_KEY_DELETE))
    {
        app.LightColor.x -= 0.01f;
    }

    if (app.GetKeyDown(GLFW_KEY_HOME))
    {
        app.LightColor.y += 0.01f;
    }
    if (app.GetKeyDown(GLFW_KEY_END))
    {
        app.LightColor.y -= 0.01f;
    }

    if (app.GetKeyDown(GLFW_KEY_PAGE_UP))
    {
        app.LightColor.z += 0.01f;
    }
    if (app.GetKeyDown(GLFW_KEY_PAGE_DOWN))
    {
        app.LightColor.z -= 0.01f;
    }

    if (app.GetKeyDown(GLFW_KEY_1))
    {
        app.LightPow += 0.01f;
    }
    if (app.GetKeyDown(GLFW_KEY_2))
    {
        app.LightPow -= 0.01f;
    }
}
