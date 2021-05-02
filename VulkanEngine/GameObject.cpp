#include "GameObject.h"
#include "GameMain.h"

scene::GameObject::GameObject(renderer::ModelType modelType, renderer::ModelKey key) : renderer::Model(modelType, key) {
    //_velocity = glm::vec3(0.0f, 0.0f, 0.1f);
}

void scene::GameObject::update(renderer::Models_t &models) {
    for (auto& component : _components)
    {
        component->update(*this);
    }
}

void scene::GameObject::updateUniformBuffer (VkDevice &device, uint32_t currentImage) {
    Model::updateUniformBuffer(device, currentImage);
}

std::ostream &operator<<(std::ostream &stream, const glm::vec3 &vec) {
    stream << vec.x << " " << vec.y << " " << vec.z;
    return stream;
}
