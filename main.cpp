#include <Window.hpp>

int main() {
    bgl::Window window{ 800, 600, "Bagiel Window" };

    while (window.isOpen()) {
        window.clear();

        window.display();
    }

    return 0;
}
