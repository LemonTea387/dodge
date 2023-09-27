#ifndef DODGE_GAME_H
#define DODGE_GAME_H

#include <Game.hpp>
class DodgeGame : public Game {
public:
  DodgeGame();
  ~DodgeGame();
  void Run() override;
};

#endif
