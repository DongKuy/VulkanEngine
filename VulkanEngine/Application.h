#pragma once
#include "AllHeader.h"

class Application
{
public:

	void Start();

private:
	void InitWindow();
	void InitVulkan();
	void CreateInstance();
	void Reelase();

	void FrameUpdate();

private:
	GLFWwindow* window;
	VkInstance instance;
};

