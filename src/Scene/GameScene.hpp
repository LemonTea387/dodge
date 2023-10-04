#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <Scene/Scene.hpp>
#include "Physics/Physics.hpp"
#include "Player.hpp"

class GameScene : public Scene {
public:
  GameScene();
  ~GameScene();
  virtual void Update(const SDL_Event &event, double deltaTime) override;
  virtual void Render(RenderWindow &renderWindow) override;
private:
  std::unique_ptr<Player> m_Player;
  std::unique_ptr<World> m_PhysicsWorld;
};

#endif
