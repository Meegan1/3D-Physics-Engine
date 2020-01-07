//
// Created by Jake Meegan on 06/01/2020.
//

#ifndef ASSIGNMENT_2_PLANECOLLIDER_H
#define ASSIGNMENT_2_PLANECOLLIDER_H


#include "Collider.h"

class PlaneCollider : public Collider {
public:
    PlaneCollider(const glm::vec3 &position, GLfloat width, GLfloat height) : Collider(position), width(width), height(height) {}

    Collision collides(Collider &other) override;

    Collision collides(const SphereCollider &other) override;

    Collision collides(const PlaneCollider &other) override;

    glm::vec3 closestPoint(const glm::vec3 &point) override;

    GLfloat width, height;
};


#endif //ASSIGNMENT_2_PLANECOLLIDER_H
