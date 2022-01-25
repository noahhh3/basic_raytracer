#include "Headers.h"


void init_cam_vals(Point3& eye, Vec3& view, Vec3& up_dir, double& h_fov)
{
    //set eye pos
    double cam_x = 0, cam_y = 0, cam_z = 0;
    eye.set(cam_x, cam_y, cam_z);

    //set view direction
    double view_x = 0, view_y = 0;
    double view_z = 1;
    view.set(view_x, view_y, view_z);

    //set cam up direction
    double up_x = 0, up_z = 0;
    double up_y = 1;
    up_dir.set(up_x, up_y, up_z);

    //set horizontal fov
    h_fov = M_PI/2; //90 fov in radians

}


int main (int argc, const char* argv[])
{
    int width = 1024;
    int height = 768;


    //setup image plane
    ImagePlane img(width, height);

    //setup camera
    Point3 eye_pos;
    Vec3 view_dir, up_dir;
    double h_fov;
    init_cam_vals(eye_pos, view_dir, up_dir,h_fov);
    Camera cam(eye_pos, view_dir, up_dir, h_fov, ((float)width/(float)height), img);






    //setup scene
    Point3 l(-1,-1,7);
    Color lc;
    lc.r = 2;
    lc.g = 2;
    lc.b = 2;
    Light* point_light = new PointLight(l, lc);

    float r = 0;
    Shader* lamb = new Lambertian(r);


    Point3 pos0 (0,2,0);
    Vec3 norm0 (0,-1,0);
    Color c0;
    c0.r = 1;
    c0.g = 1;
    c0.b = 1;
    SceneObject* plane0 = new Plane(pos0, norm0, c0, lamb);

    Point3 pos2 (0,-2,0);
    Vec3 norm2 (0,1,0);
    Color c2;
    c2.r = 1;
    c2.g = 1;
    c2.b = 1;
    SceneObject* plane1 = new Plane(pos2, norm2, c2, lamb);

    Point3 pos3 (-2,0,0);
    Vec3 norm3 (1,0,0);
    Color c3;
    c3.r = 1;
    c3.g = 0;
    c3.b = 0;
    SceneObject* plane2 = new Plane(pos3, norm3, c3, lamb);

    Point3 pos4 (2,0,0);
    Vec3 norm4 (-1,0,0);
    Color c4;
    c4.r = 0;
    c4.g = 1;
    c4.b = 0;
    SceneObject* plane3 = new Plane(pos4, norm4, c4, lamb);

    Point3 pos5 (0,0,10);
    Vec3 norm5 (0,0,-1);
    Color c5;
    c5.r = 1;
    c5.g = 1;
    c5.b = 1;
    SceneObject* plane4 = new Plane(pos5, norm5, c5, lamb);




    Point3 pos1 (1.1, 1.25, 7);
    double radius = 1;
    Color c1;
    c1.r = 0.5;
    c1.g = 0.5;
    c1.b = 1;
    SceneObject* sphere0 = new Sphere(pos1, radius, c1, lamb);

    SceneContent scene;
    scene.obj_add(plane0);
    scene.obj_add(plane1);
    scene.obj_add(plane2);
    scene.obj_add(plane3);
    scene.obj_add(plane4);
    scene.obj_add(sphere0);
    scene.light_add(point_light);








    //setup ppm
    Ppm render;

    Color r_color;

    //perform raytrace
    for(int i=0; i<img.get_width(); i++) {
        for(int j=0; j<img.get_height(); j++) {
            Ray pixel_ray = cam.view(i,j);
            r_color = trace(pixel_ray, scene);
            img.set_color(i,j,r_color);
        }
    }


    render.write_to_ppm("scene.ppm", img);


    std::cerr << "Writing to file\n" << std::endl; 



    return 0;
}