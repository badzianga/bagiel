#include <Rectangle.hpp>

#include <cmath>

namespace bgl {

    Rectangle::Rectangle(const Vector2& size) : m_size(size), m_rotation(0), m_scale({ 1.f, 1.f }) {
        m_vertices[0].position = { 0.f, 0.f };
        m_vertices[1].position = { size.x, 0.f };
        m_vertices[2].position = { 0.f, size.y };
        m_vertices[3].position = size;
        for (auto & vertex : m_vertices) {
            vertex.color = Color::Transparent;
        }
    }

    void Rectangle::setSize(const Vector2& size) {
        m_size = size;
        updateGeometry();
    }

    Vector2 Rectangle::getSize() const {
        return m_size;
    }

    void Rectangle::setFillColor(const bgl::Color &color) {
        for (auto & vertex : m_vertices) {
            vertex.color = color;
        }
    }

    Color Rectangle::getFillColor() const {
        return m_vertices[0].color;
    }

    void Rectangle::setPosition(const bgl::Vector2 &position) {
        m_position = position;
        updateGeometry();
    }

    void Rectangle::setRotation(float angle) {
        m_rotation = angle;
        updateGeometry();
    }

    void Rectangle::setScale(const bgl::Vector2 &factors) {
        m_scale = factors;
        updateGeometry();
    }

    Vector2 Rectangle::getPosition() const {
        return m_position;
    }

    float Rectangle::getRotation() const {
        return m_rotation;
    }

    Vector2 Rectangle::getScale() const {
        return m_scale;
    }

    void Rectangle::move(const bgl::Vector2 &offset) {
        m_position += offset;
        updateGeometry();
    }

    void Rectangle::rotate(float angle) {
        m_rotation += angle;
        updateGeometry();
    }

    void Rectangle::scale(const bgl::Vector2 &factors) {
        m_scale *= factors;
        updateGeometry();
    }

    Vector2 Rectangle::getCorner(int index) const {
        return m_vertices[index].position;
    }

    void Rectangle::updateGeometry() {
        // TODO: clean up this section - especially rotating the corners
        float rad = m_rotation * ((float)M_PI / 180.f);
        float s = std::sin(rad);
        float c = std::cos(rad);
        float xNew;
        float yNew;

        m_vertices[0].position = m_position * m_scale;
        // the first corner doesn't need to be rotated

        m_vertices[1].position = Vector2(m_position.x + m_size.x, m_position.y) * m_scale;
        m_vertices[1].position -= m_vertices[0].position;
        xNew = m_vertices[1].position.x * c - m_vertices[1].position.y * s;
        yNew = m_vertices[1].position.x * s + m_vertices[1].position.y * c;
        m_vertices[1].position = Vector2(xNew, yNew) + m_vertices[0].position;

        m_vertices[2].position = Vector2(m_position.x, m_position.y + m_size.y) * m_scale;
        m_vertices[2].position -= m_vertices[0].position;
        xNew = m_vertices[2].position.x * c - m_vertices[2].position.y * s;
        yNew = m_vertices[2].position.x * s + m_vertices[2].position.y * c;
        m_vertices[2].position = Vector2(xNew, yNew) + m_vertices[0].position;

        m_vertices[3].position = (m_position + m_size) * m_scale;
        m_vertices[3].position -= m_vertices[0].position;
        xNew = m_vertices[3].position.x * c - m_vertices[3].position.y * s;
        yNew = m_vertices[3].position.x * s + m_vertices[3].position.y * c;
        m_vertices[3].position = Vector2(xNew, yNew) + m_vertices[0].position;
    }

} // bgl
