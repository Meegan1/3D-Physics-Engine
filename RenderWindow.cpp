//
// Created by Jake Meegan on 19/11/2019.
//

#include "RenderWindow.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
RenderWindow::RenderWindow(QWidget *parent) : QOpenGLWidget(parent) {}

void RenderWindow::initializeGL() {
    initializeOpenGLFunctions();

    // enable z-buffering
    glEnable(GL_DEPTH_TEST);

    // cull triangles facing away
    glEnable(GL_CULL_FACE);

    // set lighting parameters
//    glShadeModel(GL_FLAT);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    // enable colour
    glEnable(GL_COLOR_MATERIAL);

    // set background colour to purple
    glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
}

void RenderWindow::resizeGL(int w, int h) {
    const float aspectRatio = (float) w / (float) h;

    // resize viewport to window size
    glViewport(0, 0, w, h);

    // set projection matrix to glFrustum based on window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-aspectRatio, aspectRatio, -1.0, 1.0, 2.0, 100.0);
}

void RenderWindow::paintGL() {
    // clear the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // enable lighting
    glEnable(GL_LIGHTING);

    // set model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    // create red ball
    glColor3f(1, 0, 0);
    glPushMatrix();
    glTranslated(0.0,0,-6);
    glutSolidSphere(1,50,50);
    glPopMatrix();

    // swap buffer
    glutSwapBuffers();
}

#pragma clang diagnostic pop