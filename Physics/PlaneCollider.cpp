//
// Created by Jake Meegan on 06/01/2020.
//

#include "PlaneCollider.h"


Collision PlaneCollider::collides(Collider &other) {
    return other.collides(*this);
}

Collision PlaneCollider::collides(const SphereCollider &other) {
    GLfloat distance = std::sqrt((position.y - other.position.y) * (position.y - other.position.y));
    return {distance < other.radius, other.radius};
}

Collision PlaneCollider::collides(const PlaneCollider &other) {
    return false;
}
