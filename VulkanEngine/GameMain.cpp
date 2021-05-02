#include "GameMain.h"
#include "PlayerController.h"

scene::GameMain* scene::GameMain::_instance = NULL;
scene::GameMain::GameMain() : renderer::Application("NoEngine") {
    initModels();
    std::srand(std::time(nullptr));
}

void scene::GameMain::initModels() {

    const size_t planeNb = 30;
    glm::vec3 position = glm::vec3(1.0f, 3.f, 2.f);

    auto newObject = GameObject(renderer::MODELTYPE[0], renderer::MODELKEY[0]);
    newObject.AddComponent(new PlayerController());
	_models.push_back(std::make_unique<GameObject>(newObject));
    _models.back()->setPosition(position);
    _models.back()->setOrientation(glm::vec3(0, 180, 0));

    for (int i = 0; i < 70; i++)
    {
        _models.push_back(std::make_unique<GameObject>(GameObject(renderer::MODELTYPE[1], renderer::MODELKEY[1])));
        _models.back()->setPosition(glm::vec3(rand() % 30 - 15, 0.f, rand() % 30 - 15));
        _models.back()->setOrientation(glm::vec3(0, rand() % 360, 0));
    }

    Application::initModels();
}

void scene::GameMain::onDraw() {
    checkKey();

    static auto startTime = std::chrono::high_resolution_clock::now();

    auto currentTime = std::chrono::high_resolution_clock::now();
    float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();

    for (auto &model : _models) {
        if (time > 0.02) {
            startTime = std::chrono::high_resolution_clock::now();
            model->update(_models);
        }
        model->setCamera(_camera, _swapChain.ratio());
    }
    Application::onDraw();
}

void scene::GameMain::checkKey() {
    for (const auto &it : _keyMap) {
        if (_keyCode[it.first] && _pressed)
            (_camera.get()->*it.second)();
    }
    if (_keyCode[GLFW_KEY_ESCAPE])
        _window.close();
}

void scene::GameMain::onMouseMove(double x, double y) {
    // std::cout << x << " " << y << std::endl;
}

void scene::GameMain::onMouseDown(int button, int action) {
    if (action == GLFW_PRESS)
        std::cout << "Clicked on: " << button << std::endl;
}

void scene::GameMain::onMouseScroll(double x, double y) {
    _camera->zoom(y);
}

void scene::GameMain::onKeyDown(int key, int action) {
    if (action == GLFW_PRESS) {
        _pressed = true;
        _keyCode[key] = true;
    } if (action == GLFW_RELEASE) {
        _pressed = false;
        _keyCode[key] = false;
    }
}

bool scene::GameMain::GetKeyDown(int key)
{
    return _keyCode[key];
}
