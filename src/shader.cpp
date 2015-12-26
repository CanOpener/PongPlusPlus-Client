#include "shader.h"

// Shader constuctor. Creates all necessary shader and binds them to the program
Shader::Shader(const std::string& filename){

  // Create the program and shaders
  m_program = glCreateProgram();
  m_shaders[0] = createShader(filename+".vs", GL_VERTEX_SHADER);
  m_shaders[1] = createShader(filename+".fs", GL_FRAGMENT_SHADER);

  for(unsigned char i = 0; i < NUM_SHADERS; i++){
    glAttachShader(m_program, m_shaders[i]);
  }

  glBindAttribLocation(m_program, 0, "position");

  glLinkProgram(m_program);
  checkShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");

  glValidateProgram(m_program);
  checkShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");

  bind();
}

Shader::~Shader(){
  for(unsigned char i = 0; i < NUM_SHADERS; i++){
    glDetachShader(m_program, m_shaders[i]);
    glDeleteShader(m_shaders[i]);
  }
  glDeleteProgram(m_program);
}

GLuint Shader::createShader(const std::string& filename, GLenum shaderType){
  GLuint shader = glCreateShader(shaderType);
  FileLoader file(filename);
  std::string* shaderData = file.GetData();
  if(shaderData->length() == 0){
    std::cerr << "Error loading shader" << std::endl;
  } else {

    if(shader == 0){
      std::cerr << "Error: Shader creation failed" << std::endl;
    }

    const GLchar* shaderSourceString[1];
    GLint shaderSourceStringLengths[1];

    shaderSourceString[0] = shaderData->c_str();
    shaderSourceStringLengths[0] = shaderData->length();

    glShaderSource(shader, 1, shaderSourceString, shaderSourceStringLengths);
    glCompileShader(shader);
    checkShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");
  }

  return shader;
}

void Shader::bind(){
  glUseProgram(m_program);
}

void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& err){
  GLint success = 0;
  GLchar error[1024] = { 0 };

  if(isProgram){
    glGetProgramiv(shader, flag, &success);
  } else {
    glGetShaderiv(shader, flag, &success);
  }

  if(success == GL_FALSE){
    if(isProgram){
      glGetProgramInfoLog(shader, sizeof(error), NULL, error);
    } else {
      glGetShaderInfoLog(shader, sizeof(error), NULL, error);
    }

    std::cerr << err << ": '" << error << "'" << std::endl;
  }
}
