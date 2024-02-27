#pragma once

#include <cmath>

class Vector3f
{
public:
    float x, y, z;
    Vector3f() : x{0}, y{0}, z{0} {};
    Vector3f(float x, float y, float z) : x{x}, y{y}, z{z} {};

    Vector3f operator+(const Vector3f& other) const;
    Vector3f operator-(const Vector3f& other) const;

    Vector3f& operator+=(const Vector3f& other);
    Vector3f& operator-=(const Vector3f& other);

    inline bool operator==(const Vector3f& other) const;

    float Length() const;
    float LengthSquared() const;
    Vector3f Normalized() const;
    float Dot(const Vector3f& other) const;
    Vector3f Cross(const Vector3f& other) const;
    Vector3f Invert() const;
};