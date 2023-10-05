#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.hpp"
#include "Physics/Physics.hpp"
#include <SDL_render.h>
#include <memory>
class Player : public Drawable, public Updatable, public Transformable {
public:
  Player();
  ~Player();
  virtual void Update(const SDL_Event &event, double deltaTime) override;
  virtual void Render(RenderWindow &renderWindow) override;
  RigidBody *GetBody() { return &m_Body; };

private:
  std::shared_ptr<SDL_Texture> m_PlayerTexture{nullptr};
  RigidBody m_Body;
};

#endif
