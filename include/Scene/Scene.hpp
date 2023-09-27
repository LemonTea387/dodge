#ifndef SCENE_H
#define SCENE_H

#include <RenderWindow.hpp>
#include <SDL_events.h>
class Scene {
public:
  virtual void Update(const SDL_Event &event) {};
  virtual void Render(RenderWindow &renderWindow) {};
  Scene(){};
  ~Scene(){};
};

#endif
