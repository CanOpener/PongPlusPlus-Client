#ifndef MESH_H
#define MESH_H

#include "object3d.h"
#include "vertex.h"

class Mesh : Object3D {

private:
  enum {
    NUM_BUFFERS,
    POSITION_VB
  };

  GLuint m_vertexArrayObject;
  GLuint m_vertexArrayBuffers[NUM_BUFFERS];
  unsigned int m_drawCount;

public:
  Mesh(Vertex* vertices, unsigned int numVertices);
  ~Mesh();

  void Draw();
};

#endif
