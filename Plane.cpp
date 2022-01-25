#include "Plane.h"

#include <iostream>

float Plane::intersect(const Ray& r) const
{
    
    //denom
    float denom = (r.get_dir() * norm_dir);
    
    //check here first to possibly reduce num optimizations
    if(denom == 0.0f) {
        return -1;
    }


    float num = ((pos- r.get_orig()) * norm_dir);


    //num represents how far away the point on plane and ray starts
    //denom represents how quickly the ray gets to the point
    float t = (num) / (denom);


    //either ray is perfectly parallel to plane or t goes in negative direction
    return t;

}
