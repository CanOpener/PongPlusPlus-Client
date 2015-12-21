#include "../include/game.h"

// Game class contructor. Take the screen reference and assigns it to
// m_screen to be utilized in the future
Game::Game(Screen* screen){
  m_screen = screen;
}

// Start running the game
void Game::Run(){
  while(m_screen->IsWindowOpen()){
    glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    m_screen->Update();
  }
}
