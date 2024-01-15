#include <Window.hpp>
#include <Input.hpp>

#include <iostream>

int main() {
    bgl::Window window{ 800, 600, "Bagiel Window" };
    window.setVSyncEnabled(true);

    while (window.isOpen()) {
        if (bgl::Input::isKeyPressed(GLFW_KEY_ESCAPE)) {
            window.close();
        }

        window.clear(bgl::Color::Cyan);

        window.display();
    }

    return 0;
}
