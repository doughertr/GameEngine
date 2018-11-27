#ifndef ENGINE_GAME_OBJECT
#define ENGINE_GAME_OBJECT 

#include "../Math/Vector3.h"

namespace Visuals {
	class Mesh;
}
//class Math::Vector3;

namespace Objects
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Update();
		Visuals::Mesh GetMesh();

		Math::Vector3 position;
		Math::Vector3 velocity;
		Math::Vector3 acceleration;

	private:
		Visuals::Mesh *m_objMesh;
	};
}
#endif


