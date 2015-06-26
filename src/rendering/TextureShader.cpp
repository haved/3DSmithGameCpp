#include "TextureShader.h"
#include "../GlobalFields.h"

#include <iostream>

TextureShader::TextureShader(const std::string& path)
{
	m_shader = new Shader(path + "TextureVS.glslvs", path + "TextureFS.glslfs");
	MVPId = m_shader->GetUniformLocation("MVP");
	colorId = m_shader->GetUniformLocation("color");
	sampleUVId = m_shader->GetUniformLocation("sampleUV");
	sampleSizeId = m_shader->GetUniformLocation("sampleSize");
	diffuseId = m_shader->GetUniformLocation("diffuse");
	ResetSample();
	SetDiffuse(0);
	Global.TextureShaderInstance = this;
}

TextureShader::~TextureShader()
{
	delete m_shader;
}

void TextureShader::SetMVP(glm::mat4& MVP)
{
	glUniformMatrix4fv(MVPId, 1, GL_FALSE, &MVP[0][0]);
}

void TextureShader::SetColor(glm::vec4& color)
{
	glUniform4f(colorId, color.x, color.y, color.z, color.w);
}

void TextureShader::SetSampleUV(glm::vec2& uv)
{
	glUniform2f(sampleUVId, uv.x, uv.y);
}

void TextureShader::SetSampleSize(glm::vec2& size)
{
	glUniform2f(sampleSizeId, size.x, size.y);
}

void TextureShader::SetDiffuse(GLuint textureSlot)
{
	glUniform1i(diffuseId, textureSlot);
}

void TextureShader::ResetSample()
{
	SetSampleUV(glm::vec2(0, 0));
	SetSampleSize(glm::vec2(1, 1));
}

void TextureShader::Bind()
{
	glUseProgram(m_shader->ProgramID);
}
