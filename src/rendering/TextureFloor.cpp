#include "../GlobalFields.h"
#include "TextureFloor.h"
#include <glm/gtc/matrix_transform.hpp>

TextureFloor::TextureFloor(std::shared_ptr<sf::Texture> texture, glm::vec2& sampleSize, float width, float length, float yPos)
{
	m_texture = texture;
	m_sampleSize = sampleSize;

	modelspace = glm::translate(modelspace, glm::vec3(-width / 2, -length / 2, yPos));
	modelspace = glm::scale(modelspace, glm::vec3(width, length, 1));
	m_color = glm::vec4(1, 1, 1, 1);
}

TextureFloor::~TextureFloor()
{
}

void TextureFloor::Render(Scene* scene, glm::mat4& VP)
{
	sf::Texture::bind( m_texture.get() );
	Global.TextureShaderInstance->Bind();
	Global.TextureShaderInstance->SetColor(m_color);
	Global.TextureShaderInstance->SetSampleUV(glm::vec2(0,0));
	Global.TextureShaderInstance->SetSampleSize(m_sampleSize);
	Global.TextureShaderInstance->SetMVP(VP*modelspace);
	Global.OrthoRenderingEngine->m_flat->Draw();
}
