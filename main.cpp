#include <Window.hpp>
#include <Input.hpp>
#include <Renderer.hpp>
#include <Shader.hpp>

int main() {
    bgl::Window window{ 800, 600, "Bagiel Window" };
    window.setVSyncEnabled(true);

    bgl::Vertex vertices[] = {
            {bgl::Vector2(-0.5f, -0.5f), bgl::Color::Blue},
            {bgl::Vector2(0.5f, -0.5f), bgl::Color::Green},
            {bgl::Vector2(-0.5f, 0.5f), bgl::Color::Red},
            {bgl::Vector2(0.5f, 0.5f), bgl::Color::Yellow},
    };

    uint32_t indices[] = {
            0, 1, 2,
            1, 2, 3
    };

    bgl::VertexArray vao;
    bgl::VertexBuffer vbo{ vertices, sizeof(vertices) };
    bgl::ElementBuffer ebo{ indices, 6 };

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(bgl::Vertex), (const void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(bgl::Vertex), (const void*)(sizeof(bgl::Vector2)));
    glEnableVertexAttribArray(1);

    bgl::Shader shader{ "shaders/shader.vert", "shaders/shader.frag" };

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
