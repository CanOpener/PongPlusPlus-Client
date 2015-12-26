#include "mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVertices){
  m_drawCount = numVertices;

  glGenVertexArrays(1, &m_vertexArrayObject);
  glBindVertexArray(m_vertexArrayObject);

  glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
  glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
  glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

  glBindVertexArray(0);
}

Mesh::~Mesh(){
  glDeleteVertexArrays(1, m_vertexArrayObject);
}

void Mesh::Draw(){

}
