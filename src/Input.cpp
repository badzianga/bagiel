#include <Input.hpp>

namespace bgl {

    Input Input::s_instance;

    Input::Input() : m_mouseMap(0), m_mousePosition(Vector2(0.f, 0.f)) {}

    void Input::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        s_instance.m_keyMap[key] = action;
    }

    void Input::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
        if (action) {
            s_instance.m_mouseMap |= (1 << button);
        }
        else {
            s_instance.m_mouseMap &= (0 << button);
        }
    }

    void Input::mousePosCallback(GLFWwindow* window, double xpos, double ypos) {
        s_instance.m_mousePosition.x = (float)xpos;
        s_instance.m_mousePosition.y = (float)ypos;
    }

    bool Input::isKeyPressed(int key) {
        return s_instance.m_keyMap[key];
    }

    bool Input::isMouseButtonPressed(int button) {
        return (s_instance.m_mouseMap >> button) & 1;
    }

    Vector2 Input::getMousePosition() {
        return s_instance.m_mousePosition;
    }

} // bgl
