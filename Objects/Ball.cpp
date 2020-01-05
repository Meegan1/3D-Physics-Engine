//
// Created by Jake Meegan on 22/11/2019.
//

#include <gl.h>
#include <GLUT/glut.h>
#include "Ball.h"

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

Ball::Ball(float x, float y, float z, float radius, float restitution_coefficient) : RigidBody(glm::vec3(x, y, z), 0.5, restitution_coefficient), radius(radius) {
}

void Ball::draw() {
    // create red ball
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslated(position.x, position.y, position.z);
    glutSolidSphere(radius,50,50);
    glPopMatrix();
}

void Ball::update(const GLfloat &delta_time) {
    updateVelocity(delta_time);
    position += getVelocity() * delta_time;
}

void Ball::collision(const glm::vec3 &intersection) {
    if(position.y <= intersection.y + radius) {
        velocity.y = (-velocity.y * getRC());
        position.y = intersection.y + radius;
    }
}
