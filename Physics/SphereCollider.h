//
// Created by Jake Meegan on 05/01/2020.
//

#ifndef ASSIGNMENT_2_SPHERECOLLIDER_H
#define ASSIGNMENT_2_SPHERECOLLIDER_H


#include "RigidBody.h"
#include "../Objects/Plane.h"
#include "Collider.h"

class SphereCollider : public Collider {
public:
    explicit SphereCollider(const glm::vec3 &position, float radius) : Collider(position), radius(radius) {};

    Collision collides(Collider &other) override;

    glm::vec3 closestPoint(const glm::vec3 &point) override;

    float radius;

    Collision collides(const PlaneCollider &other) override;
    Collision collides(const SphereCollider &other) override;
};


#endif //ASSIGNMENT_2_SPHERECOLLIDER_H
