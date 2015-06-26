#pragma once

#include "Shader.h"
#include <string>
#include <glm/glm.hpp>

class TextureShader
{
public:
	Shader* m_shader;
	TextureShader(const std::string& path);
	~TextureShader();
	
	void SetMVP(glm::mat4& MVP);
	void SetColor(glm::vec4& color);
	void SetSampleUV(glm::vec2& uv);
	void SetSampleSize(glm::vec2& size);
	void SetDiffuse(GLuint textureSlot);
	void Bind();
	void ResetSample();

private:
	GLuint MVPId;
	GLuint colorId;
	GLuint sampleUVId;
	GLuint sampleSizeId;
	GLuint diffuseId;
};

