//
// Created by Jake Meegan on 23/11/2019.
//

#ifndef ASSIGNMENT_2_CAMERA_H
#define ASSIGNMENT_2_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <QElapsedTimer>

class Camera {
public:
    Camera();

    void update();

    void rotate(float p, float y);
    glm::vec3 forward();
    glm::vec3 right();
    glm::vec3 up();
    glm::quat orientation();

    void pan(const float dx, const float dy);
    void zoom(const float amount);
    glm::mat4 getView();
    glm::mat4 view;
protected:
    glm::vec3 position;
    float yaw, pitch;

    void updateViewMatrix();
};


#endif //ASSIGNMENT_2_CAMERA_H
