//
// Created by Jake Meegan on 24/11/2019.
//

#include "PhysicsEngine.h"

void PhysicsEngine::update(GLfloat delta_time) {
    for(const auto& object : objects) {
        object->update(delta_time);
    }
}

void PhysicsEngine::draw() {
    for(const auto& object : objects) {
        object->draw();
    }
}

void PhysicsEngine::addObject(const std::shared_ptr<RigidBody>& object) {
    object->setGravity(gravity);
    objects.emplace_back(object);
}

void PhysicsEngine::setGravity(glm::vec3 g) {
    gravity = g;

    for(auto &body : objects) {
        body->setGravity(g);
    }
}
