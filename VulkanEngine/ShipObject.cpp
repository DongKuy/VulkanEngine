#include "ShipObject.h"
#include "GameMain.h"

scene::ShipObject::ShipObject(renderer::ModelType modelType, renderer::ModelKey key) : renderer::Model(modelType, key) {
    _velocity = glm::vec3(0.0f, 0.0f, 0.1f);
}

void scene::ShipObject::update(renderer::Models_t &models) {
    if (this->getId() != 0)
    {
        return;
    }
    scene::GameMain& app = scene::GameMain::Get();
    if (app.GetKeyDown(GLFW_KEY_UP))
	{
		_position += glm::vec3(0, 0, -0.1f * _maxSpeed);
	}
	if (app.GetKeyDown(GLFW_KEY_DOWN))
	{
		_position += glm::vec3(0, 0, 0.1f * _maxSpeed);
	}
	if (app.GetKeyDown(GLFW_KEY_LEFT))
	{
		_position += glm::vec3(-0.1f * _maxSpeed, 0, 0);
	}
	if (app.GetKeyDown(GLFW_KEY_RIGHT))
	{
		_position += glm::vec3(0.1f * _maxSpeed, 0, 0);
	}

	if (app.GetKeyDown(GLFW_KEY_SPACE))
	{
		_position += glm::vec3(0, 0.1f * _maxSpeed, 0);
	}
	if (app.GetKeyDown(GLFW_KEY_LEFT_SHIFT))
	{
		_position += glm::vec3(0, -0.1f * _maxSpeed, 0);
    }
    app.SetCameraLookAtTarget(true);
    app.SetCameraTarget(_position);
    app.SetCameraPosition(_position + glm::vec3(0.f, 1.3f, 3.5f));
    app.LightPos = _position;

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

glm::vec3 scene::ShipObject::boundaries() {
    glm::vec3 bound = glm::vec3(0.0f, 0.0f, 0.0f);
    if (_position.x < -10)
        bound.x = 1;
    else if (_position.x > 20)
        bound.x = -1;
    if (_position.y < -10)
        bound.y = 1;
    else if (_position.y > 20)
        bound.y = -1;
    if (_position.z < 0)
        bound.z = 1;
    else if (_position.z > 20)
        bound.z = -1;
    return bound;
}

void scene::ShipObject::updateUniformBuffer (VkDevice &device, uint32_t currentImage) {
    Model::updateUniformBuffer(device, currentImage);
}

std::ostream &operator<<(std::ostream &stream, const glm::vec3 &vec) {
    stream << vec.x << " " << vec.y << " " << vec.z;
    return stream;
}
