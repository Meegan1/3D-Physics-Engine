//
// Created by Jake Meegan on 19/11/2019.
//

#include <QPainter>
#include "Engine.h"
#include "../Physics/PhysicsEngine.h"
#include "../Objects/Plane.h"
#include "ObjectDialog.h"
#include <QMouseEvent>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

Engine::Engine(QWidget *parent)
        :
        QOpenGLWidget(parent),
        is_done(false),
        is_paused(false),
        FPS(0),
        timer(this),
        camera(glm::vec3(0, 5.f, 7)),
        physics(),
        delta_accumulator(0) {}

void Engine::initializeGL() {
    initializeOpenGLFunctions();
    initializeHUD();

    glEnable(GL_DEPTH_TEST); // enable z-buffering
    glEnable(GL_CULL_FACE); // cull triangles facing away
    // set lighting parameters
//    glShadeModel(GL_FLAT);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL); // enable colour

    // set background colour to purple
    glClearColor(0.5f, 0.5f, 1.0f, 1.0f);

    /*
     * Setup Physics Engine
     */
    physics.setGravity(glm::vec3(0, -9.8f, 0));

    // ball falling off side of plane
//    Ball falling_ball(glm::vec3(-5.1, 1, 0), 1, 0.6);
//    physics.addObject(std::make_shared<Ball>(falling_ball));

    /*
     * Balls colliding into eachother
     */
//    Ball colliding_ball_1(glm::vec3(0, 10, 0), 1, 0.5);
//    physics.addObject(std::make_shared<Ball>(colliding_ball_1));
//
//    Ball colliding_ball_2(glm::vec3(0.1, 1, 0), 1, 0.5);
//    physics.addObject(std::make_shared<Ball>(colliding_ball_2));
////    colliding_ball_2.rigidBody->setForce(glm::vec3(0.0f, 9.8f/2, 0.0f));
//
//    Ball colliding_ball_3(glm::vec3(-3, 7, 0), 1, 0.6);
//    physics.addObject(std::make_shared<Ball>(colliding_ball_3));

    Ball colliding_ball_1(glm::vec3(-5, 1, 0), 1, 1);
    physics.addObject(std::make_shared<Ball>(colliding_ball_1));
    colliding_ball_1.rigidBody->velocity = glm::vec3(2, 0, 0);
    colliding_ball_1.rigidBody->mass = 1;

    Ball colliding_ball_2(glm::vec3(5, 1, 0), 1, 1);
    physics.addObject(std::make_shared<Ball>(colliding_ball_2));
    colliding_ball_2.rigidBody->velocity = glm::vec3(-2, 0, 0);
    colliding_ball_2.rigidBody->mass = 1;


    Plane plane(glm::vec3(-5, 0, -5), 10, 10);
    physics.addObject(std::make_shared<Plane>(plane));

    startLoop(); // start game loop
}

void Engine::initializeHUD() {
    // setup pause/play button
    btn_play = new QPushButton("Pause", this);
    btn_play->setGeometry(QRect(QPoint(0, 0),
                                QSize(100, 50)));

    // setup restart button
    btn_restart = new QPushButton("Restart", this);
    btn_restart->setGeometry(QRect(QPoint(100, 0),
                                QSize(100, 50)));

    // setup add object button
    btn_add_object = new QPushButton("Add Object", this);
    btn_add_object->setGeometry(QRect(QPoint(200, 0),
                                   QSize(100, 50)));

    // setup FPS Control
    btn_fps = new QSpinBox(this);
    btn_fps->setGeometry(QRect(QPoint(300, 12),
                               QSize(100, 25)));
    btn_fps->setSuffix(" fps");

    fps_label = new QFPS(this);
    fps_label->setGeometry(QRect(QPoint(400, 0),
                                 QSize(100, 50)));

    // connect buttons to slots
    connect(btn_play, SIGNAL (released()), this, SLOT (togglePause()));
    connect(btn_restart, SIGNAL (released()), this, SLOT (restart()));
    connect(btn_add_object, SIGNAL (released()), this, SLOT (addObjectDialog()));
    connect(btn_fps, SIGNAL (valueChanged(int)), this, SLOT (setFPS(int)));
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
    GLfloat frame_time = elapsed_timer.nsecsElapsed() * 0.000000001;
    elapsed_timer.restart();
    delta_accumulator += frame_time;

    camera.update();

    // integrate in steps
    while (delta_accumulator >= DELTA_TIME) {
        if (!is_paused)
            physics.update(DELTA_TIME);

        delta_accumulator -= DELTA_TIME;
    }

    // catch remainder in accumulator and integrate
    if(delta_accumulator >= 0.0f) {
        if (!is_paused)
            physics.update(delta_accumulator);

        delta_accumulator = 0.0f;
    }

    // call window/opengl to update
    update();

    if(FPS != 0) {
        timer.stop();
        timer.start((1000 / (int) FPS) - (int) elapsed_timer.elapsed());
    }

    updateFPS(frame_time);
}

void Engine::resizeGL(int w, int h) {

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

    physics.draw();

    GLfloat lightPos[] = {0, 3.0f, 0, 0};
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

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
    } else if (event->buttons() & Qt::RightButton) {
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
    camera.zoom(event->delta() * 0.05f);
}

void Engine::pause() {
    is_paused = true;
    btn_play->setText("Play");
}

void Engine::play() {
    elapsed_timer.restart();
    is_paused = false;
    btn_play->setText("Pause");
}

void Engine::togglePause() {
    if(is_paused)
        play();
    else
        pause();
}

void Engine::restart() {
    physics.reset();
}

void Engine::setFPS(int fps) {
    FPS = fps;

    // uncap fps when set to 0
    if(fps == 0) {
        timer.stop();
        timer.start(0);
    }
}

void Engine::addObjectDialog() {
    bool ok;
    std::shared_ptr<Ball> ball = std::make_shared<Ball>(ObjectDialog::getBall(this, &ok));
    if(ok)
        physics.addObject(ball);
}

void Engine::updateFPS(GLfloat time) {
    int FPS = 1/time;
    fps_label->updateFPS(FPS);
}

#pragma clang diagnostic pop