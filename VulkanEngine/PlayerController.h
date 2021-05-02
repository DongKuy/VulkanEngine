#ifndef PLAYERCONTROLLER_H
# define PLAYERCONTROLLER_H

#include "ComponentBehavior.h"

namespace scene {
class PlayerController :
    public scene::ComponentBehavior
{
public:
    void setUp() override;
    void release() override;
    void update(GameObject& gameObejct) override;
};
};

#endif
