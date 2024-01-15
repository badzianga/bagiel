#ifndef BAGIEL_INPUT_HPP
#define BAGIEL_INPUT_HPP

#include <unordered_map>

#include <GLFW/glfw3.h>

namespace bgl {

    class Input {
    public:
        Input(const Input&) = delete;
        static bool isKeyPressed(int key);
    private:
        Input() = default;
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

        static Input s_instance;
        std::unordered_map<int, bool> m_keyMap;

        friend class Window;
    };

} // bgl

#endif //BAGIEL_INPUT_HPP
