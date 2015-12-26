#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex {
private:
  glm::vec3 m_pos;

public:
  Vertex(const glm::vec3& pos);
};

#endif
