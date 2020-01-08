//
// Created by Jake Meegan on 26/11/2019.
//

#ifndef ASSIGNMENT_2_OBJECT_H
#define ASSIGNMENT_2_OBJECT_H

#include <glm/glm.hpp>
#include <gltypes.h>
#include "memory"


class Collider;
class RigidBody;

/*
 * Base class for objects
 */
class Object {
public:
    explicit Object(glm::vec3 position) : position(position){};

    virtual void update(const GLfloat &delta_time);
    virtual void draw() = 0;

    virtual void reset() {}

    bool hasRigidBody() {
        return rigidBody != nullptr;
    }

    void updateCollider();

    glm::vec3 position;
    std::shared_ptr<RigidBody> rigidBody;
    Collider *collider;
    float frictionCoefficient{0};
};

#include "../Physics/RigidBody.h"
#include "../Physics/Collider.h"

#endif //ASSIGNMENT_2_OBJECT_H
