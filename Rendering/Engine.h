//
// Created by Jake Meegan on 19/11/2019.
//

#ifndef ASSIGNMENT_2_ENGINE_H
#define ASSIGNMENT_2_ENGINE_H


#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <QtDebug>
#include <QTimer>
#include <QElapsedTimer>
#include "../Objects/Ball.h"
#include "Camera.h"

#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

class Engine : public QOpenGLWidget, protected QOpenGLFunctions {
public:
    explicit Engine(QWidget *parent);
protected:
    void initializeGL() override;

    void startLoop();

    void loop();

    void resizeGL(int w, int h) override;

    void paintGL() override;

    /*
     * Mouse Events
     */
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void wheelEvent(QWheelEvent *event) override;

    bool isDone;
    QTimer timer;
    QElapsedTimer elapsed_timer;
    GLfloat delta_time;
    Camera camera;
    QPoint last_m_pos;
};


#endif //ASSIGNMENT_2_ENGINE_H
