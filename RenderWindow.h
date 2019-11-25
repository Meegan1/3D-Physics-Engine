//
// Created by Jake Meegan on 19/11/2019.
//

#ifndef ASSIGNMENT_2_RENDERWINDOW_H
#define ASSIGNMENT_2_RENDERWINDOW_H


#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <QTimer>
#include <QElapsedTimer>
#include "Ball.h"
#include "Camera.h"

#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

class RenderWindow : public QOpenGLWidget, protected QOpenGLFunctions {
public:
    explicit RenderWindow(QWidget *parent);
protected:
    void initializeGL() override;

    void startLoop();

    void loop();

    void resizeGL(int w, int h) override;

    void paintGL() override;

    bool isDone;
    QTimer timer;
    QElapsedTimer elapsed_timer;
    GLfloat delta_time;
    Camera camera;
};


#endif //ASSIGNMENT_2_RENDERWINDOW_H
