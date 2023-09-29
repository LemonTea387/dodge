#include "Player.hpp"
#include "AssetManager.hpp"
#include "Assets.hpp"
#include <SDL_render.h>

Player::Player() {
  AssetManager &am = AssetManager::GetInstance();
  m_PlayerTexture = am.GetTexture(Assets::AssetID::STICKMAN);
  SDL_Rect bounds {32,32,32,32};
  SetBounds(bounds);
}
Player::~Player() {}
void Player::Update(const SDL_Event &event, double deltaTime) {}
void Player::Render(RenderWindow &renderWindow) {
  auto trans = GetTransform();
  SDL_RenderCopy(renderWindow.GetRenderer(), m_PlayerTexture.get(), NULL, &trans.bounds);
};
