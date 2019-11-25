//
// Created by Jake Meegan on 24/11/2019.
//

#ifndef ASSIGNMENT_2_PHYSICSENGINE_H
#define ASSIGNMENT_2_PHYSICSENGINE_H


#include <vector>
#include "../Objects/Ball.h"

class PhysicsEngine {
public:
    static void update(GLfloat delta_time);
    static void draw();

    static void addObject(const std::shared_ptr<RigidBody>& object);
protected:
    static std::vector<std::shared_ptr<RigidBody>> objects;
};


#endif //ASSIGNMENT_2_PHYSICSENGINE_H
