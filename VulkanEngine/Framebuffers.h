#ifndef FRAMEBUFFERS_H
# define FRAMEBUFFERS_H

#include <vector>
#include <array>

#include "Libraries.h"
#include "SwapChain.h"
#include "Utils.h"

namespace renderer {
    class Framebuffers {
    public:
        Framebuffers() = default;

        void setUp(VkDevice &device, SwapChain &swapChain, VkRenderPass &renderPass, VkImageView &depthImageView);
        void cleanUp(VkDevice &device);

        VkFramebuffer &operator[](size_t i);
        size_t size() const;

    private:
        std::vector<VkFramebuffer> _swapChainFramebuffers;

    };

}

#endif
