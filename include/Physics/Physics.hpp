#ifndef PHYSICS_H
#define PHYSICS_H

#include <glm/vec2.hpp>
#include <vector>

struct BoxCollider {
  glm::vec2 centerPosition;
  glm::vec2 dimension;
};

enum BodyType { STATIC, DYNAMIC, KINEMATIC };

struct RigidBody {
  float mass;
  glm::vec2 force;
  glm::vec2 velocity;
  glm::vec2 position;
  BoxCollider collider;
  BodyType type;
};

struct Collision {
  RigidBody *A;
  RigidBody *B;
};

class World {
public:
  World(glm::vec2 gravity, glm::vec2 size) : m_Gravity{gravity}, m_Dimension{size} {};
  ~World(){};
  void Step(float deltaTime) {
    for (auto bodyPtr : m_Bodies) {
      // v = v0 + F/m t
      //   = v0 + at
      bodyPtr->velocity += bodyPtr->force / bodyPtr->mass * deltaTime;
      // displacement = vt
      bodyPtr->position += bodyPtr->velocity * deltaTime;
    }
  };
  void AddBody(RigidBody *body) {
    m_Bodies.push_back(body);
    body->force += body->mass * m_Gravity;
  };
  void RemoveBody(RigidBody *body) {
    for (int i = 0; i < m_Bodies.size(); i++) {
      auto bodyPtr = m_Bodies[i];
      if (body == bodyPtr) {
        m_Bodies.erase(m_Bodies.begin() + i);
        break;
      }
    }
  };

private:
  std::vector<RigidBody *> m_Bodies;
  glm::vec2 m_Gravity;
  glm::vec2 m_Dimension;
};

class Fixture {};

#endif
