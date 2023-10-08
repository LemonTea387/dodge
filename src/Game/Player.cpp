#include "Player.hpp"
#include "AssetManager.hpp"
#include "Assets.hpp"
#include "Math.hpp"
#include <SDL_render.h>

Player::Player()
    : m_Body{1.0,
             {0., 0.},
             {0., 0.},
             {32., 500.},
             BoxCollider{{0., 0.}, {32., 32.}},
             BodyType::DYNAMIC} {
  AssetManager &am = AssetManager::GetInstance();
  m_PlayerTexture = am.GetTexture(Assets::AssetID::STICKMAN);
}
Player::~Player() {}
void Player::Update(const SDL_Event &event, double deltaTime) {}
void Player::Render(RenderWindow &renderWindow) {
  const auto &pos = m_Body.position;
  const auto &dim = m_Body.collider.dimension;
  SDL_FRect bounds{pos.x, pos.y, dim.x, dim.y};
  Algorithms::ConvertPhysicsBoundsToSDL(renderWindow, bounds);
  SDL_RenderCopyF(renderWindow.GetRenderer(), m_PlayerTexture.get(), NULL,
                  &bounds);
};
