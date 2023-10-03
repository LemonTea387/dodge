#ifndef PHYSICS_H
#define PHYSICS_H

#include <glm/vec2.hpp>
#include <vector>

struct RigidBody {
  float mass;
  glm::vec2 force;
  glm::vec2 velocity;
  glm::vec2 position;
};

class World {
public:
  World(glm::vec2 gravity) : m_Gravity{gravity} {};
  ~World();
  void Step(float deltaTime) {
    for (auto bodyPtr : m_Bodies) {
      // F = ma, where a = g
      bodyPtr->force += bodyPtr->mass * m_Gravity;

      // v = v0 + F/m t
      //   = v0 + at
      bodyPtr->velocity += bodyPtr->force / bodyPtr->mass * deltaTime;
      // displacement = vt
      bodyPtr->position += bodyPtr->velocity * deltaTime;

      // Reset?
      bodyPtr->force = glm::vec2{0., 0.};
    }
  };
  void AddBody(RigidBody *body) { m_Bodies.push_back(body); };
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
};

class Fixture {};

#endif
