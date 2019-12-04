//
// Created by Jake Meegan on 24/11/2019.
//

#ifndef ASSIGNMENT_2_RIGIDBODY_H
#define ASSIGNMENT_2_RIGIDBODY_H


#include <gltypes.h>
#include <glm/glm.hpp>
#include <QElapsedTimer>
#include "Object.h"

class RigidBody : public Object {
public:
    explicit RigidBody(glm::vec3 position, float mass) : Object(position), mass(mass) {};

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

    void updateVelocity(const GLfloat &delta_time) {
        velocity += (acceleration + gravity) * delta_time;
        velocityStasisCheck();
    }

    glm::vec3 getVelocity() {
        return velocity;
    }

    void velocityStasisCheck() {
        if(velocity.x <= V_EPSILON && velocity.x >= V_EPSILON) {
            velocity.x = 0;
        }
        if(velocity.y <= V_EPSILON && velocity.y >= V_EPSILON) {
            velocity.y = 0;
        }
        if(velocity.z <= V_EPSILON && velocity.z >= V_EPSILON) {
            velocity.z = 0;
        }
    }

    GLfloat getRC() {
        return RESTITUTION_COEFFICIENT;
    }

protected:
    float mass;
    glm::vec3 force{0, 0, 0};
    glm::vec3 gravity{0, 0, 0};
    glm::vec3 acceleration{0, 0, 0};
    glm::vec3 velocity{0, 0, 0};

    GLfloat V_EPSILON = 0.01f;
    GLfloat RESTITUTION_COEFFICIENT = 1;
};


#endif //ASSIGNMENT_2_RIGIDBODY_H
