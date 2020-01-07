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
//    GLfloat distance = std::sqrt((other.position->x - position.x) * (other.position.x - position.x) +
//                             (other.position.y - position.y) * (other.position.y - position.y) +
//                             (other.position.z - position.z) * (other.position.z - position.z));
//    return distance < radius;
    //    if(position.y <= plane.position.y + radius)
//        return true;
////        velocity.y = (-velocity.y * getRC());
////        position.y = intersection + radius;
}
