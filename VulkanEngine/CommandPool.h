#ifndef COMMAND_POOL_HPP
# define COMMAND_POOL_HPP

#include "Libraries.h"
#include "Utils.h"

namespace renderer {
    class CommandPool {
    public:
        CommandPool() = default;

        void setUp(VkDevice &device, QueueFamilyIndices queueFamilyIndices);
        void cleanUp(VkDevice &device);

        VkCommandPool &get();

    private:
        VkCommandPool _commandPool = nullptr;

    };

}


#endif
