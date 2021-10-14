#include "Cube.h"

Cube::Vertex* Cube::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	Vertex* vertices = nullptr;
	vertexCount = 36;
	triCount = 12;

	vertices = new Vertex[vertexCount];

	/*
		AFBEGDHC

		A6------E5		G7------C4
		|		|		|		|	
		F1------B0		D2------H3


	*/
	
	//Front Face 012-230
	initializeCorner(vertices, vertexCount, 0,  {  1.0f,		 1.0f,		 1.0f, });  //B0
	initializeCorner(vertices, vertexCount, 1,  { -1.0f,		 1.0f,		 1.0f, });  //F1
	initializeCorner(vertices, vertexCount, 2,  { -1.0f,		-1.0f,		 1.0f, });  //D2

	initializeCorner(vertices, vertexCount, 3,  { -1.0f,		-1.0f,		 1.0f, });  //D2
	initializeCorner(vertices, vertexCount, 4,  {  1.0f,		-1.0f,		 1.0f, });  //H3
	initializeCorner(vertices, vertexCount, 5,  {  1.0f,		 1.0f,		 1.0f, });  //B0

	//Right Face 034-450
	initializeCorner(vertices, vertexCount, 6,  {  1.0f,		 1.0f,		 1.0f, });  //B0
	initializeCorner(vertices, vertexCount, 7,  {  1.0f,		-1.0f,		 1.0f, });  //H3
	initializeCorner(vertices, vertexCount, 8,  {  1.0f,		-1.0f,		-1.0f, });  //C4

	initializeCorner(vertices, vertexCount, 9,  {  1.0f,		-1.0f,		-1.0f, });  //C4
	initializeCorner(vertices, vertexCount, 10, {  1.0f,		 1.0f,		-1.0f, });  //E5
	initializeCorner(vertices, vertexCount, 11, {  1.0f,		 1.0f,		 1.0f, });  //B0

	//Top Face 056-610
	initializeCorner(vertices, vertexCount, 12, {  1.0f,		 1.0f,		 1.0f, });  //B0
	initializeCorner(vertices, vertexCount, 13, {  1.0f,		 1.0f,		-1.0f, });  //E5
	initializeCorner(vertices, vertexCount, 14, { -1.0f,		 1.0f,		-1.0f, });  //A6

	initializeCorner(vertices, vertexCount, 15, { -1.0f,		 1.0f,		-1.0f, });  //A6
	initializeCorner(vertices, vertexCount, 16, { -1.0f,		 1.0f,		 1.0f, });  //F1
	initializeCorner(vertices, vertexCount, 17, {  1.0f,		 1.0f,		 1.0f, });  //B0

	//Back Face 765-547
	initializeCorner(vertices, vertexCount, 18, { -1.0f,		-1.0f,		-1.0f, });  //G7
	initializeCorner(vertices, vertexCount, 19, { -1.0f,		 1.0f,		-1.0f, });  //A6
	initializeCorner(vertices, vertexCount, 20, {  1.0f,		 1.0f,		-1.0f, });  //E5

	initializeCorner(vertices, vertexCount, 21, {  1.0f,		 1.0f,		-1.0f, });  //E5
	initializeCorner(vertices, vertexCount, 22, {  1.0f,		-1.0f,		-1.0f, });  //C4
	initializeCorner(vertices, vertexCount, 23, { -1.0f,		-1.0f,		-1.0f, });  //G7

	//Bottom Face 743-327
	initializeCorner(vertices, vertexCount, 24, { -1.0f,		-1.0f,		-1.0f, });  //G7
	initializeCorner(vertices, vertexCount, 25, {  1.0f,		-1.0f,		-1.0f, });  //C4
	initializeCorner(vertices, vertexCount, 26, {  1.0f,		-1.0f,		 1.0f, });  //H3

	initializeCorner(vertices, vertexCount, 27, {  1.0f,		-1.0f,		 1.0f, });  //H3
	initializeCorner(vertices, vertexCount, 28, { -1.0f,		-1.0f,		 1.0f, });  //D2
	initializeCorner(vertices, vertexCount, 29, { -1.0f,		-1.0f,		-1.0f, });  //G7

	//Left Face 721-167
	initializeCorner(vertices, vertexCount, 30, { -1.0f,		-1.0f,		-1.0f, });  //G7
	initializeCorner(vertices, vertexCount, 31, { -1.0f,		-1.0f,		 1.0f, });  //D2
	initializeCorner(vertices, vertexCount, 32, { -1.0f,		 1.0f,		 1.0f, });  //F1

	initializeCorner(vertices, vertexCount, 33, { -1.0f,		 1.0f,		 1.0f, });  //F1
	initializeCorner(vertices, vertexCount, 34, { -1.0f,		 1.0f,		-1.0f, });  //A6
	initializeCorner(vertices, vertexCount, 35, { -1.0f,		-1.0f,		-1.0f, });  //G7
	

	return vertices;
}

void Cube::initializeCorner(Vertex* vertices, int vertexCount, int index, glm::vec3 coordinates)
{
	for (int i = index; i < vertexCount; i += 8) {
		vertices[i].position = glm::vec4(coordinates * 0.5f, 1.0f);
		vertices[i].normal = glm::vec4(coordinates, 0.0f);
		vertices[i].color = m_color;
	}
}
