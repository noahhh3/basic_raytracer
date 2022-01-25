#include "Lambertian.h"


Color Lambertian::eval(Ray& light_ray, const Color& cl, Ray& cam_ray, Vec3& normal)
{


    float R_lamb = std::max(((-normal * light_ray.get_dir())/M_PI), 0.0);





    Color mix;
    mix.r = cl.r * R_lamb;
    mix.g = cl.g * R_lamb;
    mix.b = cl.b * R_lamb;




    return mix;
}