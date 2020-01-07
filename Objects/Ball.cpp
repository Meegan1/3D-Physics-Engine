//
// Created by Jake Meegan on 22/11/2019.
//

#include <gl.h>
#include <GLUT/glut.h>
#include "Ball.h"
#include "../Physics/SphereCollider.h"

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

Ball::Ball(const glm::vec3 &position, float radius, float restitution_coefficient) : Object(position), radius(radius) {
    rigidBody = std::make_shared<RigidBody>(RigidBody(position, 0.5, 0.6));
    collider = new SphereCollider(this->position, radius);
}

void Ball::draw() {
    // create red ball
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslated(position.x, position.y, position.z);
    glutSolidSphere(radius,50,50);
    glPopMatrix();
}

void Ball::reset() {
    rigidBody->reset();
    position = rigidBody->o_position;
}
