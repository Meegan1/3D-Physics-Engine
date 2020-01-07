//
// Created by Jake Meegan on 26/11/2019.
//

#include <gl.h>
#include "Plane.h"

Plane::Plane(glm::vec3 position, int height, int width) : Object(position), height(height), width(width) {
    collider = new PlaneCollider(this->position);
}

void Plane::draw() {
    glPushMatrix();
    glTranslatef(position.x-((float)height/2)+0.5f, position.y, position.z-((float)width/2)+0.5f);
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
    glVertex3f(0.5f, 0, 0.5f); // vertex 1
    glVertex3f(0.5f, 0, -0.5f); // vertex 2
    glVertex3f(-0.5f, 0, -0.5f); // vertex 3
    glVertex3f(-0.5f, 0, 0.5f); // vertex 4
    glEnd();
    glPopMatrix();
}
