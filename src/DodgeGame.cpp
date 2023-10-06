#include "DodgeGame.hpp"
#include <AssetManager.hpp>

#include "Assets.hpp"
#include "Scene/GameScene.hpp"

DodgeGame::DodgeGame() : Game{"Dodge", 800, 600} {
  AssetManager &am = AssetManager::GetInstance();
  am.LoadAssets(m_RenderWindow, Assets::assets);
  PushScene(std::make_unique<GameScene>());
}
DodgeGame::~DodgeGame() {}
void DodgeGame::Run() {
  SDL_Event e;
  bool quit = false;
  double lastTime = SDL_GetTicks();
  double currentTime;
  double deltaTime = 0;
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
        break;
      }
    }
    currentTime = SDL_GetTicks();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;
    m_SceneStack.top()->Update(e, deltaTime);

    // Clear Screen
    m_RenderWindow.RendererClearScreen(255, 255, 255, 255);
    m_SceneStack.top()->Render(m_RenderWindow);
    m_RenderWindow.Render();
  }
}
