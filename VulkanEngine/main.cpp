#include "AllHeader.h"
#include "Application.h"

int main()
{
	Application* app = new Application();

    try {
        app->Start();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

	return 0;
}