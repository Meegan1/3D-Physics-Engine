//
// Created by Jake Meegan on 06/01/2020.
//

#ifndef ASSIGNMENT_2_COLLIDER_H
#define ASSIGNMENT_2_COLLIDER_H

#include "glm/glm.hpp"
#include "gl.h"

struct Collision {
    GLboolean hasCollided;
    GLfloat offset;

    Collision(GLboolean hasCollided) : hasCollided(hasCollided), offset(0) {}
    Collision(GLboolean hasCollided, GLfloat offset) : hasCollided(hasCollided), offset(offset) {}
};

class SphereCollider;
class PlaneCollider;

class Collider {
public:
    Collider(const glm::vec3 &position) : position(position) {}
    virtual Collision collides(Collider &other) = 0;

    virtual Collision collides(const SphereCollider &other) = 0;
    virtual Collision collides(const PlaneCollider &other) = 0;

    glm::vec3 position;
};

#include "SphereCollider.h"
#include "PlaneCollider.h"

#endif //ASSIGNMENT_2_COLLIDER_H
