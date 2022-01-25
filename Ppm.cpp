#include "Ppm.h"
#include "ImagePlane.h"


void Ppm::write_to_ppm(std::string out, ImagePlane& img)
{
    out_file.open(out);

    out_file << "P3\n" << img.get_width() << " " << img.get_height() << "\n255\n";

    Color c;
    for (int i=0; i<img.get_width()*img.get_height(); i++) {
        c = img.get_color_out(i);
        out_file << (int)(c.r*255) << " " << (int)(c.g*255) << " " << (int)(c.b*255) << "\n";
    }

    out_file.close();
}