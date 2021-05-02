#ifndef CAMERA_H
# define CAMERA_H

#include <memory>

#include "Libraries.h"

namespace scene {

    class Camera {
    public:
        Camera();

        const glm::vec3 &getCameraPosition() const;
        glm::mat4 getViewMatrix() const;
        glm::mat4 getProjectionMatrix(float ratio) const;

        void zoom(double yOffset);

        void moveForward();
        void moveBackward();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void rotateLeft();
        void rotateRight();

        bool IsLookAtTarget = false;
		glm::vec3 Target = glm::vec3(0.f, 0.f, 0.f);
        void SetPosition(glm::vec3 pos) { _cameraPos = pos; }

    private:
        void updateCamerasVectors();

    private:
        float _fov = 45.0f;

        glm::vec3 _cameraPos = glm::vec3(0.0f, 0.0f, -4.0f);
        glm::vec3 _cameraFront = glm::vec3(0.0f, 0.0f, 1.0f);
        glm::vec3 _cameraRight = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
        const glm::vec3 _worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

        const float _cameraSpeed = 0.1f;
    };

    typedef std::unique_ptr<Camera> Camera_ptr_t;
    typedef void (scene::Camera::*change_camera_t)();

}

#endif
