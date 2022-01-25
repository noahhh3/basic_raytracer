#ifndef ___POINTLIGHT_H___
#define ___POINTLIGHT_H___

#include "Vec3.h"
#include "Lights.h"

class PointLight : public Light
{
    public:
        PointLight() {};
        PointLight(Point3 Xl, Color C) : Light(Xl, C) {};

        //Point3 get_pos() const { return pos_l; }
       // Color get_color() const { return cl; }

    private:
        //Point3 pos_l;
        //Color cl;
};

#endif