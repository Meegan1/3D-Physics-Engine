//
// Created by Jake Meegan on 24/11/2019.
//

#include "PhysicsEngine.h"

void PhysicsEngine::update(GLfloat delta_time) {
    for(const auto& object : objects) {
        object->update(delta_time);

        if(object->hasRigidBody()) {
            object->rigidBody->collision(object, objects);
        }
    }
}

void PhysicsEngine::draw() {
    for(const auto& object : objects) {
        object->draw();
    }
}


void PhysicsEngine::reset() {
    for(const auto& object : objects) {
        object->reset();
    }
}

void PhysicsEngine::addObject(const std::shared_ptr<Object>& object) {
    if (object->hasRigidBody())
        object->rigidBody->setGravity(gravity);

    objects.emplace_back(object);
}

void PhysicsEngine::setGravity(glm::vec3 g) {
    gravity = g;

    for(const auto& object : objects) {
        if (!object->hasRigidBody())
            continue;

        object->rigidBody->setGravity(g);
    }
}