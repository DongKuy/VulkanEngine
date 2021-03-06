#ifndef GAMEMAIN_H
# define GAMEMAIN_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <algorithm>
#include <unordered_map>

#include "Application.h"
#include "Camera.h"
#include "GameObject.h"

namespace scene {
    class GameMain : public renderer::Application {

    private:
        static GameMain* _instance;
    public:
        GameMain();
        static void CreateInstance()
        {
                _instance = new GameMain();
        }
        static GameMain& Get()
        {
            return *_instance;
        }
        bool GetKeyDown(int key)final;

        void SetCameraTarget(glm::vec3 pos) {
            _camera->Target = pos;
        }
        void SetCameraLookAtTarget(bool isOn)
        {
            _camera->IsLookAtTarget = isOn;
        }
        void SetCameraPosition(glm::vec3 pos)
        {
            _camera->SetPosition(pos);
        }
        glm::vec3 GetCameraPosition() { return _camera->getCameraPosition(); }

        glm::vec3 LightPos;
        glm::vec3 LightColor = glm::vec3(1,1,1);
        float LightPow = 3.8;

    private:
        void initModels() override;

        void onDraw() override;

        void checkKey();

        void onMouseMove(double x, double y) final;
        void onMouseDown(int button, int action) final;
        void onMouseScroll(double x, double y) final;
        void onKeyDown(int key, int action) final;

    private:
        bool _pressed = false;
        bool _keyCode[512] = { false };
        Camera_ptr_t _camera = std::make_unique<Camera>(Camera());
        const std::unordered_map<int, change_camera_t> _keyMap = {
                {GLFW_KEY_W, &scene::Camera::moveForward},
                {GLFW_KEY_S, &scene::Camera::moveBackward},
                {GLFW_KEY_R, &scene::Camera::moveUp},
                {GLFW_KEY_F, &scene::Camera::moveDown},
                {GLFW_KEY_A, &scene::Camera::moveLeft},
                {GLFW_KEY_D, &scene::Camera::moveRight},
                {GLFW_KEY_Q, &scene::Camera::rotateLeft},
                {GLFW_KEY_E, &scene::Camera::rotateRight}
        };

    };
}

#endif
