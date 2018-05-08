#ifndef ENGINE_VECTOR_3
#define ENGINE_VECTOR_3
#include <iostream>

namespace RyEngine
{
namespace Math
{
	template<typename T>
	class Vector3
	{
	public:
		union {
			struct
			{
				T x;
				T y;
				T z;
			};
			T val[3];
		};
		explicit Vector3(T xVal, T yVal, T zVal) : x(xVal), y(yVal), z(zVal){}
		explicit Vector3(T xVal, T yVal) : x(xVal), y(yVal), z() {}
		Vector3() : x(), y(), z() {}

		// Vector mathmatics
		inline Vector3<T> operator+(const Vector3<T> &other);
		inline Vector3<T>& operator+=(const Vector3<T> &other);
		inline Vector3<T> operator-(const Vector3<T> &other);
		inline Vector3<T>& operator-=(const Vector3<T> &other);
		template<typename TDot = T> inline TDot operator*(const Vector3<T> &other);
		inline Vector3<T> operator^(const Vector3<T> &other);

		// Vector properties
		inline Vector3<T> cross(const Vector3<T> &other);
		template<typename TAngle = T> inline TAngle angle(const Vector3<T> &other);
		inline T magnitude();
		__forceinline T length();
		template<typename TMagSq = T> inline TMagSq magnitudeSquared();
		template<typename TLenSq = T> __forceinline TLenSq lengthSquared();
		inline void normalize();

		// Scalar mathmatics
		template<typename TScalar = T> inline Vector3<T> operator*(TScalar scalar);
		template<typename TScalar = T> inline friend Vector3<T> operator*(TScalar scalar, const Vector3<T> &vec)
		{
			return Vector3<T>(vec.x * scalar, vec.y * scalar, vec.z * scalar);
		}
		template<typename TScalar = T> inline Vector3<T>& operator*=(TScalar scalar);
		template<typename TScalar = T> inline Vector3<T> operator/(TScalar scalar);
		template<typename TScalar = T> inline friend Vector3<T> operator/(TScalar scalar, const Vector3<T> &vec)
		{
			return Vector3<T>(vec->x / scalar, vec->y / scalar, vec->z / scalar);
		}
		template<typename TScalar = T> inline Vector3<T>& operator/=(TScalar scalar);

		// Comparison operators
		inline bool operator==(const Vector3<T> &other);
		inline bool operator!=(const Vector3<T> &other);

		inline T & operator[](int index);
		inline T operator[](int index) const;

		inline std::ostream& operator<<(std::ostream& os);

		// Static Vector functions
		static Vector3<T> normalize(Vector3<T> &vec)
		{
			T len = vec.length();
			return Vector3<T>(vec.x/len, vec.y/len, vec.z/len);
		}
	};

}
}

#endif
