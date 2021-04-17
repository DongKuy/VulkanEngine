#ifndef WINDOW_HPP
# define WINDOW_HPP

#include "IApplication.h"
#include "Libraries.h"
#include "Utils.h"

namespace renderer {
    class Window {
    public:
        Window() = default;

        void setUp(IApplication *app, const std::string &appName);
        void cleanUp();

        GLFWwindow *get();
        bool shouldClose();

        void resize();
        void close();

    private:
        static void framebufferResizeCallback(GLFWwindow *window, int width, int height);

    public:
        bool resized = false;

    private:
        GLFWwindow *_window = nullptr;
    };

}

#endif
