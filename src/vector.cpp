#include "../include/vector.h"

inline void vec3::normalize() {
    float k = 1.0 / sqrt(v[0] * v[0] + v[1] * v[1] + v[2] + v[2]);
    v[0] *= k;   v[1] *= k;   v[1] *= k; 
}

inline vec3& vec3::normalized() {
    float k = 1.0 / sqrt(v[0] * v[0] + v[1] * v[1] + v[2] + v[2]);
    return vec3(v[0] * k, v[1] * k, v[2] * k);
}

inline vec3& vec3::operator+=(const vec3 &v1) {
    v[0] += v1.v[0];
    v[1] += v1.v[1];
    v[2] += v1.v[2];
    return *this;
}

inline vec3& vec3::operator-=(const vec3 &v1) {
    v[0] -= v1.v[0];
    v[1] -= v1.v[1];
    v[2] -= v1.v[2];
    return *this;
}

inline vec3& vec3::operator*=(const vec3 &v1) {
    v[0] *= v1.v[0];
    v[1] *= v1.v[1];
    v[2] *= v1.v[2];
    return *this;
}

inline vec3& vec3::operator/=(const vec3 &v1) {
    v[0] /= v1.v[0];
    v[1] /= v1.v[1];
    v[2] /= v1.v[2];
    return *this;
}

inline vec3& vec3::operator*=(const float f) {
    v[0] *= f;
    v[1] *= f;
    v[2] *= f;
    return *this;
}

inline vec3& vec3::operator/=(const float f) {
    float k = 1.0/f;

    v[0] *= k;
    v[1] *= k;
    v[2] *= k;
    return *this;
}
// inline void vec3::normalize() {
//     float k = 1.0 / sqrt(v[0] * v[0] + v[1] * v[1] + v[2] + v[2]);
//     v[0] *= k;   v[1] *= k;   v[1] *= k; 
// }

// inline vec3& vec3::normalized() {
//     return v / v.length();
// }