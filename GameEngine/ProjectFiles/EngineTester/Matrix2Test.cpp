#include <gtest\gtest.h>
#include <Math\Matrix2.h>
using Math::Matrix2;

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

}
TEST(Matrix2, Multiplication)
{

}
TEST(Matrix2, MatrixIndexing)
{
	Matrix2 indentityMatrix;
	indentityMatrix.members[3][0];
	EXPECT_FLOAT_EQ(indentityMatrix.members[0][0], 1.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.members[0][1], 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.members[1][0], 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.members[1][1], 1.0f);
}