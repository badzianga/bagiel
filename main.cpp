#include <Window.hpp>
#include <Input.hpp>
#include <Renderer.hpp>
#include <Shader.hpp>

#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

int main() {
    bgl::Window window{ 800, 600, "Bagiel Window" };

    bgl::Shader shader{ "shaders/shader.vert", "shaders/shader.frag" };

    glm::mat4 projectionMatrix = glm::ortho(0.f, window.getSize().x, window.getSize().y, 0.f, 0.f, 1.f);
    shader.setMatrix4("u_projection", projectionMatrix);

    bgl::Rectangle rect{ { 32.f, 32.f } };
    rect.setFillColor(bgl::Color::Black);

    double previousTime = glfwGetTime();
    int frameCount = 0;

    while (window.isOpen()) {
        window.clear(bgl::Color8(144, 144, 168, 255));

        if (bgl::Input::isKeyPressed(GLFW_KEY_ESCAPE)) {
            window.close();
        }

        double currentTime = glfwGetTime();
        frameCount++;
        if (currentTime - previousTime >= 1.0) {
            std::cout << frameCount << '\n';
            frameCount = 0;
            previousTime = currentTime;
        }

        for (int y = 4; y < 600; y += 40) {
            for (int x = 4; x < 800; x += 40) {
                rect.setPosition({ (float)x, (float)y });
                window.draw(rect);
            }
        }

        window.display();
    }

    return 0;
}
