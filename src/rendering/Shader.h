#pragma once

#include <GL/glew.h>
#include <string>
#include <SFML/Graphics/Shader.hpp>

class Shader
{
public:
	sf::Shader m_shader;
	void LoadFromFiles(const std::string& vertexShader, const std::string& fragmentShader);
	GLint ProgramID;
	GLuint GetUniformLocation(const std::string& name);
};

