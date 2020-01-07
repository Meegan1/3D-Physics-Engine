//
// Created by Jake Meegan on 06/01/2020.
//

#include "PlaneCollider.h"


Collision PlaneCollider::collides(Collider &other) {
    return other.collides(*this);
}

Collision PlaneCollider::collides(SphereCollider &other) {
    glm::vec3 point = closestPoint(other.position);
    GLfloat distance = Collider::distance(other, point);

    glm::vec3 direction = glm::normalize(other.closestPoint(point));

    return {distance < other.radius, other.radius, direction, point};
}

Collision PlaneCollider::collides(PlaneCollider &other) {
    return false;
}

glm::vec3 PlaneCollider::closestPoint(const glm::vec3 &point) {
    glm::vec3 newPoint(point - position);
    return glm::vec3(glm::clamp(newPoint.x, 0.0f, width), position.y, glm::clamp(newPoint.z, 0.0f, height)) + position;
}
