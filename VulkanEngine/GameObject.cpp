#include "GameObject.h"
#include "GameMain.h"

scene::GameObject::GameObject(renderer::ModelType modelType, renderer::ModelKey key) : renderer::Model(modelType, key) {
    //_velocity = glm::vec3(0.0f, 0.0f, 0.1f);
}

void scene::GameObject::update(renderer::Models_t &models) {
    if (!_isActivation)return;

    for (auto& component : _components)
    {
        component->update(*this);
    }
}

void scene::GameObject::OnEntranceCollider(Model& model)
{
    if (model.Tag == 1)
    {
        auto tPos= model.getPosition();
        auto dPos = tPos - _position;
        auto n = glm::normalize(dPos) * 0.5f;
        auto tV = model.getVelocity();
        tV.x += n.x;
        tV.y += n.y;
        model.setVelocity(tV);

        _velocity.x -= n.x;
        _velocity.y -= n.y;
    }
}

void scene::GameObject::updateUniformBuffer (VkDevice &device, uint32_t currentImage) {
    Model::updateUniformBuffer(device, currentImage);
}

std::ostream &operator<<(std::ostream &stream, const glm::vec3 &vec) {
    stream << vec.x << " " << vec.y << " " << vec.z;
    return stream;
}
