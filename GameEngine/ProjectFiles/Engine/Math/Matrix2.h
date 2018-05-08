#ifndef ENGINE_MATRIX_2
#define ENGINE_MATRIX_2
#include "Vector2.h"

namespace RyEngine
{
namespace Math
{
	//MATRIX2 FORMAT
	/*

	Basis Vector#: (0),(1)
	...........(x)| 1 , 0 |
	...........(y)| 0 , 1 |

	*/
	template<template T>
	class Matrix2
	{
	public:
		union
		{
			struct
			{
				T r0c0; T r0c1;
				T r1c0; T r1c1;
			};
			T val1d[4];
			T val2d[2][2];
		};

		explicit inline Matrix2(T r0c0 = 1.0f, T r0c1 = 0.0f, 
								T r1c0 = 0.0f, T r1c1 = 1.0f);

		explicit inline Matrix2(T values[4]);
		explicit inline Matrix2(T values[2][2]);

		inline static Matrix2 rotate(float radians);

		inline Vector2& operator[](int index);
		inline Vector2 operator[](int index) const;
	};
	inline Vector2 operator*(const Matrix2& matrix, const Vector2& vector);
	inline std::ostream& operator<<(std::ostream& os, const Matrix2& matrix);
}
}

#endif

