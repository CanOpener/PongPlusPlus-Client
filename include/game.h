#ifndef GAME_H
#define GAME_H

#include <memory>

#include "screen.h"
#include "shader.h"

class Game {
private:
  // Private Variables
  std::unique_ptr<Screen> m_screen;

public:
  // Public Constructor
  Game();

  // Public methods
  void Run();
};

#endif
