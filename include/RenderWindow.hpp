#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <stdint.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <string>

class RenderWindow {
public:
  RenderWindow(const std::string &title, int x, int y) {
    InitSDL();
    CreateWindow(title, x, y);
  }
  ~RenderWindow() {
    // Window
    SDL_DestroyWindow(m_Window);

    // SDL System
    SDL_Quit();
  }
  SDL_Renderer *GetRenderer() { return m_Renderer; };
  SDL_Window *GetWindow() { return m_Window; };
  void RendererClearScreen(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    // Clear screen
    SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
    SDL_RenderClear(m_Renderer);
  };
  void Render() { SDL_RenderPresent(m_Renderer); }

private:
  SDL_Window *m_Window;
  SDL_Renderer *m_Renderer;

  int InitSDL() {
    // Initialize SDl
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
      printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
      return -1;
    }

    // Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
      printf("SDL_image could not initialize! SDL_image Error: %s\n",
             IMG_GetError());
      return -1;
    }
    return 0;
  }
  int CreateWindow(const std::string &title, int x, int y) {
    // Create window
    this->m_Window =
        SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN);
    if (this->m_Window == NULL) {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      return -1;
    }
    this->m_Renderer = SDL_CreateRenderer(this->m_Window, -1,
                                          SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    if (this->m_Renderer == NULL) {
      printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
      return -1;
    }
    return 0;
  }
};

#endif
