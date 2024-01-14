#ifndef BAGIEL_COLOR_H
#define BAGIEL_COLOR_H

#include <cstdint>

namespace bgl {

    class Color8;

    class Color {
    public:
        float r;
        float g;
        float b;
        float a;

        Color();
        Color(float red, float green, float blue, float alpha);
        explicit Color(const Color8& color);

        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color Yellow;
        static const Color Magenta;
        static const Color Cyan;
        static const Color White;
        static const Color Black;
    };


    class Color8 {
    public:
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        Color8();
        Color8(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
        explicit Color8(const Color& color);

        static const Color8 Red;
        static const Color8 Green;
        static const Color8 Blue;
        static const Color8 Yellow;
        static const Color8 Magenta;
        static const Color8 Cyan;
        static const Color8 White;
        static const Color8 Black;
    };

} // bgl

#endif //BAGIEL_COLOR_H
