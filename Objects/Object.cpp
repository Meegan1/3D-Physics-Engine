//
// Created by Jake Meegan on 07/01/2020.
//

#include "Object.h"

void Object::update(const GLfloat &delta_time) {
    if(!hasRigidBody())
        return;

    rigidBody->updateVelocity(delta_time);
    position += rigidBody->getVelocity() * delta_time;
}

void Object::updateCollider() {
    if(collider != nullptr)
        collider->position = position;
}
