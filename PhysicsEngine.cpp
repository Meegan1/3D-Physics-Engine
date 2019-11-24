//
// Created by Jake Meegan on 24/11/2019.
//

#include "PhysicsEngine.h"

std::vector<std::shared_ptr<RigidBody>> PhysicsEngine::objects;

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
    objects.emplace_back(object);
}