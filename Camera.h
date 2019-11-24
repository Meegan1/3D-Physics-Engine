//
// Created by Jake Meegan on 23/11/2019.
//

#ifndef ASSIGNMENT_2_CAMERA_H
#define ASSIGNMENT_2_CAMERA_H

#include <glm/glm.hpp>

class Camera {
public:
    Camera();
    void update();
    void rotate(const float yaw, const float pitch, const float roll);
    void setTarget(const glm::vec3 target);
    const glm::vec3 getTarget();
    void pan(const float dx, const float dy);
    void zoom(const float amount);
    void move(const float dx, const float dz);

protected:
    glm::vec3 target;
    float minRy, maxRy;
    float distance;
    float minDistance, maxDistance;
    glm::vec3 position;
};


#endif //ASSIGNMENT_2_CAMERA_H
