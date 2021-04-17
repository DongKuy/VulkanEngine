#ifndef SURFACE_HPP
# define SURFACE_HPP

#include <set>

#include "Debug.h"
#include "Libraries.h"
#include "Utils.h"

namespace renderer {
    class Surface {
    public:
        Surface() = default;

        void setUp(VkInstance &instance, GLFWwindow* window);
        void cleanUp(VkInstance &instance);

        VkSurfaceKHR &get();

        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
        bool isDeviceSuitable(VkPhysicalDevice device);

    private:
        static bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    private:
        VkSurfaceKHR _surface;

    };

}

#endif
