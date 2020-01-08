//
// Created by Jake Meegan on 26/11/2019.
//

#include <gl.h>
#include "Plane.h"

Plane::Plane(glm::vec3 position, int width, int height) : Object(position), height(height), width(width) {
    collider = new PlaneCollider(this->position, width, height);
    frictionCoefficient = 0.005f;
}

void Plane::draw() {
    glPushMatrix();
    glTranslatef(position.x, position.y, position.z);
    for(int x = 0; x < height; x++) {
        for(int y = 0; y < width; y++) {
            if((x+y)%2 == 0)
                glColor3f(0.0f, 0.0f, 0.0f);
            else
                glColor3f(1.0f, 1.0f, 1.0f);
            drawQuad(x, y);
        }
    }
    glPopMatrix();
}

void Plane::drawQuad(float x, float y) {
    glPushMatrix();
    glTranslatef(x, 0, y);
    glBegin(GL_QUADS);
    glNormal3f(0, 1.0f, 0);
    glVertex3f(1, 0, 1); // vertex 1
    glVertex3f(1, 0, 0); // vertex 2
    glVertex3f(0, 0, 0); // vertex 3
    glVertex3f(0, 0, 1); // vertex 4
    glEnd();
    glPopMatrix();
}
