//
// Created by Jake Meegan on 26/11/2019.
//

#ifndef ASSIGNMENT_2_OBJECT_H
#define ASSIGNMENT_2_OBJECT_H


#include <glm/glm.hpp>
#include <gltypes.h>
#include "../Physics/RigidBody.h"

class Object {
public:
    explicit Object(glm::vec3 position) : position(position){};

    virtual void update(const GLfloat &delta_time) = 0;
    virtual void draw() = 0;

    virtual void reset() {}

    glm::vec3 position;
    std::shared_ptr<RigidBody> rigidBody;
};


#endif //ASSIGNMENT_2_OBJECT_H
