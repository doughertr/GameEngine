#include "GameObject.h"

#include "../Visuals/Mesh.h"


namespace Objects
{
	GameObject::GameObject()
	{
	}


	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
	}
	Visuals::Mesh GameObject::GetMesh()
	{
		return Visuals::Mesh();
	}
}
