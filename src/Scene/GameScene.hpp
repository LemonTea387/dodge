#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "Game/Platform.hpp"
#include "Game/Player.hpp"
#include "Physics/Physics.hpp"
#include <Scene/Scene.hpp>

class GameScene : public Scene {
public:
  GameScene();
  ~GameScene();
  virtual void Update(double deltaTime) override;
  virtual void HandleEvents(const SDL_Event &event) override;
  virtual void Render(RenderWindow &renderWindow) override;

private:
  std::unique_ptr<Player> m_Player;
  std::unique_ptr<World> m_PhysicsWorld;
  std::unique_ptr<Platform> m_Platform;
};

#endif
