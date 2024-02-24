#include "Vector3f.hpp"

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