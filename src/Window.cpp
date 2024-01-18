#include <Window.hpp>
#include <Input.hpp>

#include <iostream>

namespace bgl {

    Window::Window() : p_window(nullptr), p_renderer(nullptr) {
        initGLFW();
    }

    Window::Window(uint32_t width, uint32_t height, const char *title) : p_window(nullptr), p_renderer(nullptr) {
        initGLFW();
        create(width, height, title);
    }

    Window::~Window() {
        delete p_renderer;
        glfwDestroyWindow(p_window);
        glfwTerminate();
    }

    void Window::create(uint32_t width, uint32_t height, const char *title) {
        p_window = glfwCreateWindow((int)width, (int)height, title, nullptr, nullptr);

        if (p_window == nullptr) {
            std::cerr << "Failed to create GLFW window!\n";
            glfwTerminate();
            exit(-1);
        }

        m_size = Vector2((float)width, (float)height);
        glfwMakeContextCurrent(p_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cerr << "Failed to initialize GLAD!\n";
            glfwDestroyWindow(p_window);
            glfwTerminate();
            exit(-1);
        }
        glfwSwapInterval(0);

        glViewport(0, 0, (int)width, (int)height);

        glfwSetKeyCallback(p_window, Input::keyCallback);
        glfwSetMouseButtonCallback(p_window, Input::mouseButtonCallback);
        glfwSetCursorPosCallback(p_window, Input::mousePosCallback);

        p_renderer = new Renderer(m_size);

        std::cout << "OpenGL API " << glGetString(GL_VERSION) << '\n';
        std::cout << "Using device: " << glGetString(GL_VENDOR) << " - " << glGetString(GL_RENDERER) << '\n';
    }

    void Window::close() {
        glfwSetWindowShouldClose(p_window, GLFW_TRUE);
    }

    void Window::clear(bgl::Color color) {
        p_renderer->clearData();
        glClearColor(color.r, color.g, color.b, color.a);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Window::display() {
        p_renderer->renderData();
        glfwSwapBuffers(p_window);
        glfwPollEvents();
    }

    void Window::draw(const Rectangle& rect) {
        p_renderer->addData(rect);
    }

    Vector2 Window::getSize() const {
        return m_size;
    }

    bool Window::isOpen() const {
        return !glfwWindowShouldClose(p_window);
    }

    void Window::setVSyncEnabled(bool enabled) {
        glfwSwapInterval((int)enabled);
    }

    void Window::initGLFW() {
        if (glfwInit() == GLFW_FALSE) {
            std::cerr << "[ERROR] Failed to initialize GLFW!\n";
            glfwTerminate();
            exit(-1);
        }
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    }

} // bgl
