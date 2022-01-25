#include "Sphere.h"

#include <algorithm>
#include <iostream>


float Sphere::intersect(const Ray& r) const
{

    Point3 ray_pos_transform = r.get_orig() - pos;




    float b = (r.get_dir() * ray_pos_transform);



    float discriminant = (b*b) + (radius*radius) - pow(ray_pos_transform.magnitude(),2);

    //ray doesn't intersect sphere if discriminant is < zero
    if(discriminant < 0.0f) {
        return -1;
    }
    else if (discriminant == 0.0f) {
        return (r.get_dir() * ray_pos_transform);
    }
    else {
        float t_minus = ((-b) - sqrt(discriminant));
        float t_plus = ((-b) + sqrt(discriminant));



        //if two intersections
        if(t_minus > 0 && t_plus >0) return std::min(t_minus, t_plus);

        if(t_minus < 0 && t_plus>0) return t_plus;
        if(t_plus<0 && t_minus>0) return t_minus;
    }


    return -1;
}