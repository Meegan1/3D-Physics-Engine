//
// Created by Jake Meegan on 19/11/2019.
//

#include <QPainter>
#include "Engine.h"
#include "../Physics/PhysicsEngine.h"
#include <QMouseEvent>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

Engine::Engine(QWidget *parent) : QOpenGLWidget(parent), isDone(false), timer(this), camera() {}

void Engine::initializeGL() {
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

void Engine::startLoop() {
    // start elapsed timer
    elapsed_timer.start();

    // start game loop
    connect(&timer, &QTimer::timeout, this, QOverload<>::of(&Engine::loop));
    timer.start();
}

void Engine::loop() {
    // get time from previous frame
    delta_time = elapsed_timer.elapsed() / 1000.0f;
    elapsed_timer.restart();

    PhysicsEngine::update(delta_time);
    camera.update();

    // call window/opengl to update
    update();
}

void Engine::resizeGL(int w, int h) {
    screen_width = w;
    screen_height = h;

    const float aspectRatio = (float) w / (float) h;

    // resize viewport to window size
    glViewport(0, 0, w, h);

    // set projection matrix to glFrustum based on window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-aspectRatio, aspectRatio, -1.0, 1.0, 2.0, 100.0);
}

void Engine::paintGL() {
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

void Engine::mouseMoveEvent(QMouseEvent *event) {
    float sensitivity = 0.01;
    if (event->buttons() & Qt::LeftButton) {
        float xoffset = event->x() - last_m_pos.x();
        float yoffset = event->y() - last_m_pos.y();

        xoffset *= sensitivity;
        yoffset *= sensitivity;

        camera.rotate(xoffset, yoffset);
    }
    else if(event->buttons() &Qt::RightButton) {
        float xoffset = last_m_pos.x() - event->x();
        float yoffset = last_m_pos.y() - event->y();

        xoffset *= sensitivity;
        yoffset *= sensitivity;
        camera.pan(xoffset, yoffset);
    }

    last_m_pos = event->pos();
}

void Engine::mousePressEvent(QMouseEvent *event) {
    last_m_pos = event->pos();
}

void Engine::wheelEvent(QWheelEvent *event) {
    camera.zoom(event->delta()*0.05f);
}

#pragma clang diagnostic pop