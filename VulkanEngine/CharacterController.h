#ifndef CHARACTERCONTROLLER_H
# define CHARACTERCONTROLLER_H

#include "ComponentBehavior.h"

namespace scene {
	class CharacterController : public ComponentBehavior
	{
		void setUp()override;
		void release()override;
		void  update(scene::GameObject& gameObject) override;
	};
}
#endif
