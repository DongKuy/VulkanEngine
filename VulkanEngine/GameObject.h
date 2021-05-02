#ifndef GAMEOBJECT_H
# define GAMEOBJECT_H

#include <algorithm>
#include <cmath>
#include <chrono>

#include "Model.h"
#include "Utils.h"
#include "ComponentBehavior.h"

namespace scene {

    class GameObject : public renderer::Model {
    public:
        explicit GameObject(renderer::ModelType modelType,renderer::ModelKey key);
        ~GameObject() override = default;

        void update(renderer::Models_t &models) override;
        void updateUniformBuffer(VkDevice &device, uint32_t currentImage) override;

        template <class T>
        void AddComponent(T newComponent);

    private:
        ComponentBehaviors_t _components;
    };
    template<class T>
    inline void GameObject::AddComponent(T newComponent)
    {
        _components.push_back(newComponent);
        std::cout << "컴포넌트 추가" << std::endl;
    }
}

std::ostream	&operator<<(std::ostream &stream, const glm::vec3 &vec);

#endif
