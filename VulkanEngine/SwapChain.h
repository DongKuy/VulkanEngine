#ifndef SWAP_CHAIN_H
# define SWAP_CHAIN_H

#include <vector>

#include "BufferManip.h"
#include "Devices.h"
#include "Libraries.h"
#include "Surface.h"
#include "Utils.h"

namespace renderer {
    class SwapChain {
    public:
        SwapChain() = default;

        void setUp(GLFWwindow* window, Surface &surface, Devices &devices);
        void cleanUp(VkDevice &device);

        VkSwapchainKHR &get();
        VkFormat &getImageFormat();
        VkImageView &getImageView(size_t i);
        VkExtent2D &getExtent();
        size_t size();
        float ratio();


    private:
        void createSwapChain(GLFWwindow* window, Surface &surface, Devices &devices);
        void createImageViews(VkDevice &device);

        static VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
        static VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
        static VkExtent2D chooseSwapExtent(GLFWwindow* window, const VkSurfaceCapabilitiesKHR& capabilities);

    private:
        VkSwapchainKHR _swapChain = nullptr;
        VkFormat _swapChainImageFormat = {};
        std::vector<VkImage> _swapChainImages;
        std::vector<VkImageView> _swapChainImageViews;
        VkExtent2D _swapChainExtent = {};

    };
}

#endif
