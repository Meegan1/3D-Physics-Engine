//
// Created by Jake Meegan on 09/12/2019.
//

#include <QFormLayout>
#include <QDialogButtonBox>
#include <QLabel>
#include "ObjectDialog.h"

ObjectDialog::ObjectDialog(QWidget *parent) : p_x(), p_y(), p_z(), v_x(), v_y(), v_z(), radius(), restitution() {
    QFormLayout *layout = new QFormLayout();

    QLabel *pLabel = new QLabel("Position:");
    QHBoxLayout *position = new QHBoxLayout();
    position->addWidget(&p_x);
    position->addWidget(&p_y);
    position->addWidget(&p_z);
    layout->addRow(pLabel, position);

    QLabel *vLabel = new QLabel("Velocity:");
    QHBoxLayout *velocity = new QHBoxLayout();
    velocity->addWidget(&v_x);
    velocity->addWidget(&v_y);
    velocity->addWidget(&v_z);
    layout->addRow(vLabel, velocity);

    QLabel *rLabel = new QLabel("Radius:");
    radius.setMinimum(0);
    layout->addRow(rLabel, &radius);

    QLabel *rcLabel = new QLabel("Resitution Coefficient:");
    restitution.setMaximum(1);
    restitution.setMinimum(0);
    restitution.setSingleStep(0.1);
    layout->addRow(rcLabel, &restitution);

    QDialogButtonBox *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal,
                                                     this);
    connect(buttons, &QDialogButtonBox::accepted, this, &ObjectDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &ObjectDialog::reject);

    layout->addWidget(buttons);
    setLayout(layout);
}

Ball ObjectDialog::getBall(QWidget *parent, bool *ok) {
    ObjectDialog *dialog = new ObjectDialog(parent);

    const int ret = dialog->exec();
    *ok = (ret != 0);

    Ball ball(glm::vec3(dialog->p_x.value(), dialog->p_y.value(), dialog->p_z.value()), dialog->radius.value(), dialog->restitution.value());
    ball.rigidBody->setVelocity(glm::vec3(dialog->v_x.value(), dialog->v_y.value(), dialog->v_z.value()));

    return ball;
}
