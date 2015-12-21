#ifndef GAME_H
#define GAME_H

#include "screen.h"

class Game {
private:
  // Private Variables
  Screen* m_screen;

  Game(){}; // Private Default constructor
public:
  // Public Constructor
  Game(Screen* screen);

  // Public methods
  void Run();
};

#endif
