#ifndef OBJ_PLATFORM_H
#define OBJ_PLATFORM_H

#include "GameObject.hpp"
#include "Physics/Physics.hpp"
#include <memory>
class Platform : public Drawable, public Updatable {
public:
  Platform();
  ~Platform();
  virtual void Update(const SDL_Event &event, double deltaTime) override;
  virtual void Render(RenderWindow &renderWindow) override;
  RigidBody *GetBody() { return &m_Body; };

private:
  RigidBody m_Body;
  std::shared_ptr<SDL_Texture> m_Texture{nullptr};
};

#endif
