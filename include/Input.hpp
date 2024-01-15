#ifndef BAGIEL_INPUT_HPP
#define BAGIEL_INPUT_HPP

#include <unordered_map>

#include <GLFW/glfw3.h>

#include <Vector2.hpp>

namespace bgl {

    class Input {
    public:
        Input(const Input&) = delete;
        static bool isKeyPressed(int key);
        static bool isMouseButtonPressed(int button);
        static Vector2 getMousePosition();
    private:
        Input();
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        static void mousePosCallback(GLFWwindow* window, double xpos, double ypos);

        static Input s_instance;
        std::unordered_map<int, bool> m_keyMap;
        uint8_t m_mouseMap;
        Vector2 m_mousePosition;

        friend class Window;
    };

} // bgl

#endif //BAGIEL_INPUT_HPP
