#include <Window.hpp>
#include <Input.hpp>
#include <iostream>


int main() {
    bgl::Window window{ 800, 600, "Window Title" };

    bgl::Rectangle rect{ bgl::Vector2(300.f, 300.f) };
    rect.setFillColor(bgl::Color::Red);
    rect.setPosition(bgl::Vector2(30.f, 40.f));

    while (window.isOpen()) {
        if (bgl::Input::isKeyPressed(GLFW_KEY_ESCAPE)) {
            window.close();
        }

        window.clear(bgl::Color::White);

        window.draw(rect);

        window.display();
    }

    return 0;
}
