#include "ColorShader.h"
#include "../GlobalFields.h"

ColorShader::ColorShader(const std::string& path)
{
	m_shader.LoadFromFiles(path + "ColorVS.glslvs", path + "ColorFS.glslfs");
	MVPId = m_shader.GetUniformLocation("MVP");
	colorId = m_shader.GetUniformLocation("color");
	Global.ColorShaderInstance = this;
}

void ColorShader::SetMVP(glm::mat4& MVP)
{
	glUniformMatrix4fv(MVPId, 1, GL_FALSE, &MVP[0][0]);
}

void ColorShader::SetColor(glm::vec4& color)
{
	glUniform4f(colorId, color.x, color.y, color.z, color.w);
}

void ColorShader::Bind()
{
	glUseProgram(m_shader.ProgramID);
}