#ifndef ___SHADER_H___
#define ___SHADER_H___


#include "Vec3.h"
#include "Ray.h"



class Shader
{

    public:
        Shader();
        Shader(float r) : l_reflectivity(r){};

        virtual ~Shader() {}
        

        virtual Color eval(Ray& l, const Color& cl, Ray& cam_ray, Vec3& norm) = 0;




    private:
        //lambertian reflectivity 
        float l_reflectivity;

};


#endif