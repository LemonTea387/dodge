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
  World(glm::vec2 gravity, glm::vec2 size, float pixelPerMeter)
      : m_Gravity{gravity}, m_Dimension{size}, m_PPM{pixelPerMeter} {};
  ~World(){};
  void Step(float deltaTime) {
    for (auto bodyPtr : m_Bodies) {
      // Only Dynamic and Kinematic bodies move
      if (bodyPtr->type == BodyType::STATIC)
        continue;
      // v = v0 + F/m t
      //   = v0 + at
      bodyPtr->velocity +=
          (bodyPtr->force + m_Gravity) / bodyPtr->mass * deltaTime / m_PPM;
      // displacement = vt
      bodyPtr->position += bodyPtr->velocity * deltaTime / m_PPM;
    }
  };
  void AddBody(RigidBody *body) { m_Bodies.push_back(body); };
  void RemoveBody(RigidBody *body) {
    for (int i = 0; i < m_Bodies.size(); i++) {
      if (body == m_Bodies[i]) {
        m_Bodies.erase(m_Bodies.begin() + i);
        break;
      }
    }
  };

private:
  std::vector<RigidBody *> m_Bodies;
  glm::vec2 m_Gravity;
  glm::vec2 m_Dimension;
  float m_PPM;
};

#endif
