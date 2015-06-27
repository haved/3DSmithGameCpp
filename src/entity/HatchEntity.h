#pragma once

#include <memory>
#include "Entity.h"
#include "InteractiveEntity.h"
#include "../IView.h"
#include "../rendering/Mesh.h"
#include <glm/glm.hpp>

class SmithGame;
class Scene;

class HatchEntity : public Entity, public InteractiveEntity, public IView
{
public:
	HatchEntity(SmithGame* game, std::shared_ptr<Mesh> hatchHole, std::shared_ptr<Mesh> hatch, glm::vec3& hatchTrans, float x, float y, float xSize, float ySize);
	~HatchEntity();
	void Update(Scene* scene);
	void Render(Scene* scene, glm::mat4& VP);

	void OnInteractionPerformed(void* source);

	void OnViewNotUsed() {}
	void OnViewChanging(std::shared_ptr<IView> prevView);
	void OnViewUsed() {}

	void UpdateView();
	void RenderView(glm::mat4& VP) {}

	glm::vec3 GetEyePos();
	glm::vec3 GetEyeTarget();
	glm::vec3 GetEyeUp();

	void* operator new(size_t size){ return _aligned_malloc(size, 16); };
	void operator delete(void* p) { _aligned_free(p); };
private:
	SmithGame* m_game;
	std::shared_ptr<Mesh> m_hatchHoleMesh;
	std::shared_ptr<Mesh> m_hatchMesh;
	glm::mat4 m_hatchTranslation;

	float m_hatchRot = 0;
	float m_hatchSpeed = 0;

	std::shared_ptr<IView> m_prevView;
};

