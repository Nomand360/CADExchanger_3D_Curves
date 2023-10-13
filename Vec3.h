#ifndef VEC3_H
#define VEC3_H

template <typename T>
class Vec3
{
public:
    Vec3() : x(0), y(0), z(0){}

    Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z){}

    template <typename U>
    explicit Vec3(const Vec3<U> &vector) :
        x(static_cast<T>(vector.x)),
        y(static_cast<T>(vector.y)),
        z(static_cast<T>(vector.z)){}

    T x;
    T y;
    T z;
};

typedef Vec3<int> Vec3i;
typedef Vec3<float> Vec3f;

#endif // VEC3_H
