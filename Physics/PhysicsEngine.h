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
    void setGravity(glm::vec3 g);
    glm::vec3 getGravity();
    void setGlobalForce(const glm::vec3 &direction, GLfloat strength);
    void setGlobalForceStrength(GLfloat strength);
protected:
    std::vector<std::shared_ptr<Object>> objects;
    glm::vec3 gravity{0, 0, 0};
    glm::vec3 globalForce{0};
};


#endif //ASSIGNMENT_2_PHYSICSENGINE_H
