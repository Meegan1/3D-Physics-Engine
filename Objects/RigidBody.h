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
    explicit RigidBody(glm::vec3 position, float mass, float restitution_coefficient) : Object(position), mass(mass),
                                                                                        RESTITUTION_COEFFICIENT(restitution_coefficient),
                                                                                        o_position(position) {};

    void reset() {
        position = o_position;
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

    virtual void collision(const glm::vec3 &intersection) = 0;

    float mass;
    glm::vec3 o_position{0, 0, 0}; // original position
    glm::vec3 force{0, 0, 0};
    glm::vec3 gravity{0, 0, 0};
    glm::vec3 acceleration{0, 0, 0};
    glm::vec3 velocity{0, 0, 0};

    GLfloat RESTITUTION_COEFFICIENT = 1;
};


#endif //ASSIGNMENT_2_RIGIDBODY_H
