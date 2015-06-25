#pragma once

#include <memory>
#include "Entity.h"
#include "../rendering/Mesh.h"

class MeshEntity : public Entity
{
public:
	MeshEntity(std::shared_ptr<Mesh> mesh);
	MeshEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z);
	MeshEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z, float xSize, float ySize);
	MeshEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z, float rotX, float rotY, float rotZ);
	MeshEntity(std::shared_ptr<Mesh> mesh, float x, float y, float z, float rotX, float rotY, float rotZ, float xSize, float ySize);
	~MeshEntity();
	virtual void Render(Scene* scene, glm::mat4& VP);
	virtual void Update(Scene* scene);
	std::shared_ptr<Mesh> m_mesh;

	void* operator new (std::size_t count)
	{
		return _aligned_malloc(count, 16);
	};
	void operator delete (void* ptr)
	{
		_aligned_free(ptr);
	};
};

