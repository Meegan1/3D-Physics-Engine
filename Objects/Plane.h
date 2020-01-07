//
// Created by Jake Meegan on 26/11/2019.
//

#ifndef ASSIGNMENT_2_PLANE_H
#define ASSIGNMENT_2_PLANE_H


#include "Object.h"

class Plane : public Object {
public:
    explicit Plane(glm::vec3 position, int height, int width);

    void draw() override;

    void drawQuad(float x, float y);

    int height, width;
};


#endif //ASSIGNMENT_2_PLANE_H
