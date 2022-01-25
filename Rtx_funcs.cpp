#include "Rtx_funcs.h"
#include <iostream>

Color trace(const Ray& r, SceneContent& scene)
{

    //initialize for if ray doesn't intersect, color is black
    float t = INFINITY;
    Color obj_c;
    obj_c.r = 0;
    obj_c.g = 0;
    obj_c.b = 0;

    int intersect_obj = -1;


    for(int i=0; i<scene.num_objects(); i++) {
        
        //new intersection calc
        float t_int = scene.obj_at(i)->intersect(r);
        if(t_int>0) {
            float temp = t;
            t = std::min(t_int , t);
            if(t < temp) {  
                intersect_obj = i;
                obj_c = scene.obj_at(i)->get_color();
            } 
        }
    }


    Color shader;
    shader.r = shader.g = shader.b = 0;
    //if ray intersects object
    if(intersect_obj > -1) {

        //check if intersected objects is in light or not
 
        for(int i=0; i<scene.num_lights(); i++) {

            Point3 light_pos = scene.light_at(i)->get_pos();
            Color light_color = scene.light_at(i)->get_color();

            //check to see if the light ray from point light to pixel position intersects any other objects in the scene
            //get pixel pos and do light pos - pixel pos for direction vector from pixel to light
            Point3 pixel_pos = r.at(t);

            //from pixel to light

            //from light to pixel
            Ray l(light_pos, (pixel_pos - light_pos).normal());


            Ray view (r.get_orig(), r.get_dir().normal());
            
            
            Color temp = scene.obj_at(intersect_obj)->get_shader(l, light_color, view, pixel_pos);
                    

            shader.r += temp.r;
            shader.g += temp.g;
            shader.b += temp.b;

        }
    }



    obj_c.r *= shader.r;
    obj_c.g *= shader.g;
    obj_c.b *= shader.b;


    return obj_c;

}