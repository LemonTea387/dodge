#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <Scene/Scene.hpp>
#include "Player.hpp"

class GameScene : public Scene {
public:
  GameScene();
  ~GameScene();
  virtual void Update(const SDL_Event &event) override;
  virtual void Render(RenderWindow &renderWindow) override;
private:
  std::unique_ptr<Player> m_Player;
};

#endif
