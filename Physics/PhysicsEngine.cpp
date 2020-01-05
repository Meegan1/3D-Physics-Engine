//
// Created by Jake Meegan on 24/11/2019.
//

#include "PhysicsEngine.h"

void PhysicsEngine::update(GLfloat delta_time) {
    for(const auto& object : objects) {
        object->update(delta_time);
    }

    for(const auto& body : rigidBodies) {
        body->update(delta_time);

        for(const auto& object : objects) {
            body->collision(glm::vec3(0, object->position.y, 0));
        }
    }
}

void PhysicsEngine::draw() {
    for(const auto& object : objects) {
        object->draw();
    }

    for(const auto& body : rigidBodies) {
        body->draw();
    }
}


void PhysicsEngine::reset() {
    for(const auto& body : rigidBodies) {
        body->reset();
    }
}

void PhysicsEngine::addObject(const std::shared_ptr<Object>& object) {
    objects.emplace_back(object);
}

void PhysicsEngine::addRigidBody(const std::shared_ptr<RigidBody>& rigidBody) {
    rigidBody->setGravity(gravity);
    rigidBodies.emplace_back(rigidBody);
}

void PhysicsEngine::setGravity(glm::vec3 g) {
    gravity = g;

    for(auto &body : rigidBodies) {
        body->setGravity(g);
    }
}