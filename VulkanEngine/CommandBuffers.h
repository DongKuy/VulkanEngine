#ifndef COMMAND_BUFFERS_H
# define COMMAND_BUFFERS_H

#include <vector>
#include <array>

#include "Framebuffers.h"
#include "GraphicsPipeline.h"
#include "Libraries.h"
#include "SwapChain.h"
#include "Mesh.h"
#include "Model.h"
#include "Texture.h"
#include "UniformBuffers.h"
#include "Utils.h"

namespace renderer {
    class CommandBuffers {
    public:
        CommandBuffers() = default;

        void setUp(VkDevice &device, SwapChain &swapChain, GraphicsPipeline &pipeline, Framebuffers &framebuffers,
                   VkCommandPool &pool, MeshMap_t &meshes, Models_t &models);
        void cleanUp(VkDevice &device, VkCommandPool &pool);

        VkCommandBuffer &operator[](size_t i);
        size_t size() const;

    private:
        std::vector<VkCommandBuffer> _commandBuffers;
    };

}

#endif