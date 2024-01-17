#include <Window.hpp>
#include <Input.hpp>
#include <Renderer.hpp>
#include <Shader.hpp>

#include <glm/gtc/matrix_transform.hpp>

int main() {
    bgl::Window window{ 800, 600, "Bagiel Window" };
    window.setVSyncEnabled(true);

    bgl::Vertex vertices[] = {
            {bgl::Vector2(200.f, 150.f), bgl::Color::Blue},
            {bgl::Vector2(600.f, 150.f), bgl::Color::Green},
            {bgl::Vector2(200.f, 450.f), bgl::Color::Red},
            {bgl::Vector2(600.f, 450.f), bgl::Color::Yellow},
    };

    uint32_t indices[] = {
            0, 1, 2,
            1, 3, 2
    };

    bgl::VertexArray vao;
    bgl::VertexBuffer vbo{ vertices, sizeof(vertices) };
    bgl::ElementBuffer ebo{ indices, 6 };

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(bgl::Vertex), (const void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(bgl::Vertex), (const void*)(sizeof(bgl::Vector2)));
    glEnableVertexAttribArray(1);

    bgl::Shader shader{ "shaders/shader.vert", "shaders/shader.frag" };

    glm::mat4 projectionMatrix = glm::ortho(0.f, window.getSize().x, window.getSize().y, 0.f, 0.f, 1.f);
    shader.setMatrix4("u_projection", projectionMatrix);

    while (window.isOpen()) {
        if (bgl::Input::isKeyPressed(GLFW_KEY_ESCAPE)) {
            window.close();
        }

        window.clear(bgl::Color::Cyan);
        glDrawElements(GL_TRIANGLES, (int)ebo.getCount(), GL_UNSIGNED_INT, nullptr);

        window.display();
    }

    return 0;
}
