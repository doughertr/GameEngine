#ifndef ENGINE_MATRIX_2
#define ENGINE_MATRIX_2
#include "Vector2.h"
namespace Math 
{
	//MATRIX FORMAT
	/*

	Vector#    (0),(1)
		   (x)| 1 , 0 |
		   (y)| 0 , 1 |
	
	*/
	struct Matrix2
	{
		Vector2 members[2];

		explicit inline Matrix2(float r0c0 = 1.0f, float r0c1 = 0.0f, float r1c0 = 0.0f, float r1c1 = 1.0f);
		inline Matrix2(float values[2][2]);
		inline Matrix2(const Matrix2& source);

		inline Vector2 & operator[](int index);
	};
	inline Vector2 operator*(const Matrix2 left, const Vector2 right);
	#include "Matrix2.inl"
}

#endif

