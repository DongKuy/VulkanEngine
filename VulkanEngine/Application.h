#pragma once

class Application
{
public:

	void Start();

private:

	void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
	void SetupDebugMessenger();

	static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
	bool CheckValidationLayerSupport();
	std::vector<const char*> GetRequiredExtensions();

	void PickPhsicalDevice();
	void CreateLogicalDevice();
	void CreateSurface();
	void CreateSwapChain();
	void RecreateSwapChain();
	void ReleaseSwapChain();
	VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
	bool IsDeviceSuitable(VkPhysicalDevice device);
	bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
	QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);

	VkShaderModule CreateShaderModule(const std::vector<char>& code);

	void CreateImageViews();
	void CreateGraphicsPipeline();
	void CreateRenderPass();

	void CreateFramebuffers();
	static void framebufferResizeCallback(GLFWwindow* window, int width, int height) {
		auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
		app->_framebufferResized = true;
	}

	void CreateCommandbuffers();
	void CreateCommandPool();

	void CreateSyncObjects();

	uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

	void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
	void CreateVertexBuffer();
	void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

	void CreateIndexBuffer();

	void CreateDescriptorSetLayout();
	void CreateUniformBuffers();

	void CreateDescriptorPool();
	void CreateDescriptorSets();

private:
	void InitWindow();
	void InitVulkan();
	void CreateInstance();
	void Reelase();

	void FrameUpdate();
	void Rendering();
	void UpdateUniformBuffer(uint32_t currentImage);

private:
	GLFWwindow*					_window;
	VkInstance					_instance;

	VkDebugUtilsMessengerEXT	_debugMessenger;
	VkSurfaceKHR				_surface;

	VkDevice					_device;
	VkPhysicalDevice			_physicalDevice = VK_NULL_HANDLE;

	VkQueue						_graphicsQueue;
	VkQueue						_presentQueue;

	VkSwapchainKHR				_swapChain;
	std::vector<VkImage>		_swapChainImages;
	std::vector<VkImageView>	_swapChainImageViews;
	VkFormat					_swapChainImageFormat;
	VkExtent2D					_swapChainExtent;

	VkPipelineLayout			_pipelineLayout; 
	VkPipeline					_graphicsPipeline;
	VkRenderPass				_renderPass;
	VkDescriptorSetLayout		_descriptorSetLayout;

	std::vector<VkFramebuffer>	_swapChainFramebuffers;

	std::vector<VkCommandBuffer>	_commandBuffers;
	VkCommandPool					_commandPool;

	std::vector<VkSemaphore>	_imageAvailableSemaphores;
	std::vector<VkSemaphore>	_renderFinishedSemaphores;
	std::vector<VkFence>		_inFlightFences;
	std::vector<VkFence>		_imagesInFlight;

	size_t						_currentFrame = 0;
	bool						_framebufferResized = false;

	VkBuffer		_vertexBuffer;
	VkDeviceMemory	_vertexBufferMemory;
	VkBuffer		_indexBuffer;
	VkDeviceMemory	_indexBufferMemory;

	std::vector<VkBuffer>		_uniformBuffers;
	std::vector<VkDeviceMemory> _uniformBuffersMemory;

	VkDescriptorPool				_descriptorPool;
	std::vector<VkDescriptorSet>	_descriptorSets;

};