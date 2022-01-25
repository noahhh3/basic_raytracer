#include "Camera.h"

#include <iostream>

Camera::Camera(Point3 eye, Vec3 forward, Vec3 up_dir, double h_fov, double ar, const ImagePlane& img)
              : eye_pos(eye), view_dir(forward), cam_up_dir(up_dir) , horiz_fov(h_fov)
               , aspect_ratio(ar), img_plane(img)
{
    //using horizontal angle of view calculates the distance between eye and img plane
    focal_length = 1/(tan(horiz_fov/2));



    right = (up_dir^view_dir).normal();
}

Ray Camera::view(float x, float y) 
{
    //convert x,y coords to u,v (0,0) is center of image plane and middle of eye
    //x,y coords in NDC space, which is [0-1] and rasterized space is [-1-1]
    float u = ((2*x / img_plane.get_width()) - 1) * tan(horiz_fov/2);
    float v = ((2*y / img_plane.get_height()) - 1) * (tan(horiz_fov/2)/aspect_ratio);

    Point3 pixel_3d_coord = u * right + v * cam_up_dir;

    Ray r (eye_pos, (pixel_3d_coord + view_dir) / (pixel_3d_coord + view_dir).magnitude());


    return (r);
}