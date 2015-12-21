#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class Screen {
private:
  int m_height;
  int m_width;
  std::string m_title;
  SDL_Window* m_window;
  SDL_GLContext m_glContext;
  bool m_windowOpen;

  Screen() {} // Default private constructor

public:
  Screen(int height, int width, const std::string& title);
  virtual ~Screen();

  void Init();
  void Update();
  bool IsWindowOpen();
};

#endif
