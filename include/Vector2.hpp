#ifndef BAGIEL_VECTOR2_HPP
#define BAGIEL_VECTOR2_HPP

namespace bgl {

    class Vector2 {
    public:
        float x;
        float y;

        Vector2();
        Vector2(float X, float Y);

        static const Vector2 Zero;
        static const Vector2 One;
        static const Vector2 Inf;
        static const Vector2 Left;
        static const Vector2 Right;
        static const Vector2 Up;
        static const Vector2 Down;

        [[nodiscard]] Vector2 abs() const;
        [[nodiscard]] Vector2 ceil() const;
        [[nodiscard]] Vector2 directionTo(const Vector2& to) const;
        [[nodiscard]] float distanceTo(const Vector2& to) const;
        [[nodiscard]] Vector2 floor() const;
        [[nodiscard]] float length() const;
        [[nodiscard]] Vector2 normalized() const;
        [[nodiscard]] Vector2 round() const;
    };

    Vector2 operator+(const Vector2& v1, const Vector2& v2);
    Vector2& operator+=(Vector2& v1, const Vector2& v2);
    Vector2 operator-(const Vector2& v);
    Vector2 operator-(const Vector2& v1, const Vector2& v2);
    Vector2& operator-=(Vector2& v1, const Vector2& v2);
    Vector2 operator*(const Vector2& v, float f);
    Vector2 operator*(float f, const Vector2& v);
    Vector2& operator*=(Vector2& v, float f);
    Vector2 operator/(const Vector2& v, float f);
    Vector2 operator/(float f, const Vector2& v);
    Vector2& operator/=(Vector2& v, float f);
    bool operator==(const Vector2& v1, const Vector2& v2);
    bool operator!=(const Vector2& v1, const Vector2& v2);

} // bgl

#endif //BAGIEL_VECTOR2_HPP
