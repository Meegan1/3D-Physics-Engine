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
    glm::vec3 direction;
    glm::vec3 point;
    glm::vec3 normal;

    Collision(GLboolean hasCollided) : hasCollided(hasCollided), offset(0) {}
    Collision(GLboolean hasCollided, GLfloat offset, const glm::vec3 &direction, const glm::vec3 &point, const glm::vec3 &normal) : hasCollided(
            hasCollided), offset(offset), direction(direction), point(point), normal(normal) {}
};

class SphereCollider;
class PlaneCollider;

class Collider {
public:
    Collider(const glm::vec3 &position) : position(position) {}
    virtual Collision collides(Collider &other) = 0;

    virtual Collision collides(SphereCollider &other) = 0;
    virtual Collision collides(PlaneCollider &other) = 0;

    virtual glm::vec3 closestPoint(const glm::vec3 &point) = 0;

    static GLfloat distance(const SphereCollider &sphere, const glm::vec3 &point);

    glm::vec3 position;
};

#include "SphereCollider.h"
#include "PlaneCollider.h"

#endif //ASSIGNMENT_2_COLLIDER_H
