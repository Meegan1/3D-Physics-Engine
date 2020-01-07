//
// Created by Jake Meegan on 22/11/2019.
//

#ifndef ASSIGNMENT_2_BALL_H
#define ASSIGNMENT_2_BALL_H


#include "Object.h"

class Ball : public Object {
public:
    explicit Ball(const glm::vec3 &position, float radius, float restitution_coefficient);
    void draw() override;
    void reset();

    float radius;
};


#endif //ASSIGNMENT_2_BALL_H
