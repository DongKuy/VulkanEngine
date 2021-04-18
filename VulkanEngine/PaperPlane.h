#ifndef PAPER_PLANE_HPP
# define PAPER_PLANE_HPP

#include <algorithm>
#include <cmath>
#include <chrono>

#include "Model.h"
#include "Utils.h"

namespace scene {

    class ShipObject : public renderer::Model {
    public:
        explicit ShipObject(renderer::ModelKey key);
        ~ShipObject() override = default;

        void update(renderer::Models_t &models) override;
        void updateUniformBuffer(VkDevice &device, uint32_t currentImage) override;

    private:
        glm::vec3 boundaries();

    private:
        const double _separationMin = 1.5f;
        const double _maxSpeed = 0.5f;
    };
}

std::ostream	&operator<<(std::ostream &stream, const glm::vec3 &vec);

#endif
