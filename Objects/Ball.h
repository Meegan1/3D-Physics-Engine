//
// Created by Jake Meegan on 22/11/2019.
//

#ifndef ASSIGNMENT_2_BALL_H
#define ASSIGNMENT_2_BALL_H


#include "RigidBody.h"

class Ball : public RigidBody {
public:
    explicit Ball(float x, float y, float z, float radius, float restitution_coefficient);
    void draw() override;
    void update(const GLfloat &delta_time) override;

    float radius;
};


#endif //ASSIGNMENT_2_BALL_H
