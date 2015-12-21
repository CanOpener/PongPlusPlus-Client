#include <iostream>
#include "../include/screen.h"
#include "../include/flags.h"
#include "../include/game.h"

int main(int argc, char* argv[]){

  // Parse the CLI flags
  Flags flags(argc, argv);
  flags.Parse();

  // Create a new screen and handle the screen by the main Game class
  Screen screen(800,600,"PongPlusPlus-Client");
  screen.Init();
  Game game(&screen);

  // Start running the game
  game.Run();

  // Finish running the program
  return 0;
}
