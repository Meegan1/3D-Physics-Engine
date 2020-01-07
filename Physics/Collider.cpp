//
// Created by Jake Meegan on 07/01/2020.
//

#include "SphereCollider.h"

GLfloat Collider::distance(const SphereCollider &sphere, const glm::vec3 &point) {
    return std::sqrt((point.x - sphere.position.x) * (point.x - sphere.position.x) +
              (point.y - sphere.position.y) * (point.y - sphere.position.y) +
              (point.z - sphere.position.z) * (point.z - sphere.position.z));
}
