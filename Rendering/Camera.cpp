//
// Created by Jake Meegan on 23/11/2019.
//

#include <gltypes.h>
#include "Camera.h"
#include "glm/gtx/quaternion.hpp"

Camera::Camera() : position(0.0f, 0.0f, 3.0f), pitch(0), yaw(0) {
    updateViewMatrix();
}

Camera::Camera(glm::vec3 position) : position(position), pitch(0), yaw(0) {
    updateViewMatrix();
}

void Camera::update() {
    updateViewMatrix();
}

glm::mat4 Camera::getView() {
    return view;
}

void Camera::updateViewMatrix() {
    glm::mat4 translate(1.0f);
    translate = glm::translate(translate, -position);

    glm::mat4 rotate = glm::mat4_cast(orientation());
    view = rotate * translate;
}

void Camera::pan(const float dx, const float dy) {
    position += right() * -dx;
    position += up() * dy;
}

void Camera::zoom(const float amount) {
    position += forward() * amount;
}

void Camera::rotate(float y, float p) {
    if(pitch + p >= glm::radians(89.0f))
        pitch = glm::radians(89.0f);
    else if(pitch + p <= glm::radians(-89.0f))
        pitch = glm::radians(-89.0f);
    else
        pitch += p;

    yaw += y;
}

glm::vec3 Camera::forward() {
    glm::vec4 forward = glm::inverse(orientation()) * glm::vec4(0,0,-1,1);
    return glm::vec3(forward);
}

glm::quat Camera::orientation() {
    glm::quat qPitch = glm::angleAxis(pitch, glm::vec3(1, 0, 0));
    glm::quat qYaw = glm::angleAxis(yaw, glm::vec3(0, 1, 0));

    glm::quat orientation = qPitch * qYaw;
    return glm::normalize(orientation);
}

glm::vec3 Camera::right() {
    glm::vec4 right = glm::inverse(orientation()) * glm::vec4(1,0,0,1);
    return glm::vec3(right);
}

glm::vec3 Camera::up() {
    glm::vec4 up = glm::inverse(orientation()) * glm::vec4(0,1,0,1);
    return glm::vec3(up);
}
