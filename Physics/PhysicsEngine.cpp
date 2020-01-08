//
// Created by Jake Meegan on 24/11/2019.
//

#include "PhysicsEngine.h"

/*
 * Update objects
 */
void PhysicsEngine::update(GLfloat delta_time) {
    for(const auto& object : objects) {
        object->update(delta_time);

        if(object->hasRigidBody()) {
            object->rigidBody->collision(object, objects);
        }
    }
}

/*
 * Draw objects
 */
void PhysicsEngine::draw() {
    for(const auto& object : objects) {
        object->draw();
    }
}

/*
 * Reset all objects
 */
void PhysicsEngine::reset() {
    for(const auto& object : objects) {
        object->reset();
    }
}

/*
 * Add an object to the scene
 */
void PhysicsEngine::addObject(const std::shared_ptr<Object>& object) {
    if (object->hasRigidBody())
        object->rigidBody->setGravity(gravity);

    objects.emplace_back(object);
}

/*
 * Set gravity for scene
 */
void PhysicsEngine::setGravity(glm::vec3 g) {
    gravity = g;

    for(const auto& object : objects) {
        if (!object->hasRigidBody())
            continue;

        object->rigidBody->setGravity(g);
    }
}

/*
 * Get current gravity
 */
glm::vec3 PhysicsEngine::getGravity() {
    return gravity;
}

/*
 * Set wind/global force with a direction and strength
 */
void PhysicsEngine::setGlobalForce(const glm::vec3 &direction, GLfloat strength) {
    globalForce = direction * strength;

    for(const auto& object : objects) {
        if (!object->hasRigidBody())
            continue;

        object->rigidBody->setForce(globalForce);
    }
}

/*
 * Update wind/global force strength
 */
void PhysicsEngine::setGlobalForceStrength(GLfloat strength) {
    for(const auto& object : objects) {
        if (!object->hasRigidBody())
            continue;

        glm::vec3 normalForce = glm::normalize(globalForce);
        if(!glm::all(glm::isnan(normalForce)))
            object->rigidBody->setForce(glm::normalize(globalForce) * strength);
    }
}
