Vector2 operator+(const Vector2 &vec1, const Vector2 &vec2)
{
	return Vector2(vec2.x + vec1.x, vec2.y + vec1.y);
}
Vector2 operator-(const Vector2 &vec1, const Vector2 &vec2)
{
	return Vector2(vec1.x - vec2.x, vec1.y - vec2.y);
}
Vector2 operator*(float scalar, const Vector2 &vec2)
{
	return Vector2(vec2.x * scalar, vec2.y * scalar);
}
Vector2 operator*(const Vector2 &vec2, float scalar)
{
	return scalar * vec2;
}
float operator*(const Vector2 &vec1, const Vector2 &vec2)
{
	return (vec1.x*vec2.x) + (vec1.y*vec2.y);
}
Vector2::Vector2(const Vector2& source)
{
	this->x = source.x;
	this->y = source.y;
}
Vector2& Vector2::operator=(const Vector2 &vec1)
{
	this->x = vec1.x;
	this->y = vec1.y;
	return *this;
}
Vector2& Vector2::operator+=(const Vector2 &vec1)
{
	this->x = this->x + vec1.x;
	this->y = this->y + vec1.y;
	return *this;
}
Vector2& Vector2::operator-=(const Vector2 &vec1)
{
	this->x = this->x - vec1.x;
	this->y = this->y - vec1.y;
	return *this;
}
Vector2& Vector2::operator*=(float scalar)
{
	this->x = this->x * scalar;
	this->y = this->y * scalar;
	return *this;
}
Vector2& Vector2::operator/=(float scalar)
{
	this->x = this->x / scalar;
	this->y = this->y / scalar;
	return *this;
}
float & Vector2::operator[](int index)
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
		throw std::out_of_range ("2D Vector can only have two coordinates");
		break;
	}
}