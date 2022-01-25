#ifndef ___IMAGEPLANE_H___
#define ___IMAGEPLANE_H___

#include "Vec3.h"
#include <vector>

class ImagePlane
{
    public:
        ImagePlane() { Nx = Ny = 0; }
        ImagePlane(int width, int height) : Nx(width), Ny(height)
        {
            data.resize(Nx*Ny);
        }

        Color get_color(int i, int j) const;
        Color get_color_out(int ip) const;


        int get_width() { return Nx; }
        int get_height() { return Ny; }

        void set_color(int i, int j, const Color& c);


    private:
        //image plane width & height
        int Nx, Ny;

        
        //pixel data for image plane (Nx * Ny * (optional)num_channels)
        std::vector<Color> data;

};


#endif