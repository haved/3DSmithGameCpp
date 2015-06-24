#pragma once

#include "Shader.h"
#include <glm/glm.hpp>
#include <memory>
#include <string>

class BasicShader
{
public:
	Shader* m_shader;
	BasicShader(const std::string& path);
	~BasicShader();
	void SetModelspaceMatrix(glm::mat4& modelspace);
	void SetMVP(glm::mat4& MVP);
	void SetColor(glm::vec4& color);
	void ResetColor();
	void Bind();
private:
	GLuint modelspaceId;
	GLuint MVPId;
	GLuint colorId;
};