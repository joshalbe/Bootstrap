#include "DragonWorld.h"

void DragonWorld::onStart()
{
	//Camera
	m_camera = new PlayerCamera(45.0f, 0.001f, 1000.0f);
	m_camera->getTransform()->setPosition(5.0f, 5.0f, 5.0f);
	m_camera->getTransform()->rotate(-40.0f, -135.0f, 0.0f);
	setCamera(m_camera);
	add(m_camera);

	//Light
	m_light = new Light(
		{ 1.0f, 1.0f, 1.0f },
		{ 0.25f, 0.5f, 0.5f, 1.0f },
		{ 0.5f, 1.0f, 1.0f, 1.0f },
		{ 0.5f, 1.0f, 1.0f, 1.0f }
	);
	m_light->setDirection({ -40.0f, -100.0f, 0.0f });
	add(m_light);

	//Dragon
	m_dragon = new OBJMesh();
	m_dragon->load("Dragon.obj");
	m_dragon->getTransform()->setPosition({ 0.0f, -0.70f, 0.0f });
	m_dragon->getTransform()->setScale(glm::vec3(0.5f, 0.5f, 0.5f));
	add(m_dragon);

	//Cube
	m_cube = new Cube();
	m_cube->getTransform()->setScale(glm::vec3(7.5f, 1.5f, 4.0f));
	add(m_cube);

	m_supportStruct1 = new Cube();
	m_supportStruct1->getTransform()->setPosition({ 3.0f, -4.0f, 4.0f });
	m_supportStruct1->getTransform()->setScale(glm::vec3(1.0f, 9.5f, 1.0f));
	add(m_supportStruct1);

	m_supportStruct2 = new Cube();
	m_supportStruct2->getTransform()->setPosition({ 3.0f, -4.0f, -4.0f });
	m_supportStruct2->getTransform()->setScale(glm::vec3(1.0f, 9.5f, 1.0f));
	add(m_supportStruct2);


	m_pedestal = new Cube();
	m_pedestal->getTransform()->setPosition({ 0.0f, 1.0f, 0.0f });
	m_pedestal->getTransform()->setScale(glm::vec3(20.0f, 0.5f, 20.0f));
	add(m_pedestal);
}

void DragonWorld::onEnd()
{
	destroy(m_camera);
	destroy(m_light);
	destroy(m_dragon);
	destroy(m_cube);
}
