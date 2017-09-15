#include "Vector2.h"
#include "Vector3.h"

#include <cmath>

namespace RyEngine 
{
namespace Math
{
	template<typename T>
	inline Vector2<T> Vector2<T>::operator+(const Vector2<T> &other)
	{
		return Vector2<T>(this->x + other.x, this->y + other.y);
	}
	template<typename T>
	inline Vector2<T>& Vector2<T>::operator+=(const Vector2<T> &other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	template<typename T>
	inline Vector2<T> Vector2<T>::operator-(const Vector2<T> &other)
	{
		return Vector2<T>(this->x - other.x, this->y - other.y);
	}
	template<typename T>
	inline Vector2<T>& Vector2<T>::operator-=(const Vector2<T> &other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	template<typename T>
	template<typename TDot>
	inline TDot Vector2<T>::operator*(const Vector2<T> &other)
	{
		return (this->x*other->x) + (this->y*other->y);
	}
	//TODO: implement Vecor 3 first
	template<typename T>
	inline Vector3<T> Vector2<T>::operator^(const Vector2<T> &other)
	{

	}
	template<typename T>
	inline Vector3<T> Vector2<T>::cross(const Vector2<T> &other)
	{

	}
	template<typename T> 
	template<typename TAngle> 
	inline TAngle Vector2<T>::angle(const Vector2<T> &other)
	{
		return ((*this) * other) / (this->length() * other.length());
	}
	template<typename T> 
	template<typename TMag> 
	inline TMag Vector2<T>::magnitude()
	{
		return sqrt(pow(this->x, 2) + pow(this - y, 2));
	}
	template<typename T> 
	template<typename TLen> 
	__forceinline TLen Vector2<T>::length()
	{
		return this->magnitude();
	}
	template<typename T> 
	template<typename TMagSq>
	inline TMagSq Vector2<T>::magnitudeSquared()
	{
		return pow(this->x, 2) + pow(this - y, 2);
	}
	template<typename T> 
	template<typename TLenSq> 
	__forceinline TLenSq Vector2<T>::lengthSquared()
	{
		return this->magnitudeSquared();
	}
	template<typename T> 
	inline void Vector2<T>::normalize()
	{
		T length = this->length<T>();
		this->x /= length;
		this->y /= length;
	}
	template<typename T>
	template<typename TScalar>
	inline Vector2<T> Vector2<T>::operator*(TScalar scalar)
	{
		return Vector2<T>(this->x * scalar, this->y * scalar);
	}
	template<T>
	template<typename TScalar> 
	inline friend Vector2<T> Vector2<T>::operator*(TScalar scalar, const Vector2<T> &vec)
	{
		return Vector2<T>(vec.x * scalar, vec.y * scalar);
	}
	template<T>
	template<typename TScalar> 
	inline Vector2<T>& Vector2<T>::operator*=(TScalar scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		return *this;
	}
	template<T>
	template<typename TScalar> 
	inline Vector2<T> Vector2<T>::operator/(TScalar scalar)
	{
		return Vector2<T>(this->x / scalar, this->y / scalar);
	}
	template<T>
	template<typename TScalar> 
	inline friend Vector2<T> Vector2<T>::operator/(TScalar scalar, const Vector2<T> &vec)
	{
		return Vector2<T>(vec->x / scalar, vec->y / scalar);
	}
	template<T>
	template<typename TScalar> 
	inline Vector2<T>& Vector2<T>::operator/=(TScalar scalar)
	{
		this->x /= scalar;
		this->y /= scalar;
		return *this;
	}
	template<T>
	inline bool Vector2<T>::operator==(const Vector2<T> &other)
	{
		return (this->x == other.x) && (this->y == other.y);
	}
	template<T>
	inline bool Vector2<T>::operator!=(const Vector2<T> &other)
	{
		return !operator==(other);
	}
	template<typename T>
	inline T& Vector2<T>::operator[](int index)
	{
		switch (index)
		{
		case 0:
			return this->x;
			break;
		case 1:
			return this->y;
			break;
		default:
			throw std::out_of_range("2D Vector can only have two coordinates");
			break;
		}
	}
	template<typename T>
	inline T Vector2<T>::operator[](int index) const
	{
		switch (index)
		{
		case 0:
			return this->x;
			break;
		case 1:
			return this->y;
			break;
		default:
			throw std::out_of_range("2D Vector can only have two coordinates");
			break;
		}
	}

	//Specific defines
	template class Vector2<int>;
	template class Vector2<long>;
	template class Vector2<long long>;
	template class Vector2<unsigned int>;
	template class Vector2<unsigned long>;
	template class Vector2<unsigned long long>;
	template class Vector2<float>;
	template class Vector2<double>;
	template class Vector2<long double>;
}
}



//Vector2& Vector2::operator+=(const Vector2 &vec)
//{
//	this->x = this->x + vec.x;
//	this->y = this->y + vec.y;
//	return *this;
//}
//Vector2& Vector2::operator-=(const Vector2 &vec)
//{
//	this->x = this->x - vec.x;
//	this->y = this->y - vec.y;
//	return *this;
//}
//Vector2& Vector2::operator*=(float scalar)
//{
//	this->x = this->x * scalar;
//	this->y = this->y * scalar;
//	return *this;
//}
//Vector2& Vector2::operator/=(float scalar)
//{
//	this->x = this->x / scalar;
//	this->y = this->y / scalar;
//	return *this;
//}
//float & Vector2::operator[](int index)
//{
//	switch (index)
//	{
//	case 0:
//		return this->x;
//		break;
//	case 1:
//		return this->y;
//		break;
//	default:
//		throw std::out_of_range("2D Vector can only have two coordinates");
//		break;
//	}
//}
//
//float Vector2::operator[](int index) const
//{
//	switch (index)
//	{
//	case 0:
//		return this->x;
//		break;
//	case 1:
//		return this->y;
//		break;
//	default:
//		throw std::out_of_range("2D Vector can only have two coordinates");
//		break;
//	}
//}
////non member functions
//Vector2 operator+(const Vector2 &vec1, const Vector2 &vec2)
//{
//	return Vector2(vec1.x + vec2.x, vec1.y + vec2.y);
//}
//Vector2 operator-(const Vector2 &vec1, const Vector2 &vec2)
//{
//	return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
//}
//Vector2 operator*(float scalar, const Vector2 &vec2)
//{
//	return Vector2(vec2.x * scalar, vec2.y * scalar);
//}
//Vector2 operator*(const Vector2 &vec2, float scalar)
//{
//	return scalar * vec2;
//}
//float operator*(const Vector2 &vec1, const Vector2 &vec2)
//{
//	return (vec1.x*vec2.x) + (vec1.y*vec2.y);
//}
//std::ostream& operator<<(std::ostream& os, const Vector2& vector)
//{
//	os << "<" << vector.x << ", " << vector.y << ">";
//	return os;
//}

