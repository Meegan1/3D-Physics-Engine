//
// Created by Jake Meegan on 05/01/2020.
//

#ifndef ASSIGNMENT_2_SPHERE_H
#define ASSIGNMENT_2_SPHERE_H


#include "RigidBody.h"

class Sphere : public RigidBody {
public:
    explicit Sphere(glm::vec3 position, float mass, float restitution_coefficient, float radius) : RigidBody(position, mass,
                                                                                               restitution_coefficient),
                                                                                               radius(radius)
                                                                                               {};

    void collision(glm::vec3 &position, const glm::vec3 &intersection) override;

    float radius;
};


#endif //ASSIGNMENT_2_SPHERE_H
