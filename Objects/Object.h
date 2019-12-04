//
// Created by Jake Meegan on 26/11/2019.
//

#ifndef ASSIGNMENT_2_OBJECT_H
#define ASSIGNMENT_2_OBJECT_H


#include <glm/glm.hpp>
#include <gltypes.h>

class Object {
public:
    explicit Object(glm::vec3 position) : position(position){};

    virtual void update(const GLfloat &delta_time) = 0;
    virtual void draw() = 0;

    glm::vec3 position;
};


#endif //ASSIGNMENT_2_OBJECT_H
