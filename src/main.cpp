#include <iostream>
#include "flags.h"
#include "game.h"

int main(int argc, char* argv[]){

  // Parse the CLI flags
  Flags flags(argc, argv);
  flags.Parse();

  // Create a new Game class
  Game game;

  // Start running the game
  game.Run();

  // Finish running the program
  return 0;
}
