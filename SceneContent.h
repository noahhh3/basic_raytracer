#ifndef ___SCENECONTENT_H___
#define ___SCENECONTENT_H___

#include "SceneObject.h"
#include "PointLight.h"
#include <vector>
#include <memory>

class SceneContent
{
    public:
        SceneContent() { size = 0; }
        ~SceneContent() {}

        void obj_add(SceneObject* obj) { objects.push_back(obj); size++;}

        void light_add(Light* l) { lights.push_back(l); size++;}
        


        SceneObject* obj_at(int i) { return objects.at(i); }

        Light* light_at(int i) { return lights.at(i); }


        
        
        int num_objects() { return objects.size(); }
        int num_lights() { return lights.size(); }
        int num_elements() { return size; }


        

    private:
        std::vector<SceneObject*> objects;

        std::vector<Light*> lights;


        int size;
};


#endif