#include "screen.h"

// Constructor
Screen::Screen(int width, int height, const std::string& title){
  m_width = width;
  m_height = height;
  m_title = title;

  init();
}

Screen::~Screen(){
  SDL_GL_DeleteContext(m_glContext);
  SDL_DestroyWindow(m_window);
  SDL_Quit();
}

// Screen initializer
void Screen::init(){

  // Initialize SDL
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
  SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

  // Create a new window
  m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_OPENGL);

  // Set OpenGL context
  m_glContext = SDL_GL_CreateContext(m_window);

  // Check was GLEW initialized correctly
  GLenum status = glewInit();
  if(status != GLEW_OK){
    std::cerr << "OpenGL failed to initialize: GLEW could not be initialized" << std::endl;
  }

  // Set the window status to
  m_windowOpen = true;
}

bool Screen::IsWindowOpen() const {
  return m_windowOpen;
}

void Screen::Update(){
  SDL_GL_SwapWindow(m_window);

  SDL_Event e;

  while(SDL_PollEvent(&e)){
    if(e.type == SDL_QUIT){
      m_windowOpen = false;
    }
  }
}
