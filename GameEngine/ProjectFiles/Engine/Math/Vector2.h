#ifndef ENGINE_VECTOR_2
#define ENGINE_VECTOR_2

#include <iostream>
#include "Vector3.h"

namespace RyEngine
{
namespace Math
{
	template<typename T>
	class Vector2
	{
	public:
		union 
		{
			struct
			{
				T x;
				T y;
			};
			T val[2];
		};
		// -----------------------------------------
		// CONSTRUCTORS 
		// -----------------------------------------
		explicit Vector2(T xVal, T yVal) : x(xVal), y(yVal) {}
		Vector2() : x(), y() {}

		// -----------------------------------------
		// VECTOR MATH OPERATORS
		// -----------------------------------------
		inline Vector2<T> operator+(const Vector2<T> &other);
		inline Vector2<T>& operator+=(const Vector2<T> &other);
		inline Vector2<T> operator-(const Vector2<T> &other);
		inline Vector2<T>& operator-=(const Vector2<T> &other);
		template<typename TDot = T> inline TDot operator*(const Vector2<T> &other);

		// -----------------------------------------
		// VECTOR PROPERTIES
		// -----------------------------------------
		template<typename TAngle = T> inline TAngle angle(const Vector2<T> &other);
		template<typename TMag = T> inline TMag magnitude();
		template<typename TLen = T> __forceinline TLen length();
		template<typename TMagSq = T> inline TMagSq magnitudeSquared();
		template<typename TLenSq = T> __forceinline TLenSq lengthSquared();
		inline void normalize();

		// -----------------------------------------
		// SCALAR MATH OPERATORS
		// -----------------------------------------
		template<typename TScalar = T> inline Vector2<T> operator*(TScalar scalar);
		template<typename TScalar = T> inline friend Vector2<T> operator*(TScalar scalar, const Vector2<T> &vec)
		{
			return Vector2<T>(vec.x * scalar, vec.y * scalar);
		}
		template<typename TScalar = T> inline Vector2<T>& operator*=(TScalar scalar);
		template<typename TScalar = T> inline Vector2<T> operator/(TScalar scalar);
		template<typename TScalar = T> inline friend Vector2<T> operator/(TScalar scalar, const Vector2<T> &vec)
		{
			return Vector2<T>(vec->x / scalar, vec->y / scalar);
		}
		template<typename TScalar = T> inline Vector2<T>& operator/=(TScalar scalar);

		// -----------------------------------------
		// COMPARASON
		// -----------------------------------------
		inline bool operator==(const Vector2<T> &other);
		inline bool operator!=(const Vector2<T> &other);

		inline T & operator[](int index);
		inline T operator[](int index) const;

		inline std::ostream& operator<<(std::ostream& os);

		// Static Vector functions
		static Vector2<T> normalize(Vector2<T> &vec);
	};

}
}
#endif
