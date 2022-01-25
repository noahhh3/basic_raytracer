#ifndef ___SCENEOBJECT_H___
#define ___SCENEOBJECT_H___

#include "Vec3.h"
#include "Ray.h"
#include "Shader.h"

class SceneObject
{
    public:
        SceneObject();

        //add shader param
        SceneObject(Color& c, Shader* s) : C(c), S(s) {}

        //copy constructor tbd
        SceneObject(SceneObject& copy) {}

        //add for lambertian shader thing
        Color get_color() { return C; }


        //set an objects Shader* to be lambertian or other shader type
        void set_shader();


        Color get_shader(Ray& l, const Color& cl, Ray& cam_ray, Point3 pixel_p) const { 
            Vec3 norm = normal(pixel_p);
            return S->eval(l, cl, cam_ray, norm); 
        }

        virtual ~SceneObject(){}


        //if use as bool -1 return value for no intersection
        virtual float intersect(const Ray& r) const = 0;
        //virtual bool has_intersection(const Ray& r) const = 0;


        //get normal at point
        virtual Vec3 normal(Point3 P) const = 0;


        
    private:
        Color C;
        Shader* S;

        //maybe add some sort of define for if a sceneobj gets lambertian or phong shading



};

#endif