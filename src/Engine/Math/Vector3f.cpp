#include "Vector3f.hpp"

using namespace Engine::Math;

Vector3f Vector3f::operator+(const Vector3f& other) const
{
    return Vector3f(x + other.x, y + other.y, z + other.z);
}

Vector3f Vector3f::operator-(const Vector3f& other) const
{
    return Vector3f(x - other.x, y - other.y, z - other.z);
}

Vector3f& Vector3f::operator+=(const Vector3f& other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3f& Vector3f::operator-=(const Vector3f& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

bool Vector3f::operator==(const Vector3f& other) const
{
    return x == other.x && y == other.y && z == other.z;
}

float Vector3f::Length() const
{
    return sqrt(x * x + y * y + z * z);
}

float Vector3f::LengthSquared() const
{
    return x * x + y * y + z * z;
}

Vector3f Vector3f::Normalized() const
{
    float length = Length();
    if(length > 0) {
        length = 1.0f / length;
        return Vector3f(x * length, y * length, z * length);
    }

    return Vector3f();
}

float Vector3f::Dot(const Vector3f& other) const
{
    return x * other.x + y * other.y + z * other.z;
}

Vector3f Vector3f::Cross(const Vector3f& other) const
{
    return Vector3f(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

Vector3f Vector3f::Invert() const
{
    return Vector3f(-x, -y, -z);
}