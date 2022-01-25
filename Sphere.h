#ifndef ___SPHERE_H___
#define ___SPHERE_H___

#include "SceneObject.h"

class Sphere : public SceneObject
{
    public:
        Sphere() {}
        Sphere(Point3 p, double r, Color& c, Shader* s) : SceneObject(c,s), pos(p), radius(r) {}

        //copy constructor tbd
        Sphere(Sphere& copy) {}

        ~Sphere(){}

        virtual float intersect(const Ray& r) const;
        //virtual bool has_intersection(const Ray& r) const {}


        virtual Vec3 normal(Point3 p) const { return Vec3((p - pos).normal()); }


    private:
        //center position of sphere
        Point3 pos;

        double radius;

};

#endif