#ifndef BAGIEL_RECTANGLE_HPP
#define BAGIEL_RECTANGLE_HPP

#include <Color.hpp>
#include <Vector2.hpp>
#include <Vertex.hpp>

#include <array>

namespace bgl {

    class Rectangle {
    public:
        explicit Rectangle(const Vector2& size=Vector2(0.f, 0.f));
        void setSize(const Vector2& size);
        [[nodiscard]] Vector2 getSize() const;
        void setFillColor(const Color& color);
        [[nodiscard]] Color getFillColor() const;
        void setPosition(const Vector2& position);
        void setRotation(float angle);
        void setScale(const Vector2& factors);
        [[nodiscard]] Vector2 getPosition() const;
        [[nodiscard]] float getRotation() const;
        [[nodiscard]] Vector2 getScale() const;
        void move(const Vector2& offset);
        void rotate(float angle);
        void scale(const Vector2& factors);
        [[nodiscard]] Vector2 getCorner(int index) const;
    private:
        Vector2 m_size;
        Vector2 m_position;
        float m_rotation;
        Vector2 m_scale;
        std::array<Vertex, 4> m_vertices;
        void updateGeometry();
        friend class Renderer;
    };

} // bgl

#endif //BAGIEL_RECTANGLE_HPP
