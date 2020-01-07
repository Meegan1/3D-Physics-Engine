//
// Created by Jake Meegan on 06/01/2020.
//

#include "PlaneCollider.h"


Collision PlaneCollider::collides(Collider &other) {
    return other.collides(*this);
}

Collision PlaneCollider::collides(const SphereCollider &other) {
    glm::vec3 planePoint = closestPoint(other.position);
    GLfloat distance = Collider::distance(other, planePoint);

    return {distance < other.radius, other.radius};
}

Collision PlaneCollider::collides(const PlaneCollider &other) {
    return false;
}

glm::vec3 PlaneCollider::closestPoint(const glm::vec3 &point) {
    glm::vec3 newPoint(point - position);
    return glm::vec3(glm::clamp(newPoint.x, 0.0f, width), position.y, glm::clamp(newPoint.z, 0.0f, height)) + position;
}
