#ifndef DEPTH_IMAGE_H
# define DEPTH_IMAGE_H

#include "BufferManip.h"
#include "Devices.h"
#include "Libraries.h"
#include "Utils.h"

namespace renderer {
    class DepthImage {
    public:
        DepthImage() = default;

        void setUp(Devices &devices, VkExtent2D &extent);
        void cleanUp(VkDevice &device);

        VkImageView &get();

    private:
        VkImage _depthImage;
        VkDeviceMemory _depthImageMemory;
        VkImageView _depthImageView;
    };

}

#endif
