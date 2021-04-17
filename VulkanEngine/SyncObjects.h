#ifndef SYNC_OBJECTS_HPP
# define SYNC_OBJECTS_HPP

#include <vector>

#include "CommandBuffers.h"
#include "Devices.h"
#include "Libraries.h"
#include "Model.h"
#include "SwapChain.h"
#include "Utils.h"

namespace renderer {
    class SyncObjects {
    public:
        SyncObjects() = default;

        void setUp(VkDevice &device, size_t size);
        void cleanUp(VkDevice &device);

        bool drawFrame(Devices &devices, SwapChain &swapChain, Models_t &models,
                CommandBuffers &buffers, bool isResized);

    private:
        size_t _currentFrame = 0;
        std::vector<VkSemaphore> _imageAvailableSemaphores;
        std::vector<VkSemaphore> _renderFinishedSemaphores;
        std::vector<VkFence> _inFlightFences;
        std::vector<VkFence> _imagesInFlight;
    };

}

#endif
