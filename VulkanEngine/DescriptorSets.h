#ifndef DESCRIPTOR_SETS_H
# define DESCRIPTOR_SETS_H

#include <vector>

#include "Devices.h"
#include "Libraries.h"
#include "SwapChain.h"
#include "Texture.h"
#include "UniformBuffers.h"

namespace renderer {
    class DescriptorSets {
    public:
        DescriptorSets() = default;

        void setUp(VkDevice &device, SwapChain &swapChain, VkDescriptorSetLayout &layout,
                   Texture &texture, UniformBuffers &uniforms);
        void cleanUp(VkDevice &device);

        VkDescriptorSet &operator[](size_t i);

    private:
        void createDescriptorPool(VkDevice &device, size_t size);
        void createDescriptorSets(VkDevice &device, size_t size, VkDescriptorSetLayout &layout,
                                  Texture &texture, UniformBuffers &uniforms);

    private:
        VkDescriptorPool _descriptorPool = nullptr;
        std::vector<VkDescriptorSet> _descriptorSets;
    };

}

#endif
