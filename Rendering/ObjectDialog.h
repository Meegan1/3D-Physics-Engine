//
// Created by Jake Meegan on 09/12/2019.
//

#ifndef ASSIGNMENT_2_OBJECTDIALOG_H
#define ASSIGNMENT_2_OBJECTDIALOG_H


#include <QDialog>
#include <QDoubleSpinBox>
#include "../Objects/Ball.h"

class ObjectDialog : public QDialog {
Q_OBJECT
public:
    explicit ObjectDialog(QWidget *parent = nullptr);
    static Ball getBall(QWidget *parent, bool *ok = nullptr);

private:
    QDoubleSpinBox p_x;
    QDoubleSpinBox p_y;
    QDoubleSpinBox p_z;

    QDoubleSpinBox v_x;
    QDoubleSpinBox v_y;
    QDoubleSpinBox v_z;

    QDoubleSpinBox radius;
    QDoubleSpinBox restitution;
};


#endif //ASSIGNMENT_2_OBJECTDIALOG_H
