#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <GL/glew.h>
#include "fileloader.h"

class Shader {
private:
  static const unsigned char NUM_SHADERS = 2;
  GLuint m_program;
  GLuint m_shaders[NUM_SHADERS];

  void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& err);
  GLuint createShader(const std::string& filename, GLenum shaderType);
  void bind();

public:
  Shader(const std::string& filename);
  ~Shader();
};

#endif
