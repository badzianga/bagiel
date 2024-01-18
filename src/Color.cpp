#include <Color.hpp>

#include <cmath>

namespace bgl {

    Color::Color() : r(0.f), g(0.f), b(0.f), a(1.f) {}

    Color::Color(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha) {}

    Color::Color(const Color8& color) {
        r = (float)color.r / 255.f;
        g = (float)color.g / 255.f;
        b = (float)color.b / 255.f;
        a = (float)color.a / 255.f;
    }

    const Color Color::Red{ 1.f, 0.f, 0.f, 1.f };
    const Color Color::Green{ 0.f, 1.f, 0.f, 1.f };
    const Color Color::Blue{ 0.f, 0.f, 1.f, 1.f };
    const Color Color::Yellow{ 1.f, 1.f, 0.f, 1.f };
    const Color Color::Magenta{ 1.f, 1.f, 0.f, 1.f };
    const Color Color::Cyan{ 0.f, 1.f, 1.f, 1.f };
    const Color Color::White{ 1.f, 1.f, 1.f, 1.f };
    const Color Color::Black{ 0.f, 0.f, 0.f, 1.f };
    const Color Color::Transparent{ 0.f, 0.f, 0.f, 0.f };

    Color8::Color8() : r(0), g(0), b(0), a(255) {}

    Color8::Color8(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : r(red), g(green), b(blue), a(alpha) {}

    Color8::Color8(const Color& color) {
        r = (int)roundf(color.r * 255.f);
        g = (int)roundf(color.g * 255.f);
        b = (int)roundf(color.b * 255.f);
        a = (int)roundf(color.a * 255.f);
    }

    const Color8 Color8::Red{ 255, 0, 0, 255 };
    const Color8 Color8::Green{ 0, 255, 0, 255 };
    const Color8 Color8::Blue{ 0, 0, 255, 255 };
    const Color8 Color8::Yellow{ 255, 255, 0, 255 };
    const Color8 Color8::Magenta{ 255, 255, 0, 255 };
    const Color8 Color8::Cyan{ 0, 255, 255, 255 };
    const Color8 Color8::White{ 255, 255, 255, 255 };
    const Color8 Color8::Black{ 0, 0, 0, 255 };
    const Color8 Color8::Transparent{ 0, 0, 0, 0 };

} // bgl
