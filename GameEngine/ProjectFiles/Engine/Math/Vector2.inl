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