//
// Created by Jake Meegan on 22/11/2019.
//

#include <gl.h>
#include <GLUT/glut.h>
#include "Ball.h"

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

Ball::Ball(float x, float y, float z, float radius) : RigidBody(glm::vec3(x, y, z)), radius(radius) {
    timer.start();
}

void Ball::draw() {
    // create red ball
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslated(position.x, position.y, position.z);
    glutSolidSphere(radius,50,50);
    glPopMatrix();
}

void Ball::update(GLfloat delta_time) {
    position += gravity * delta_time * (timer.elapsed()/1000.0f);
}
