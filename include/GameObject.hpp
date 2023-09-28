#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "RenderWindow.hpp"
#include <SDL_events.h>
class Updatable {
  virtual void Update(const SDL_Event &event, double deltaTime) = 0;
};
class Drawable {
  virtual void Render(RenderWindow &renderWindow) = 0;
};

struct Transform {
  int x;
  int y;
};
class Transformable {
protected:
  Transform GetTransform() { return transform; };
  Transform transform;
};
#endif
