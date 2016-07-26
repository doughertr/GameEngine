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
Matrix2::Matrix2(const Matrix2& source)
{
	this->members[0] = source.members[0];
	this->members[1] = source.members[1];
}
Vector2 & Matrix2::operator[](int index)
{
	return this->members[index];
}


Vector2 operator*(Matrix2& matrix, Vector2& vector)
{
	return (vector[0] * matrix[0]) + (vector[1] * matrix[1]);
}

