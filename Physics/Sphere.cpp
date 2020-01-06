//
// Created by Jake Meegan on 05/01/2020.
//

#include "Sphere.h"

void Sphere::collision(glm::vec3 &position, const glm::vec3 &intersection) {
    if(position.y <= intersection.y + radius) {
        velocity.y = (-velocity.y * getRC());
        position.y = intersection.y + radius;
    }
}
