#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 36;
	triCount = 12;

	vertices = new Vertex[vertexCount];

	initailizeCorner(vertices, vertexCount, 0, { -1.0f,  1.0f,	 -1.0f,  });  //A
	initailizeCorner(vertices, vertexCount, 1, {  1.0f,	 1.0f,	  1.0f,  });  //B
	initailizeCorner(vertices, vertexCount, 2, {  1.0f,	-1.0f,	 -1.0f,  });  //C
	initailizeCorner(vertices, vertexCount, 3, { -1.0f, -1.0f,	  1.0f,  });  //D
	initailizeCorner(vertices, vertexCount, 4, {  1.0f,	 1.0f,	 -1.0f,  });  //E
	initailizeCorner(vertices, vertexCount, 5, { -1.0f,  1.0f,	  1.0f,  });  //F
	initailizeCorner(vertices, vertexCount, 6, { -1.0f, -1.0f,	 -1.0f,  });  //G
	initailizeCorner(vertices, vertexCount, 7, {  1.0f, -1.0f,	  1.0f,  });  //H

	return vertices;
}

void Cube::initailizeCorner(Vertex* vertices, int vertexCount, int index, glm::vec3 coordinates)
{
	for (int i = index; i < vertexCount; i += 8) {
		vertices[i].position = glm::vec4(coordinates * 0.5f, 1.0f);
		vertices[i].normal = glm::vec4(coordinates, 0.0f);
		vertices[i].color = m_color;
	}
}
