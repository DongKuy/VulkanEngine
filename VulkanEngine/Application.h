#ifndef APPLICATION_H
# define APPLICATION_H

#include <unordered_map>

#include "IApplication.h"
#include "BufferManip.h"
#include "CommandPool.h"
#include "CommandBuffers.h"
#include "Debug.h"
#include "DepthImage.h"
#include "Devices.h"
#include "Framebuffers.h"
#include "GraphicsPipeline.h"
#include "Instance.h"
#include "Libraries.h"
#include "Mesh.h"
#include "Model.h"
#include "Surface.h"
#include "SwapChain.h"
#include "SyncObjects.h"
#include "Utils.h"
#include "Vertex.h"
#include "Window.h"

namespace renderer {
    class Application : public IApplication {
    public:
        explicit Application(const std::string &appName);
        ~Application();

        void run();
        bool GetKeyDown(int key) override;

    protected:
        virtual void initModels();

        virtual void onDraw();

        void onMouseMove(double x, double y) override;
        void onMouseDown(int button, int action) override;
        void onMouseScroll(double x, double y) override;
        void onKeyDown(int key, int action) override;

    private:
        void initVulkan();

        void cleanup();
        void cleanupSwapChain();
        void recreateSwapChain();

    protected:
        Window _window;
        SwapChain _swapChain;
        Models_t _models;

    private:
        const std::string _appName;

        Instance _instance;
        Debug _debugMessenger;
        Surface _surface;
        Devices _devices;
        GraphicsPipeline _pipeline;
        CommandPool _commandPool;
        CommandBuffers _commandBuffers;
        DepthImage _depthImage;
        Framebuffers _framebuffers;
        SyncObjects _syncObjects;

        MeshMap_t _meshes;
        TextureMap_t _textures;
    };
};

#endif