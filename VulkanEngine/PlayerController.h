#ifndef PLAYERCONTROLLER_H
# define PLAYERCONTROLLER_H

#include "ComponentBehavior.h"
#include "Bullet.h"

namespace scene {
class PlayerController :
    public scene::ComponentBehavior
{
private:
    std::vector<Bullet*> _bulletList;
public:
    PlayerController();
    void setUp() override;
    void release() override;
    void update(GameObject& gameObejct) override;

    void AddBullet(Bullet* newBullet);
};
};

#endif
