//
// Created by Jake Meegan on 05/01/2020.
//

#include "SphereCollider.h"

//bool SphereCollider::collides(const Plane &plane) {
//    if(position.y <= plane.position.y + radius)
//        return true;

//}


Collision SphereCollider::collides(Collider &other) {
    return other.collides(*this);
}


Collision SphereCollider::collides(const SphereCollider &other) {
    return false;
}


Collision SphereCollider::collides(const PlaneCollider &other) {
    GLfloat distance = Collider::distance(*this, other.position);
    return distance < radius;
}

glm::vec3 SphereCollider::closestPoint(const glm::vec3 &point) {
    return glm::normalize(point - position) * radius;
}
