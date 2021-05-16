#ifndef BULLET_H
# define BULLET_H
#include "ComponentBehavior.h"

namespace scene {
    class Bullet :
        public scene::ComponentBehavior
    {
    private:
        double _timer = glfwGetTime();
        bool _isSetup = false;
    public:
        bool IsAlive = false;

        Bullet();
        void setUp() override;
        void release() override;
        void update(GameObject& gameObejct) override;

        void OnBullet(glm::vec3 pos);
    };
};

#endif


