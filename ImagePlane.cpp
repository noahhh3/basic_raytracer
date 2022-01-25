#include "ImagePlane.h"

#include <iostream>

Color ImagePlane::get_color(int i, int j) const
{
    Color ret; // return color struct
    int ip = i + Nx * j; //used to index image stored in 1-Dimensional array

    ret.r = data[ip].r;
    ret.g = data[ip].g;
    ret.b = data[ip].b;

    return ret;
}


Color ImagePlane::get_color_out(int ip) const
{
    Color ret;

    ret.r = data[ip].r;
    ret.g = data[ip].g;
    ret.b = data[ip].b;

    return ret;

}


void ImagePlane::set_color(int i, int j, const Color& c) 
{
    int ip = i + Nx * j; //used to index image stored in 1-Dimensional array

    data[ip].r = c.r;
    data[ip].g = c.g;
    data[ip].b = c.b;
}