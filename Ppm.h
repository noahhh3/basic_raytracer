#ifndef ___PPM_H___
#define ___PPM_H___

#include <fstream>
#include <string>
#include "ImagePlane.h"

class Ppm
{
    public:
        Ppm() {}
        void write_to_ppm(std::string file_name, ImagePlane& img);


    private:
        std::ofstream out_file;

};



#endif