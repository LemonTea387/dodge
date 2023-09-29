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
  SDL_Rect bounds;
};
class Transformable {
protected:
  Transform GetTransform() { return transform; };
  void SetBounds(const SDL_Rect &newBounds) { transform.bounds = newBounds; };

private:
  Transform transform;
};
#endif
