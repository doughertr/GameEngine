#include <gtest\gtest.h>
#include <Math\Matrix2.h>
#include <Math\Vector2.h>
using Math::Matrix2;
using Math::Vector2;

TEST(Matrix2, Constructor)
{
	Matrix2 indentityMatrix;
	EXPECT_FLOAT_EQ(indentityMatrix.members[0].x, 1.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.members[0].y, 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.members[1].x, 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.members[1].y, 1.0f);

	Matrix2 otherMatrix(9.0f, 3.0f, 1.0f, 6.0f);

	EXPECT_FLOAT_EQ(otherMatrix.members[0].x, 9.0f);
	EXPECT_FLOAT_EQ(otherMatrix.members[0].y, 1.0f);
	EXPECT_FLOAT_EQ(otherMatrix.members[1].x, 3.0f);
	EXPECT_FLOAT_EQ(otherMatrix.members[1].y, 6.0f);
}
TEST(Matrix2, ConstructorCopy)
{
	Matrix2 indentityMatrix;
	Matrix2 copiedMatrix(indentityMatrix);

	EXPECT_FLOAT_EQ(indentityMatrix.members[0].x, copiedMatrix.members[0].x);
	EXPECT_FLOAT_EQ(indentityMatrix.members[0].y, copiedMatrix.members[0].y);
	EXPECT_FLOAT_EQ(indentityMatrix.members[1].x, copiedMatrix.members[1].x);
	EXPECT_FLOAT_EQ(indentityMatrix.members[1].y, copiedMatrix.members[1].y);

	Matrix2 otherMatrix(10.0f, 7.3f, 2.0f, 9.2f);
	Matrix2 otherCopy(otherMatrix);

	EXPECT_FLOAT_EQ(otherMatrix.members[0].x, otherCopy.members[0].x);
	EXPECT_FLOAT_EQ(otherMatrix.members[0].y, otherCopy.members[0].y);
	EXPECT_FLOAT_EQ(otherMatrix.members[1].x, otherCopy.members[1].x);
	EXPECT_FLOAT_EQ(otherMatrix.members[1].y, otherCopy.members[1].y);
}
TEST(Matrix2, Multiplication)
{
	Matrix2 mat1(2, -3,
			     4, -5);
	Vector2 vec1(3, 9);
	Vector2 result = mat1 * vec1;
	EXPECT_FLOAT_EQ(result.x, -21.0f);
	EXPECT_FLOAT_EQ(result.y, -33.0f);
}
TEST(Matrix2, MatrixIndexing)
{
	Matrix2 indentityMatrix;
	EXPECT_FLOAT_EQ(indentityMatrix[0][0], 1.0f);
	EXPECT_FLOAT_EQ(indentityMatrix[0][1], 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix[1][0], 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix[1][1], 1.0f);
}