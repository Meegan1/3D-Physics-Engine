//
// Created by Jake Meegan on 05/01/2020.
//

#include "SphereCollider.h"

Collision SphereCollider::collides(Collider &other) {
    return other.collides(*this);
}

Collision SphereCollider::collides(SphereCollider &other) {
    glm::vec3 point = closestPoint(other.position);
    GLfloat distance = Collider::distance(other, point);

    glm::vec3 direction = glm::normalize(other.closestPoint(point) - other.position);

    return {distance < other.radius, other.radius, direction, point, glm::normalize(point - position)};
}

Collision SphereCollider::collides(PlaneCollider &other) {
    return false;
}

glm::vec3 SphereCollider::closestPoint(const glm::vec3 &point) {
    return (glm::normalize(point - position) * radius) + position;
}
