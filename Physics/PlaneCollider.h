//
// Created by Jake Meegan on 06/01/2020.
//

#ifndef ASSIGNMENT_2_PLANECOLLIDER_H
#define ASSIGNMENT_2_PLANECOLLIDER_H


#include "Collider.h"

class PlaneCollider : public Collider {
public:
    PlaneCollider(const glm::vec3 &position) : Collider(position) {}

    Collision collides(Collider &other) override;

    Collision collides(const SphereCollider &other) override;

    Collision collides(const PlaneCollider &other) override;
};


#endif //ASSIGNMENT_2_PLANECOLLIDER_H
