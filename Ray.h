#ifndef ___RAY_H___
#define ___RAY_H___

#include "Vec3.h"


class Ray 
{
    public:
        //default constructor
        Ray() {}
        
        Ray(const Point3 o, const Vec3 d) : origin(o), dir(d) {}
       

        //definition for ray line
        Point3 at(float t) const {
            return(origin + t*dir);
        }


        Vec3 get_dir () const  { return dir; }
        Point3 get_orig () const { return origin; }



    private:
        Point3 origin;
        Vec3 dir;

};


#endif