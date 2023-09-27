#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <Scene/Scene.hpp>
class GameScene : public Scene {
public:
  GameScene();
  ~GameScene();
  virtual void Update(const SDL_Event &event) override;
  virtual void Render(RenderWindow &renderWindow) override;
};

#endif
