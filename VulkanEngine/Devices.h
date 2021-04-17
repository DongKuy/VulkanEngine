#ifndef DEVICE_HPP
# define DEVICE_HPP

#include "Libraries.h"
#include "Surface.h"
#include "Utils.h"

namespace renderer {
    class Devices {
    public:
        Devices() = default;

        void setUp(VkInstance &instance, Surface &surface);
        void cleanUp();

        VkDevice &get();
        VkPhysicalDevice &getPhysical();
        VkQueue &getGraphicsQueue();
        VkQueue &getPresentQueue();

    private:
        void pickPhysicalDevice(VkInstance &instance, Surface &surface);
        void createLogicalDevice(Surface &surface);

    private:
        VkDevice _device = nullptr;
        VkPhysicalDevice _physicalDevice = VK_NULL_HANDLE;

        VkQueue _graphicsQueue = nullptr;
        VkQueue _presentQueue = nullptr;

    };

}

#endif
