#ifndef ENGINE_MESH
#define ENGINE_MESH

#include <vector>

namespace Math {
	class Vector3;
}

namespace Visuals
{
	class Mesh
	{
	public:
		Mesh();
		~Mesh();

		Math::Vector3* GetVerts();
		void SetVerts(Math::Vector3* newVerts, unsigned int vertSize);

		int GetNumVerts();

	private:
		std::vector<Math::Vector3> m_verticies;
	};
}
#endif


