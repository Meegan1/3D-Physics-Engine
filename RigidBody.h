//
// Created by Jake Meegan on 24/11/2019.
//

#ifndef ASSIGNMENT_2_RIGIDBODY_H
#define ASSIGNMENT_2_RIGIDBODY_H


#include <gltypes.h>
#include <glm/glm.hpp>

class RigidBody {
public:
    explicit RigidBody(glm::vec3 position) : position(position) {};

    virtual void update(GLfloat delta_time) = 0;
    virtual void draw() = 0;
    glm::vec3 position;
};


#endif //ASSIGNMENT_2_RIGIDBODY_H
