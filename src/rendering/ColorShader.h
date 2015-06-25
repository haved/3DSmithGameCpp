#pragma once

#include "Shader.h"
#include <string>
#include <glm/glm.hpp>

class ColorShader
{
public:
	Shader* shader;
	ColorShader(const std::string& path);
	~ColorShader();
	void SetMVP(glm::mat4& MVP);
	void SetColor(glm::vec4& color);
	void Bind();
private:
	GLuint MVPId;
	GLuint colorId;
};

