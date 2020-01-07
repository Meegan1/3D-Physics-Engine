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

    static void resolveCollision(const std::shared_ptr<Object> &object, const std::shared_ptr<Object> &other) {
        Collision collision_a = object->collider->collides(*other->collider);
        Collision collision_b = other->collider->collides(*object->collider);

        if(collision_a.hasCollided && collision_b.hasCollided) {
            float d_a = glm::dot(object->rigidBody->velocity, collision_a.normal);
            float d_b = glm::dot(other->rigidBody->velocity, collision_b.normal);

            float m_a = 2*(other->rigidBody->mass) / (object->rigidBody->mass + other->rigidBody->mass);
            float m_b = 2*(object->rigidBody->mass) / (object->rigidBody->mass + other->rigidBody->mass);

            float rc = glm::min(object->rigidBody->getRC(), other->rigidBody->getRC());

            float j_a = glm::max(-(1 + rc * m_a) * d_b, 0.0f);
            float j_b = glm::max(-(1 + rc * m_b) * d_a, 0.0f);

            object->rigidBody->velocity += j_a * collision_a.normal;
            other->rigidBody->velocity += j_b * collision_b.normal;

            object->position = collision_a.point + (collision_a.offset * -collision_a.direction);
            other->position = collision_b.point + (collision_b.offset * -collision_b.direction);
        }
    }

    void collision(const std::shared_ptr<Object> &curr_object, const std::vector<std::shared_ptr<Object>> &objects) {
        for(const auto& object : objects) {
            if(curr_object == object) // ignore if same object
                continue;

            if(curr_object->collider == nullptr || object->collider == nullptr) // continue if no collider
                continue;

            curr_object->updateCollider();
            object->updateCollider();

            if(object->hasRigidBody())
                resolveCollision(curr_object, object);
            else {
                Collision collision = curr_object->collider->collides(*object->collider);
                if (collision.hasCollided) {
                    float d = glm::dot(curr_object->rigidBody->velocity, collision.normal);

                    float j = glm::max(-(1 + curr_object->rigidBody->getRC()) * d, 0.0f);

                    velocity += j * collision.normal;

                    // apply friction
                        glm::vec3 friction = velocity - glm::dot(velocity, collision.normal) * collision.normal;
                        glm::vec3 direction = glm::normalize(friction);
                        if(!glm::all(glm::isnan(direction)))
                            velocity -= direction * 0.005f;

                    curr_object->position = collision.point + (collision.offset * -collision.direction);
                }
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
