#ifndef INSTANCE_HPP
# define INSTANCE_HPP

#include <vector>

#include "Debug.h"
#include "Libraries.h"
#include "Utils.h"

namespace renderer {
    class Instance {
    public:
        Instance() = default;

        void setUp(const std::string &name);
        void cleanUp();

        VkInstance &get();

    private:
        static bool checkValidationLayerSupport();
        static std::vector<const char*> getRequiredExtensions();

    private:
        VkInstance _instance;

    };

}

#endif
