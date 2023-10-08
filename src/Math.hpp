#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <RenderWindow.hpp>
#include <SDL_rect.h>
namespace Algorithms {

inline void ConvertPhysicsBoundsToSDL(RenderWindow &renderWindow,
                                      SDL_FRect &bounds) {
  int h;
  SDL_GetWindowSize(renderWindow.GetWindow(), NULL, &h);
  bounds.y = h-bounds.y; 
}

} // namespace Algorithms

#endif
