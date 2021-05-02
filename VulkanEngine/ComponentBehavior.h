#ifndef COMPONENTBEHAVIOR_H
# define COMPONENTBEHAVIOR_H

#include "Model.h"
#include "Utils.h"

namespace scene {
	class GameObject;
	class ComponentBehavior
	{
	public:
		explicit ComponentBehavior();
		virtual ~ComponentBehavior() = default;
		void Init();
		virtual void setUp() {}
		virtual void release() {};
		virtual void update(GameObject& gameObejct);
	};
	typedef std::vector<ComponentBehavior*> ComponentBehaviors_t;
}
#endif