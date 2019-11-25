//
// Created by Jake Meegan on 23/11/2019.
//

#include <gltypes.h>
#include "Camera.h"

void Camera::update(GLfloat delta_time) {
    float radius = 10.0f;
    position.x = sin(timer.elapsed()/1000.0f) * radius;
    position.z = cos(timer.elapsed()/1000.0f) * radius;
    view = glm::lookAt(glm::vec3(position.x, 0.0, position.z), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
//    updateView();
}

glm::mat4 Camera::getView() {
    return view;
}

void Camera::updateView() {
    view = glm::lookAt(position, target, up);
}
