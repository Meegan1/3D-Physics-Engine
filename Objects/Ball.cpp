//
// Created by Jake Meegan on 22/11/2019.
//

#include <gl.h>
#include <GLUT/glut.h>
#include "Ball.h"
#include "../Physics/Sphere.h"

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

Ball::Ball(const glm::vec3 &position, float radius, float restitution_coefficient) : Object(position), radius(radius) {
    Sphere sphere(position, 0.5, 0.6, 1);
    rigidBody = std::make_shared<Sphere>(sphere);
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
    if(rigidBody == nullptr)
        return;

    rigidBody->updateVelocity(delta_time);
    position += rigidBody->getVelocity() * delta_time;
}

void Ball::reset() {
    rigidBody->reset();
    position = rigidBody->o_position;
}
