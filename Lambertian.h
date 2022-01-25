#ifndef ___LAMBERTIAN_H___
#define ___LAMBERTIAN_H___

#include "Shader.h"
#include "Ray.h"
#include "Vec3.h"

#include <algorithm>




class Lambertian : public Shader
{

    public:
        Lambertian();
        Lambertian(float r) : Shader(r) {};

        ~Lambertian() {}

        virtual Color eval(Ray& light_ray, const Color& cl, Ray& cam_ray, Vec3& normal);

    private:




};

#endif