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
    void reset();

    void addObject(const std::shared_ptr<Object>& object);
    void addRigidBody(const std::shared_ptr<RigidBody>& rigidBody);
    void setGravity(glm::vec3 g);
protected:
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<RigidBody>> rigidBodies;
    glm::vec3 gravity{0, 0, 0};
};


#endif //ASSIGNMENT_2_PHYSICSENGINE_H
