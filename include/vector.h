#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3 {
    public:
    vec3(){}
    vec3(float a, float b, float c) { v[0] = a; v[1] = b; v[2] = c;}
    vec3(float a) {v[0] = v[1] = v[2] = a;}
    inline float x() const {return v[0];}
    inline float y() const {return v[1];}
    inline float z() const {return v[2];}
    inline float r() const {return v[0];}
    inline float g() const {return v[1];}
    inline float b() const {return v[2];}

    inline const vec3& operator+() const {return *this;}
    inline vec3 operator-() const {return vec3(-v[0], -v[1], -v[2]);}
    inline float operator[](int id) const {return v[id];}
    inline float& operator[](int id) {return v[id];}
    
    // inline vec3& operator=(const vec3 &v2) const {this->v[0] = v2[0]; this->v[1] = v2[1]; this->v[2] = v2[2];}
    inline vec3& operator+=(const vec3 &v2);
    inline vec3& operator-=(const vec3 &v2);
    inline vec3& operator*=(const vec3 &v2);
    inline vec3& operator/=(const vec3 &v2);

    inline vec3& operator*=(const float t);
    inline vec3& operator/=(const float t);

    inline float length() const{
        return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);}
    inline float squared_length() const {
        return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];}

    inline void normalize();
    inline vec3& normalized();

    float v[3];
};

inline vec3 operator+(const vec3 &v1, const vec3 &v2){
    return vec3(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1], v1.v[2] + v2.v[2]);
}

inline vec3 operator-(const vec3 &v1, const vec3 &v2){
    return vec3(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1], v1.v[2] - v2.v[2]);
}

inline vec3 operator*(const vec3 &v1, const vec3 &v2){
    return vec3(v1.v[0] * v2.v[0], v1.v[1] * v2.v[1], v1.v[2] * v2.v[2]);
}

inline vec3 operator/(const vec3 &v1, const vec3 &v2){
    return vec3(v1.v[0] / v2.v[0], v1.v[1] / v2.v[1], v1.v[2] / v2.v[2]);
}

inline vec3 operator*(float t, const vec3 &v2){
    return vec3( t * v2.v[0],  t * v2.v[1],  t * v2.v[2]);
}

inline vec3 operator*(const vec3 &v2, float t){
    return vec3( t * v2.v[0],  t * v2.v[1],  t * v2.v[2]);
}

inline vec3 operator/(const vec3 &v1, float t){
    return vec3( v1.v[0] / t,  v1.v[1] / t,  v1.v[2] / t);
}


inline float dot(const vec3 &v1, const vec3 &v2) {
    return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2];
}

inline vec3 cross(const vec3 &v1, const vec3 &v2) {
    return vec3(v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
    -(v1.v[0] * v2.v[2] - v1.v[2] * v2.v[0]),
    v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]);
}

inline vec3 normalized(vec3 ve) {
    return ve / ve.length();
}

inline std::istream& operator>>(std::istream &is, vec3 &t) {
    is >> t.v[0] >> t.v[1] >> t.v[2];
    return is;
}

inline std::ostream& operator<<(std::ostream &os, const vec3 &t){
    os << t.v[0] << " " << t.v[1] << " " << t.v[2];
    return os;
}