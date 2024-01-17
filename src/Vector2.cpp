#include <Vector2.hpp>

#include <cmath>

namespace bgl {

    Vector2::Vector2() : x(0.f), y(0.f) {}

    Vector2::Vector2(float X, float Y) : x(X), y(Y) {}

    Vector2 Vector2::abs() const {
        return { std::abs(x), std::abs(y) };
    }

    Vector2 Vector2::ceil() const {
        return { std::ceil(x), std::ceil(y) };
    }

    Vector2 Vector2::directionTo(const Vector2& to) const {
        return { (to - *this).normalized() };
    }

    float Vector2::distanceTo(const Vector2& to) const {
        return std::sqrt(std::pow(x - to.x, 2.f) + std::pow(y - to.y, 2.f));
    }

    Vector2 Vector2::floor() const {
        return { std::floor(x), std::floor(y) };
    }

    float Vector2::length() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2 Vector2::normalized() const {
        return *this / length();
    }

    Vector2 Vector2::round() const {
        return { std::round(x), std::round(y) };
    }

    Vector2 operator+(const Vector2& v1, const Vector2& v2) {
        return { v1.x + v2.x, v1.y + v2.y };
    }

    Vector2& operator+=(Vector2& v1, const Vector2& v2) {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    }

    Vector2 operator-(const Vector2& v) {
        return { -v.x, -v.y };
    }

    Vector2 operator-(const Vector2& v1, const Vector2& v2) {
        return { v1.x - v2.x, v1.y - v2.y };
    }

    Vector2& operator-=(Vector2& v1, const Vector2& v2) {
        v1.x -= v2.x;
        v1.y -= v2.y;
        return v1;
    }

    Vector2 operator*(const Vector2& v, float f) {
        return { v.x * f, v.y * f };
    }

    Vector2 operator*(float f, const Vector2& v) {
        return { v.x * f, v.y * f };
    }

    Vector2 operator*(const Vector2& v1, const Vector2& v2) {
        return { v1.x * v2.x, v1.y * v2.y };
    }

    Vector2& operator*=(Vector2& v, float f) {
        v.x *= f;
        v.y *= f;
        return v;
    }

    Vector2& operator*=(Vector2& v1, const Vector2& v2) {
        v1.x *= v2.x;
        v1.y *= v2.y;
        return v1;
    }

    Vector2 operator/(const Vector2& v, float f) {
        return { v.x / f, v.y / f };
    }

    Vector2 operator/(float f, const Vector2& v) {
        return { v.x / f, v.y / f };
    }

    Vector2& operator/=(Vector2& v, float f) {
        v.x /= f;
        v.y /= f;
        return v;
    }

    bool operator==(const Vector2& v1, const Vector2& v2) {
        return v1.x == v2.x && v1.y == v2.y;
    }

    bool operator!=(const Vector2& v1, const Vector2& v2) {
        return v1.x != v2.x || v1.y != v2.y;
    }

    const Vector2 Vector2::Zero{ 0.f, 0.f };
    const Vector2 Vector2::One{ 1.f, 1.f };
    const Vector2 Vector2::Inf{ INFINITY, INFINITY };
    const Vector2 Vector2::Left(-1.f, 0.f);
    const Vector2 Vector2::Right(1.f, 0.f);
    const Vector2 Vector2::Up(0.f, -1.f);
    const Vector2 Vector2::Down(0.f, 1.f);

} // bgl
