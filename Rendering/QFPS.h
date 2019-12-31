//
// Created by Jake Meegan on 31/12/2019.
//

#ifndef ASSIGNMENT_2_QFPS_H
#define ASSIGNMENT_2_QFPS_H


#include <QLabel>

class QFPS : public QLabel {
public:
    explicit QFPS(QWidget *parent) : QLabel(parent) {}
    void updateFPS(quint8 time);
};


#endif //ASSIGNMENT_2_QFPS_H
