#include "CommandPool.h"

void renderer::CommandPool::setUp(VkDevice &device, renderer::QueueFamilyIndices queueFamilyIndices) {
    VkCommandPoolCreateInfo poolInfo = {};
    poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily.value();
    poolInfo.flags = 0;

    if (vkCreateCommandPool(device, &poolInfo, nullptr, &_commandPool) != VK_SUCCESS)
        throw std::runtime_error("커맨드 풀을 만들지 못했습니다.");
}

void renderer::CommandPool::cleanUp(VkDevice &device) {
    vkDestroyCommandPool(device, _commandPool, nullptr);

}

VkCommandPool &renderer::CommandPool::get() {
    return _commandPool;
}
