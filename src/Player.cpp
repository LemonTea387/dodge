#include "Player.hpp"
#include "AssetManager.hpp"
#include "Assets.hpp"

Player::Player() {
  AssetManager &am = AssetManager::GetInstance();
  m_PlayerTexture = am.GetTexture(Assets::AssetID::STICKMAN);
}
Player::~Player() {}
void Player::Update(const SDL_Event &event, double deltaTime) {}
void Player::Render(RenderWindow &renderWindow){
  auto trans = GetTransform();

};
