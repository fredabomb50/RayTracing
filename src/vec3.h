#include <math.h>
#include <iostream>
#include <stdlib.h>

using std::istream;
using std::ostream;


class vec3
{
    public:
        float e[3];

        vec3() {}
        vec3(float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2; }

        // Points
        inline float x() { return e[0]; }
        inline float y() { return e[1]; }
        inline float z() { return e[2]; }

        // Colors
        inline float r() { return e[0]; }
        inline float g() { return e[1]; }
        inline float b() { return e[2]; }

        // return pointer of vec3
        inline const vec3& operator+() const { return *this; }

        // return vec3 with inverted values
        inline vec3 operator-() const { return vec3( -e[0], -e[1], -e[2] ); }

        // return entry at index
        inline float operator[](int index) const { return e[index]; }

        // return pointer to entry at index
        inline float& operator[](int index) { return e[index]; }


        // Function definitions
        inline vec3& operator+=(const vec3& other_vec3);
        inline vec3& operator-=(const vec3& other_vec3);
        inline vec3& operator*=(const vec3& other_vec3);
        inline vec3& operator/=(const vec3& other_vec3);
        inline vec3& operator*=(const float val);
        inline vec3& operator/=(const float val);
        inline void make_unit_vector();


        // Size and stats
        inline float length() const 
        {
            return sqrt( e[0]*e[0] + e[1]*e[1] + e[2]*e[2] );
        }

        inline float squared_length() const
        {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};


// Stream operations
inline istream& operator>>(istream& stream, vec3& v)
{   
    stream >> v.e[0] >> v.e[1] >> v.e[2];
    return stream;
}

inline ostream& operator<<(ostream& stream, vec3& v)
{
    stream << v.e[0] << " " << v.e[1] << " " << v.e[2];
    return stream;
}


// Conversions
inline void vec3::make_unit_vector()
{
    float k = 1.0 / vec3::length();
    e[0] *= k;
    e[1] *= k;
    e[2] *= k;
}

// Standard operations
inline vec3 operator+(const vec3& v1, const vec3& v2)
{
    return vec3( v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2] );
}

inline vec3 operator-(const vec3& v1, const vec3& v2)
{
    return vec3( v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2] );
}

inline vec3 operator*(const vec3& v1, const vec3& v2)
{
    return vec3( v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2] );
}

inline vec3 operator/(const vec3& v1, const vec3& v2)
{
    return vec3( v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2] );
}

inline vec3 operator*(float val, const vec3& v)
{
    return vec3( val * v.e[0], val * v.e[1], val * v.e[2] );
}

// THIS MAY NEED TO ALIGN VERBATIM WITH THE BOOK
inline vec3 operator/(float val, const vec3& v)
{
    return vec3( v.e[0] / val, v.e[1] / val, v.e[2] / val );
}

inline float dot(const vec3& v1, const vec3& v2)
{
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2)
{
    return vec3
    (
        ( (v1.e[1] * v2.e[2]) - (v1.e[2] - v2.e[1]) ),
        ( (v1.e[1] * v2.e[2]) - (v1.e[2] - v2.e[1]) ),
        ( (v1.e[1] * v2.e[2]) - (v1.e[2] - v2.e[1]) )
    );
}