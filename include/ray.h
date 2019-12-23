#ifndef RAY_H
#define RAY_H
#include "vector.h"

class ray
{
    public:
    ray() {}
    ray(const vec3& o, const vec3& d) {pos = o; dir = d; }

    vec3 origin() const { return pos; }
    vec3 direction() const { return dir; }
    vec3 point_at_paramter(float t) const { return pos + t * dir; }

    vec3 dir;
    vec3 pos;
};
#endif