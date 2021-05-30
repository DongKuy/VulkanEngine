#ifndef RIGDBODY_H
# define RIGDBODY_H

#include "ComponentBehavior.h"

namespace scene {
    class Rigdbody :
        public scene::ComponentBehavior
    {
    private:
        double timer_;
        bool _isInit = false;

        float _gravity = 12.8f;
        float _deceleration = 20.5f;
        glm::vec3 _velocity = glm::vec3(0,0,0);

        float _energy = 0.f;
        float _moveEnergy = 0.f;

        glm::vec3 _pos;
    public:
        Rigdbody();
        void setUp() override;
        void release() override;
        void update(GameObject& gameObejct) override;
    };
}
#endif
