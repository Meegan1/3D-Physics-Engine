//
// Created by Jake Meegan on 24/11/2019.
//

#ifndef ASSIGNMENT_2_RIGIDBODY_H
#define ASSIGNMENT_2_RIGIDBODY_H


#include <gltypes.h>
#include <glm/glm.hpp>
#include <QElapsedTimer>
#include <vector>

#include "../Objects/Object.h"
#include "Collider.h"
#include "qdebug.h"

class RigidBody {
public:
    explicit RigidBody(const glm::vec3 &position, float mass, float restitution_coefficient) : mass(mass),
                                                                                        RESTITUTION_COEFFICIENT(restitution_coefficient),
                                                                                        o_position(position) {};

    void reset() {
        force = glm::vec3(0);
        velocity = glm::vec3(0);
    }

    void setGravity(const glm::vec3 &g) {
        gravity = g;
    }

    void setForce(const glm::vec3 &f) {
        force = f;
        acceleration = ((force) / mass);
    }

    void addForce(const glm::vec3 &f) {
        force += f;
        acceleration = ((force) / mass);
    }

    glm::vec3 getForce() {
        return force;
    }

    void setVelocity(const glm::vec3 &v) {
        velocity = v;
    }

    void updateVelocity(const GLfloat &delta_time) {
        velocity += (acceleration + gravity) * delta_time;
    }

    glm::vec3 getVelocity() {
        return velocity;
    }

    GLfloat getRC() {
        return RESTITUTION_COEFFICIENT;
    }

    void collision(std::shared_ptr<Object> curr_object, const std::vector<std::shared_ptr<Object>> &objects) {
        for(const auto& object : objects) {
            if(curr_object == object) // ignore if same object
                continue;

            if(curr_object->collider == nullptr || object->collider == nullptr) // continue if no collider
                continue;

            curr_object->updateCollider();
            object->updateCollider();

            Collision collision = curr_object->collider->collides(*object->collider);
            if(collision.hasCollided) {
                curr_object->position = collision.point + (collision.offset * -collision.direction);

                float d = glm::dot(velocity, collision.normal);
                float j = glm::max(-(1 + getRC()) * d, 0.0f);
                velocity += j * collision.normal;
            }
        }
    };

    float mass;
    glm::vec3 o_position{0, 0, 0}; // original position
    glm::vec3 force{0, 0, 0};
    glm::vec3 gravity{0, 0, 0};
    glm::vec3 acceleration{0, 0, 0};
    glm::vec3 velocity{0, 0, 0};

    GLfloat RESTITUTION_COEFFICIENT = 1;
};


#endif //ASSIGNMENT_2_RIGIDBODY_H
