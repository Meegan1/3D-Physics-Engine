//
// Created by Jake Meegan on 24/11/2019.
//

#ifndef ASSIGNMENT_2_RIGIDBODY_H
#define ASSIGNMENT_2_RIGIDBODY_H


#include <gltypes.h>
#include <glm/glm.hpp>
#include <QElapsedTimer>
#include "Object.h"

class RigidBody : public Object {
public:
    explicit RigidBody(glm::vec3 position) : Object(position), gravity(0, 0, 0) {};

    void setGravity(glm::vec3 g) {
        gravity = g;
    }
    glm::vec3 gravity;
    QElapsedTimer timer;
};


#endif //ASSIGNMENT_2_RIGIDBODY_H
