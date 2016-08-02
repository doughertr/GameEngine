Matrix3::Matrix3(
	float r0c0, float r0c1, float r0c2,
	float r1c0, float r1c1, float r1c2,
	float r2c0, float r2c1, float r2c2)
{
	basisVector0 = Vector3(r0c0, r1c0, r2c0);
	basisVector1 = Vector3(r0c1, r1c1, r2c1);
	translationVector = Vector3(r0c2, r1c2, r2c2);
}
Matrix3::Matrix3(float values[3][3])
{
	basisVector0 = Vector3(values[0][0], values[1][0], values[2][0]);
	basisVector1 = Vector3(values[0][1], values[1][1], values[2][1]);
	translationVector = Vector3(values[0][2], values[1][2], values[2][2]);
}
Vector3 & Matrix3::operator[](int index)
{
	switch (index)
	{
	case 0:
		return basisVector0;
		break;
	case 1:
		return basisVector1;
		break;
	case 2:
		return translationVector;
		break;
	default:
		throw std::out_of_range("3D Matrix can only have a max of three Vectors");
		break;
	}
}
Vector3 Matrix3::operator[](int index) const
{
	switch (index)
	{
	case 0:
		return basisVector0;
		break;
	case 1:
		return basisVector1;
		break;
	case 2:
		return translationVector;
		break;
	default:
		throw std::out_of_range("3D Matrix can only have a max of three Vectors");
		break;
	}
}
Matrix3 Matrix3::translate(float radians, float xOffset, float yOffset)
{
	float cosResult = cos(radians);
	float sinResult = sin(radians);

	return Matrix3(
		cosResult, -sinResult, xOffset,
		sinResult, cosResult, yOffset,
		0, 0, 1.0f);
}
Matrix3 Matrix3::rotate(float radians)
{
	float cosResult = cos(radians);
	float sinResult = sin(radians);

	return Matrix3(
		cosResult, -sinResult, 0,
		sinResult, cosResult, 0,
		0, 0, 1.0f);
}
//non member functions
Vector3 operator*(const Matrix3& matrix, const Vector3& vector)
{
	return Vector3(vector[0] * matrix[0] + vector[1] * matrix[1] + vector[2] * matrix[2]);
}
std::ostream& operator<<(std::ostream& os, const Matrix3& matrix)
{
	return os;
}