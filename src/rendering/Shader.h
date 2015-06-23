#pragma once

#include <GL/glew.h>
#include <string>

class Shader
{
public:
	Shader(const std::string& vertexShader, const std::string& fragmentShader);
	~Shader();
	GLuint ProgramID;
	GLuint GetUniformLocation(const std::string& name);
	std::string LoadShader(const std::string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const std::string& text, unsigned int type);
};

