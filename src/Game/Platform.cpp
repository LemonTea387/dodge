#include "Platform.hpp"
#include "AssetManager.hpp"
#include "Assets.hpp"
#include "Math.hpp"

Platform::Platform()
    : m_Body{1.0,
             {0., 0.},
             {0., 0.},
             {30., 30.},
             BoxCollider{{30., 30.}, {100., 9.}},
             BodyType::STATIC} {
  AssetManager &am = AssetManager::GetInstance();
  m_Texture = am.GetTexture(Assets::AssetID::PLATFORM);
}

Platform::~Platform() {}

void Platform::Update(const SDL_Event &event, double deltaTime) {}

void Platform::Render(RenderWindow &renderWindow) {
  const auto &pos = m_Body.position;
  const auto &dim = m_Body.collider.dimension;
  SDL_FRect bounds{pos.x, pos.y, dim.x, dim.y};
  Algorithms::ConvertPhysicsBoundsToSDL(renderWindow, bounds);
  SDL_RenderCopyF(renderWindow.GetRenderer(), m_Texture.get(), NULL,
                  &bounds);
}
