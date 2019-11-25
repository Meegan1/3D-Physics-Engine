//
// Created by Jake Meegan on 19/11/2019.
//

#include <QPainter>
#include "RenderWindow.h"
#include "PhysicsEngine.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

RenderWindow::RenderWindow(QWidget *parent) : QOpenGLWidget(parent), isDone(false), timer(this), camera() {}

void RenderWindow::initializeGL() {
    initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST); // enable z-buffering
    glEnable(GL_CULL_FACE); // cull triangles facing away
    // set lighting parameters
//    glShadeModel(GL_FLAT);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL); // enable colour

    // set background colour to purple
    glClearColor(0.5f, 0.5f, 1.0f, 1.0f);

    Ball ball(0.0, 0, 0, 1);
    PhysicsEngine::addObject(std::make_shared<Ball>(ball));

    startLoop(); // start game loop
}

void RenderWindow::startLoop() {
    // start elapsed timer
    elapsed_timer.start();

    // start game loop
    connect(&timer, &QTimer::timeout, this, QOverload<>::of(&RenderWindow::loop));
    timer.start();
}

void RenderWindow::loop() {
    // get time from previous frame
    delta_time = elapsed_timer.elapsed() / 1000.0f;
    elapsed_timer.restart();

//    PhysicsEngine::update(delta_time);
    camera.update(delta_time);

    // call window/opengl to update
    update();
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

    glMultMatrixf(&camera.getView()[0][0]);

    PhysicsEngine::draw();

    // swap buffer
    glutSwapBuffers();
}

#pragma clang diagnostic pop