//
// Created by Jake Meegan on 31/12/2019.
//

#include "QFPS.h"

void QFPS::updateFPS(quint8 time) {
    this->setText("FPS: " + QString::number(time));
}
