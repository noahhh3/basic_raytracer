#ifndef ___PLANE_H___
#define ___PLANE_H___

#include "SceneObject.h"

class Plane : public SceneObject
{
    public:
        Plane() {}
        Plane(Point3 p, Vec3 n, Color& c, Shader* s) : SceneObject(c,s), pos(p), norm_dir(n) {}

        //copy constructor tbd
        Plane(Plane& copy) {}

        ~Plane() {}

        virtual float intersect(const Ray& r) const;
        //virtual bool has_intersection(const Ray& r) const;



        virtual Vec3 normal(Point3 p) const { return norm_dir.normal(); }


    private:
        Point3 pos;
        Vec3 norm_dir;


};

#endif