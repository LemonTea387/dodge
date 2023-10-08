#include "GameScene.hpp"
#include <SDL_render.h>

GameScene::GameScene()
    : m_Player{new Player()}, m_Platform{new Platform()},
      m_PhysicsWorld{new World({0., -9.81}, {800, 600}, 32)} {
  m_PhysicsWorld->AddBody(m_Player->GetBody());
  m_PhysicsWorld->AddBody(m_Platform->GetBody());
}

GameScene::~GameScene() {}

void GameScene::Update(double deltaTime) { m_PhysicsWorld->Step(deltaTime); }

void GameScene::Render(RenderWindow &renderWindow) {
  m_Platform->Render(renderWindow);
  m_Player->Render(renderWindow);
}

void GameScene::HandleEvents(const SDL_Event &event) {}
