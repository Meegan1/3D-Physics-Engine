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
#include <QPushButton>
#include <QSpinBox>
#include "../Objects/Ball.h"
#include "Camera.h"
#include "../Physics/PhysicsEngine.h"
#include "QFPS.h"

#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#define DELTA_TIME 0.01f

class Engine : public QOpenGLWidget, protected QOpenGLFunctions {
Q_OBJECT
public:
    explicit Engine(QWidget *parent);

    void pause();

    void play();

/*
 * GUI Slots
 */
public slots:
    void togglePause();
    void restart();
    void setFPS(int fps);
    void setGravity(double gravity);
    void addObjectDialog();
    void setWindStrength(int strength);
    void setWindDirection();

protected:
    /*
     * OpenGL Methods
     */
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

    /*
     * class members
     */
    bool is_done;
    bool is_paused;
    unsigned int FPS;
    QTimer timer;
    QElapsedTimer elapsed_timer;
    GLfloat delta_accumulator;
    Camera camera;
    QPoint last_m_pos;

    PhysicsEngine physics;

private:
    void initializeHUD();

    /*
     * GUI buttons
     */
    QPushButton *btn_play;
    QPushButton *btn_restart;
    QPushButton *btn_add_object;
    QSpinBox *btn_fps;
    QPushButton *btn_set_wind;
    QSpinBox *btn_wind_strength;
    QFPS *fps_label;
    QDoubleSpinBox *btn_gravity;

    void updateFPS(GLfloat time);
};


#endif //ASSIGNMENT_2_ENGINE_H
