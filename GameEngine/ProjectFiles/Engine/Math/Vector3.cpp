#include "Vector3.h"

#include <cmath>

namespace RyEngine
{
	namespace Math
	{
		template<typename T>
		inline Vector3<T> Vector3<T>::operator+(const Vector3<T> &other)
		{
			return Vector3<T>(this->x + other.x, this->y + other.y, this->z + other.z);
		}
		template<typename T>
		inline Vector3<T>& Vector3<T>::operator+=(const Vector3<T> &other)
		{
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}
		template<typename T>
		inline Vector3<T> Vector3<T>::operator-(const Vector3<T> &other)
		{
			return Vector3<T>(this->x - other.x, this->y - other.y, this->z - other.z);
		}
		template<typename T>
		inline Vector3<T>& Vector3<T>::operator-=(const Vector3<T> &other)
		{
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}
		template<typename T>
		template<typename TDot>
		inline TDot Vector3<T>::operator*(const Vector3<T> &other)
		{
			return (this->x * other.x) + (this->y * other.y) + (this->z * other.z)
		}
		//TODO: implement Vector 3 first
		template<typename T>
		inline Vector3<T> Vector3<T>::operator^(const Vector3<T> &other)
		{
			return this->cross(other);
		}
		template<typename T>
		inline Vector3<T> Vector3<T>::cross(const Vector3<T> &other)
		{
			return Vector3<T>(
				this->y * other.z - this->z * other.y,
				this->z * other.x - this->x * other.z,
				this->x * other.y - this->y * other.x);
		}
		template<typename T>
		template<typename TAngle>
		inline TAngle Vector3<T>::angle(const Vector3<T> &other)
		{
			return ((*this) * other) / (this->length() * other.length());
		}
		template<typename T>
		inline T Vector3<T>::magnitude()
		{
			return static_cast<T>(sqrt(pow<T>(this->x, 2) + pow<T>(this->y, 2) + pow<T>(this->z, 2)));
		}
		template<typename T>
		__forceinline T Vector3<T>::length()
		{
			return this->magnitude();
		}
		template<typename T>
		template<typename TMagSq>
		inline TMagSq Vector3<T>::magnitudeSquared()
		{
			return pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2);
		}
		template<typename T>
		template<typename TLenSq>
		__forceinline TLenSq Vector3<T>::lengthSquared()
		{
			return this->magnitudeSquared();
		}
		template<typename T>
		inline void Vector3<T>::normalize()
		{
			T length = this->length();
			this->x /= length;
			this->y /= length;
			this->z /= length;
		}
		template<typename T>
		template<typename TScalar>
		inline Vector3<T> Vector3<T>::operator*(TScalar scalar)
		{
			return Vector3<T>(this->x * scalar, this->y * scalar, this->z * scalar);
		}
		template<typename T>
		template<typename TScalar>
		inline Vector3<T>& Vector3<T>::operator*=(TScalar scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			this->z *= scalar;
			return *this;
		}
		template<typename T>
		template<typename TScalar>
		inline Vector3<T> Vector3<T>::operator/(TScalar scalar)
		{
			return Vector3<T>(this->x / scalar, this->y / scalar, this->z / scalar);
		}
		template<typename T>
		template<typename TScalar>
		inline Vector3<T>& Vector3<T>::operator/=(TScalar scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			this->z /= scalar;
			return *this;
		}
		template<typename T>
		inline bool Vector3<T>::operator==(const Vector3<T> &other)
		{
			return (this->x == other.x) && (this->y == other.y) && (this->z == other.z);
		}
		template<typename T>
		inline bool Vector3<T>::operator!=(const Vector3<T> &other)
		{
			return !operator==(other);
		}
		template<typename T>
		inline T& Vector3<T>::operator[](int index)
		{
			switch (index)
			{
			case 0:
				return this->x;
				break;
			case 1:
				return this->y;
				break;
			case 2:
				return this->z;
				break;
			default:
				throw std::out_of_range("3D Vector can only have three coordinates");
				break;
			}
		}
		template<typename T>
		inline T Vector3<T>::operator[](int index) const
		{
			switch (index)
			{
			case 0:
				return this->x;
				break;
			case 1:
				return this->y;
				break;
			case 2:
				return this->z;
				break;
			default:
				throw std::out_of_range("3D Vector can only have three coordinates");
				break;
			}
		}

		template<typename T>
		inline std::ostream & Vector3<T>::operator<<(std::ostream & os)
		{
			os << "<" << this->x << ", " << this->y << ", " << this->z << ">";
			return os;
		}




		//Specific defines
		template class Vector3<int>;
		template class Vector3<long>;
		template class Vector3<long long>;
		template class Vector3<unsigned int>;
		template class Vector3<unsigned long>;
		template class Vector3<unsigned long long>;
		template class Vector3<float>;
		template class Vector3<double>;
		template class Vector3<long double>;
	}
}