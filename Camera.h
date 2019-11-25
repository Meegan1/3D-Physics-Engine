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
    Camera() {
        position = glm::vec3(0.0f, 0.0f, 3.0f);
        target = glm::vec3(0.0f, 0.0f, 0.0f);
        direction = glm::normalize(position - target);

        glm::vec3 tempUp = glm::vec3(0.0f, 1.0f, 0.0f);
        right = glm::normalize(glm::cross(tempUp, direction));
        up = glm::cross(direction, right);

        updateView();
        timer.start();
    }

    void update(GLfloat delta_time);

    void rotate(const float yaw, const float pitch, const float roll);
    void setTarget(const glm::vec3 target);
    const glm::vec3 getTarget();
    void pan(const float dx, const float dy);
    void zoom(const float amount);
    void move(const float dx, const float dz);
    glm::mat4 getView();

protected:
    void updateView();

    glm::vec3 target, position, direction, right, up;
    glm::mat4 view;
    QElapsedTimer timer;
};


#endif //ASSIGNMENT_2_CAMERA_H
