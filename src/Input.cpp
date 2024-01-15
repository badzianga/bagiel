#include "Input.hpp"

namespace bgl {

    Input Input::s_instance;

    void Input::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        s_instance.m_keyMap[key] = action;
    }

    bool Input::isKeyPressed(int key) {
        return s_instance.m_keyMap[key];
    }

} // bgl
