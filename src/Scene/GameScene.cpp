#include "GameScene.hpp"
#include <SDL_render.h>

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Update(const SDL_Event &event) {}

void GameScene::Render(RenderWindow &renderWindow) {
  auto renderer = renderWindow.GetRenderer();
  SDL_Rect rect{10, 300, 100, 100};
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
  SDL_RenderDrawRect(renderer, &rect);
}
