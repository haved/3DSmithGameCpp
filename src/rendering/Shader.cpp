#include "shader.h"
#include <iostream>


void Shader::LoadFromFiles(const std::string& vertexShader, const std::string& fragmentShader)
{
	m_shader.loadFromFile(vertexShader, fragmentShader);
	sf::Shader::bind(&m_shader);
	glGetIntegerv(GL_CURRENT_PROGRAM, &ProgramID);
	std::cout << "Program loaded:" << ProgramID << std::endl;
}

GLuint Shader::GetUniformLocation(const std::string& name)
{
	return glGetUniformLocation(ProgramID, name.c_str());
}