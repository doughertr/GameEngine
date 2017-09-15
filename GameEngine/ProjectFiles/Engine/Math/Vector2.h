#ifndef ENGINE_VECTOR_2
#define ENGINE_VECTOR_2
#include <iostream>

namespace RyEngine
{
namespace Math
{
	template<typename T>
	class Vector2
	{
	public:
		union {
			struct
			{
				T x;
				T y;
			};
			T val[2];
		};
		explicit Vector2(T xVal = 0.0f, T yVal = 0.0f) : x(xVal), y(yVal) {}

		// Vector mathmatics
		inline Vector2<T> operator+(const Vector2<T> &other);
		inline Vector2<T>& operator+=(const Vector2<T> &other);
		inline Vector2<T> operator-(const Vector2<T> &other);
		inline Vector2<T>& operator-=(const Vector2<T> &other);
		template<typename TDot = T> inline TDot operator*(const Vector2<T> &other);
		inline Vector3<T> operator^(const Vector2<T> &other);

		// Vector properties
		inline Vector3<T> cross(const Vector2<T> &other);
		template<typename TAngle = T> inline TAngle angle(const Vector2<T> &other);
		template<typename TMag = T> inline TMag magnitude();
		template<typename TLen = T> __forceinline TLen length();
		template<typename TMagSq = T> inline TMagSq magnitudeSquared();
		template<typename TLenSq = T> __forceinline TLenSq lengthSquared();
		inline void normalize();

		// Scalar mathmatics
		template<typename TScalar = T> inline Vector2<T> operator*(TScalar scalar);
		template<typename TScalar = T> inline friend Vector2<T> operator*(TScalar scalar, const Vector2<T> &vec);
		template<typename TScalar = T> inline Vector2<T>& operator*=(TScalar scalar);
		template<typename TScalar = T> inline Vector2<T> operator/(TScalar scalar);
		template<typename TScalar = T> inline friend Vector2<T> operator/(TScalar scalar, const Vector2<T> &vec);
		template<typename TScalar = T> inline Vector2<T>& operator/=(TScalar scalar);

		// Comparison operators
		inline bool operator==(const Vector2<T> &other);
		inline bool operator!=(const Vector2<T> &other);

		inline T & operator[](int index);
		inline T operator[](int index) const;

		inline std::ostream& operator<<(std::ostream& os, const Vector2& vector);

		// Static Vector functions
		static Vector2<T> normalize(const Vector2<T> &vec);
	};

}
}
#endif
