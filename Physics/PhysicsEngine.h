//
// Created by Jake Meegan on 24/11/2019.
//

#ifndef ASSIGNMENT_2_PHYSICSENGINE_H
#define ASSIGNMENT_2_PHYSICSENGINE_H


#include <vector>
#include "../Objects/Ball.h"

class PhysicsEngine {
public:
    PhysicsEngine() = default;
    void update(GLfloat delta_time);
    void draw();

    void addObject(const std::shared_ptr<RigidBody>& object);
    void setGravity(glm::vec3 g);
protected:
    std::vector<std::shared_ptr<RigidBody>> objects;
    glm::vec3 gravity{0, 0, 0};
};


#endif //ASSIGNMENT_2_PHYSICSENGINE_H
