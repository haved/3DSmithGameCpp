#pragma once

#include "Shader.h"
#include <string>
#include <glm/glm.hpp>

class ColorShader
{
public:
	Shader m_shader;
	ColorShader(const std::string& path);
	void SetMVP(glm::mat4& MVP);
	void SetColor(glm::vec4& color);
	void Bind();
private:
	GLuint MVPId;
	GLuint colorId;
};

