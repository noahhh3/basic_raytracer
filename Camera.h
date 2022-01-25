#ifndef ___CAMERA_H___
#define ___CAMERA_H___

#include "Vec3.h"
#include "Ray.h"
#include "ImagePlane.h"

class Camera
{
    public:
        Camera() {}

        //up direction vector points in direction camera considers up, usually (0,1,0)
        Camera(Point3 eye, Vec3 view, Vec3 up, double h_fov, double ar, const ImagePlane& img);

        //returns ray direction from specific x,y pixel
        Ray view (float x, float y);

        Point3 origin() const { return eye_pos; }



    private:
        Point3 eye_pos; //camera origin aka origin or aperture the (0,0) of the aperture hole
        
        Vec3 view_dir, cam_up_dir, right;
        
        double focal_length; //distance from eye to image plane

        double horiz_fov;

        double aspect_ratio;

        ImagePlane img_plane;


};



#endif