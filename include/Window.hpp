#ifndef BAGIEL_WINDOW_HPP
#define BAGIEL_WINDOW_HPP

#include <cstdint>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Color.hpp>

namespace bgl {

    class Window {
    public:
        Window();
        Window(uint32_t width, uint32_t height, const char* title);
        virtual ~Window();
        void create(uint32_t width, uint32_t height, const char* title);
        void close();
        void clear(bgl::Color color = bgl::Color::Black);
        void display();
        [[nodiscard]] bool isOpen() const;
        void setVSyncEnabled(bool enabled);
    private:
        GLFWwindow* p_window;
        void initGLFW();
    };

} // bgl

#endif //BAGIEL_WINDOW_HPP
