#ifndef ___LIGHTS_H___
#define ___LIGHTS_H___

#include "Vec3.h"


class Light
{
    public:
        Light() {};
        Light(Point3 p, Color c) : pos(p), C(c) {};

        
        Point3 get_pos() const { return pos; }
        Color get_color() const  { return C; }


    private:
        Point3 pos;
        Color C;

};

#endif