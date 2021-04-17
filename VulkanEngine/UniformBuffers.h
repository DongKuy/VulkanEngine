#ifndef UNIFORM_BUFFERS_HPP
# define UNIFORM_BUFFERS_HPP

#include <vector>
#include <array>

#include "BufferManip.h"
#include "Devices.h"
#include "Libraries.h"
#include "Utils.h"

namespace renderer {
    class UniformBuffers {
    public:
        UniformBuffers() = default;

        void setUp(Devices &devices, size_t size);
        void cleanUp(VkDevice &device);

        VkBuffer &operator[](size_t i);
        VkDeviceMemory &getMemory(size_t i);

    private:
        std::vector<VkBuffer> _uniformBuffers;
        std::vector<VkDeviceMemory> _uniformBuffersMemory;

    };

}

#endif
