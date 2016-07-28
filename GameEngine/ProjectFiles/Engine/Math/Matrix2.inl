Matrix2::Matrix2(float r0c0, float r0c1, float r1c0, float r1c1)
{
	members[0] = Vector2(r0c0, r1c0);
	members[1] = Vector2(r0c1, r1c1);
}
Matrix2::Matrix2(float matrix[2][2])
{
	members[0] = Vector2(matrix[0][0], matrix[1][0]);
	members[1] = Vector2(matrix[0][1], matrix[1][1]);
}
Vector2 & Matrix2::operator[](int index)
{
	return this->members[index];
}
Vector2 Matrix2::operator[](int index) const
{
	return this->members[index];
}
Matrix2 Matrix2::rotate(float radians)
{
	float cosResult = cos(radians);
	float sinResult = sin(radians);

	return Matrix2(cosResult, -sinResult,
				   sinResult,  cosResult);
}
//non member functions
Vector2 operator*(const Matrix2& matrix, const Vector2& vector)
{
	return Vector2(vector[0] * matrix[0] + vector[1] * matrix[1]);
}
std::ostream& operator<<(std::ostream& os, const Matrix2& matrix) 
{
	return os;
}