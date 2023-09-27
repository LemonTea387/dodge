#ifndef GAME_H
#define GAME_H

#include <memory>
#include <stack>

#include <Scene/Scene.hpp>

class Game {
public:
  Game(const std::string &title, int x, int y) : m_RenderWindow{title, x, y} {};
  void PushScene(std::unique_ptr<Scene> &&scene) {
    m_SceneStack.push(std::move(scene));
  };
  void PopScene() { m_SceneStack.pop(); }
  virtual void Run() = 0;

protected:
  std::stack<std::unique_ptr<Scene>> m_SceneStack;
  RenderWindow m_RenderWindow;
};

#endif
