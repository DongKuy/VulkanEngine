#ifndef GRAPHICS_PIPELINE_HPP
# define GRAPHICS_PIPELINE_HPP

#include <vector>
#include <array>

#include "Devices.h"
#include "Libraries.h"
#include "SwapChain.h"
#include "Utils.h"
#include "Vertex.h"

namespace renderer {
    class GraphicsPipeline {
    public:
        GraphicsPipeline() = default;

        void setUp(Devices &device, SwapChain &swapChain);
        void cleanUp(VkDevice &device);

        VkPipeline &get();
        VkRenderPass &getRenderPass();
        VkPipelineLayout &getLayout();
        VkDescriptorSetLayout &getDescriptorSetLayout();

    private:
        void createRenderPass(Devices &device, SwapChain &swapChain);
        void createDescriptorSetLayout(VkDevice &device);
        void createGraphicsPipeline(VkDevice &device, SwapChain &swapChain);

        static VkShaderModule createShaderModule(VkDevice &device, const std::vector<char>& code);

    private:
        VkRenderPass _renderPass;
        VkPipeline _graphicsPipeline;
        VkPipelineLayout _pipelineLayout;
        VkDescriptorSetLayout _descriptorSetLayout;

    };

}

#endif
