#include "Light.h"
#include "gl_core_4_4.h"

Light::Light(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, bool firstLight)
{
	setDirection(direction);
	m_ambient = ambient;
	m_diffuse = diffuse;
	m_specular = specular;
	isFirstLight = firstLight;
}

void Light::onDraw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);

	if (program == -1) {
		printf("No shader bound!\n");
		return;
	}

	int lightDirection;
	int lightAmbient;
	int lightDiffuse;
	int lightSpecular;

	if (isFirstLight) {
		lightDirection = glGetUniformLocation(program, "iDirection");
		lightAmbient = glGetUniformLocation(program, "iAmbient");
		lightDiffuse = glGetUniformLocation(program, "iDiffuse");
		lightSpecular = glGetUniformLocation(program, "iSpecular");
	}
	else {
		lightDirection = glGetUniformLocation(program, "iDirection1");
		lightAmbient = glGetUniformLocation(program, "iAmbient1");
		lightDiffuse = glGetUniformLocation(program, "iDiffuse1");
		lightSpecular = glGetUniformLocation(program, "iSpecular1");
	}
	

	if (lightDirection >= 0) {
		glm::vec3 direction = getDirection();
		glUniform3f(lightDirection, direction.x, direction.y, direction.z);
	}
	if (lightAmbient >= 0) {
		glUniform3f(lightAmbient, m_ambient.x, m_ambient.y, m_ambient.z);
	}
	if (lightDiffuse >= 0) {
		glUniform3f(lightDiffuse, m_diffuse.x, m_diffuse.y, m_diffuse.z);
	}
	if (lightSpecular >= 0) {
		glUniform3f(lightSpecular, m_specular.x, m_specular.y, m_specular.z);
	}
}

glm::vec3 Light::getDirection()
{
	return getTransform()->getForward();
}

void Light::setDirection(glm::vec3 direction)
{
	getTransform()->setRotation(direction);
}
