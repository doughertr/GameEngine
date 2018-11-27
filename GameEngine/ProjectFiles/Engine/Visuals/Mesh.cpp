#include "Mesh.h"


#include "../Math/Vector3.h"

using namespace Math;




namespace Visuals
{
	Mesh::Mesh() : m_verticies()
	{
	}


	Mesh::~Mesh()
	{
	}

	Math::Vector3* Mesh::GetVerts()
	{
		return m_verticies.data();
	}

	void Mesh::SetVerts(Math::Vector3 * newVerts, unsigned int vertSize)
	{
		m_verticies.clear();

		for (int i = 0; i < vertSize; i++)
		{
			m_verticies.push_back(newVerts[i]);
		}
	}

	int Mesh::GetNumVerts()
	{
		return m_verticies.size();
	}
}
