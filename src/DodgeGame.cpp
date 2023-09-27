#include "DodgeGame.hpp"
#include <AssetManager.hpp>

#include "Scene/GameScene.hpp"
#include "Assets.hpp"

DodgeGame::DodgeGame() : Game{"Dodge", 800, 600} {
  AssetManager& am = AssetManager::GetInstance();
  am.LoadAssets(m_RenderWindow, Assets::assets);
  PushScene(std::make_unique<GameScene>());
}
DodgeGame::~DodgeGame() {}
void DodgeGame::Run() {
  SDL_Event e;
  bool quit = false;
  while (quit == false) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        quit = true;
    }
    // Clear Screen
    m_RenderWindow.RendererClearScreen(255, 255, 255, 255);
    m_SceneStack.top()->Render(m_RenderWindow);
    m_RenderWindow.Render();
  }
}
