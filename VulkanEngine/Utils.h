#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <vector>
#include <optional>
#include <fstream>
#include <cstdint>
#include <cstdlib>

#include "Libraries.h"

namespace renderer {
    const int WIDTH = 1024;
    const int HEIGHT = 768;
    const int MAX_FRAMES_IN_FLIGHT = 2;
    const float PI = 3.14159265358979323846264338327950288f;

    const std::string PATH = "../Resources/";
    //const VkClearColorValue BACKGROUND_COLOR = {0.61f, 0.76f, 0.82f, 1.0f};
    const VkClearColorValue BACKGROUND_COLOR = {0.f, 0.f, 0.f, 1.0f};

    const std::vector<const char*> validationLayers = {
            "VK_LAYER_KHRONOS_validation"
    };
    const std::vector<const char*> deviceExtensions = {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };

    struct UniformBufferObject {
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 proj;
        glm::vec3 lightColor;
        glm::vec3 lightPos;
        glm::vec3 viewPos;
        float brightness;
	};

    struct QueueFamilyIndices {
        std::optional<uint32_t> graphicsFamily;
        std::optional<uint32_t> presentFamily;

        bool isComplete() {
            return graphicsFamily.has_value() && presentFamily.has_value();
        }
    };

    struct SwapChainSupportDetails {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    enum ModelType {
        SHIPMODEL,
        CASAMODEL
    };

    enum ModelKey {
        SHIP,
        CASA
    };

    const ModelType MODELTYPE[] = { SHIPMODEL, CASAMODEL };
    const ModelKey MODELKEY[] = { SHIP, CASA };

    std::vector<char> readFile(const std::string& filename);
    VkFormat findDepthFormat(VkPhysicalDevice &device);
    VkFormat findSupportedFormat(VkPhysicalDevice &device, const std::vector<VkFormat>& candidates,
                                 VkImageTiling tiling, VkFormatFeatureFlags features);
    uint32_t findMemoryType(VkPhysicalDevice &device, uint32_t typeFilter, VkMemoryPropertyFlags properties);
}

#endif
