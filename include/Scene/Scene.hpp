#ifndef SCENE_H
#define SCENE_H

#include <RenderWindow.hpp>
#include <SDL_events.h>
class Scene {
public:
  virtual void Update(double deltaTime) = 0;
  virtual void HandleEvents(const SDL_Event &event) = 0;
  virtual void Render(RenderWindow &renderWindow) = 0;
  Scene(){};
  ~Scene(){};
};

#endif
