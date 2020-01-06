//
// Created by Jake Meegan on 24/11/2019.
//

#include "PhysicsEngine.h"

void PhysicsEngine::update(GLfloat delta_time) {
    for(const auto& object : objects) {
        object->update(delta_time);

        if(object->rigidBody != nullptr) {
            for (const auto &other : objects) {
                if(object == other)
                    continue;

                object->rigidBody->collision(object->position, glm::vec3(0, other->position.y, 0));
            }
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
    objects.emplace_back(object);
}

void PhysicsEngine::setGravity(glm::vec3 g) {
    gravity = g;

    for(const auto& object : objects) {
        object->rigidBody->setGravity(g);
    }
}