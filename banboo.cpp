#include <iostream>
#include <fstream>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "include/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "include/stb_image_write.h"
// using namespace std;
// #include "vector.h"
#include "include/ray.h"
#include "sphere.h"
#include "hitablelist.h"

// bool hit_sphere(const vec3& center, float radius, const ray& r, float &t){
//     vec3 oc = r.origin() - center;
//     float a = dot(r.direction(), r.direction());
//     float b = 2.0 * dot(oc, r.direction());
//     float c = dot(oc, oc) - radius * radius;
//     float discriminant = b * b - 4 * a * c;

//     if (discriminant < 0) return false;
//     else{
//         t = (-b -sqrt(discriminant)) / (2.0 * a);
//         return true;
//     }
// };

vec3 color(const ray& r, hitable * world) {
    hit_record rec;
    if (world->hit(r, 0.0, MAXFLOAT, rec)) {
        return 0.5 * vec3(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);
    }else{
        vec3 ndir = normalized(r.direction());
        float t = 0.5 *(ndir.y() + 1.0);
        return (1.0-t)*vec3(1.0) + t*vec3(0.5, 0.7, 1.0);
    }
    // float hit_dis;
    // if (hit_sphere(vec3(0,0,-1), 0.5, r, hit_dis)){
    //     vec3 co = (normalized(r.point_at_paramter(hit_dis) - vec3(0,0,-1)) + vec3(1.0))/2.0;
    //     // std::cout<<"color: "<<co<<"."<<std::endl;
    //     return co;
    // }
        
    vec3 normalized_dir = normalized(r.direction());
    float t = 0.5 * (normalized_dir.y() + 1.0);
    // std::cout << t << std::endl;
    vec3 ret = (1.0 - t) * vec3(1.0) + t * vec3(0.5, 0.7, 1.0);
    // std::cout << ret << std::endl;
    return ret;
};


int main(){
    int nx = 200;
    int ny = 100;
    std::ofstream oss;
    // std::cout<<"load image1.ppm"<<std::endl;
    oss.open("../image1.ppm");
    oss << "P3\n" << nx << " " << ny << "\n255\n";

    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    hitable *list[2];
    list[0] = new sphere(vec3(0,0,-1), 0.5);
    list[1] = new sphere(vec3(0,-100.5,-1), 100);
    hitable *world = new hitable_list(list, 2);

    for (int j = ny-1 ; j >= 0 ; j--){
        float v = float(j) / float(ny);
        for (int i = 0 ; i < nx ; i++){
            // float r = float(i) / float(nx);
            // float g = float(j) / float(ny);
            // float b = 0.5;
            // vec3 rgb( float(j) / float(ny), float(i) / float(nx),0.5);
            float u = float(i) / float(nx);
            const ray r(origin, lower_left_corner + u * horizontal + v * vertical);
            vec3 rgb = color(r, world);
            // std::cout << rgb << std::endl;
            int ir = int(255.99 * rgb.r());
            int ig = int(255.99 * rgb.g());
            int ib = int(255.99 * rgb.b());
            oss << ir << " " << ig << " " << ib << "\n";
        }
    }
    // int x,y,n;
    // unsigned char *data = stbi_load("../foo.jpeg", &x, &y, &n, 0);
    // std::cout<<"loaded:"<<"width: "<<x<<"height: "<<y<<std::endl;
    
    // // std::cout<<failure_resaon<<std::endl;
    // stbi_write_png("../foo_out.png", x, y, 3, data, 0);
    // std::string failure_resaon = stbi_failure_reason();
    // std::cout<<failure_resaon<<std::endl;
    // std::cout<<"wroted"<<std::endl;
}