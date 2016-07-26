#include <gtest\gtest.h>
#include <Math\Matrix2.h>
#include <Math\Vector2.h>
using Math::Matrix2;
using Math::Vector2;

TEST(Matrix2, MatrixConstructor)
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
TEST(Matrix2, MatrixConstructorCopy)
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
TEST(Matrix2, MatrixAndVectorMultiplication)
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
TEST(Matrix2, MatrixRotation)
{
	const float PI = 3.14159265359f;
	Matrix2 op = Matrix2::rotate(0.0f);

	EXPECT_FLOAT_EQ(op[0][0],  1.0f);
	EXPECT_FLOAT_EQ(op[0][1],  0.0f);
	EXPECT_FLOAT_EQ(op[1][0],  0.0f);
	EXPECT_FLOAT_EQ(op[1][1],  1.0f);

	//=====================================
	//NOTE: PI and PI/2 Tests were having 
	//trouble with float equals, returning
	//values very close but not equal to 
	//zero (becuase of floating point error)
	//Added very small threashold instead
	//=====================================
	
	op = Matrix2::rotate(PI);
	EXPECT_NEAR(op[0][0], -1.0f, 0.00001f);
	EXPECT_NEAR(op[0][1],  0.0f, 0.00001f);
	EXPECT_NEAR(op[1][0],  0.0f, 0.00001f);
	EXPECT_NEAR(op[1][1], -1.0f, 0.00001f);
									
	op = Matrix2::rotate(PI/2);		
	EXPECT_NEAR(op[0][0],  0.0f, 0.00001f);
	EXPECT_NEAR(op[0][1],  1.0f, 0.00001f);
	EXPECT_NEAR(op[1][0], -1.0f, 0.00001f);
	EXPECT_NEAR(op[1][1],  0.0f, 0.00001f);

	//=====================================

	op = Matrix2::rotate(PI/4);
	EXPECT_FLOAT_EQ(op[0][0],  sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[0][1],  sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][0], -sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][1],  sqrt(2.0f) / 2.0f);

	op = Matrix2::rotate(-PI/4);
	EXPECT_FLOAT_EQ(op[0][0],  sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[0][1], -sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][0],  sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][1],  sqrt(2.0f) / 2.0f);

	op = Matrix2::rotate(PI/3);
	EXPECT_FLOAT_EQ(op[0][0],  1.0f / 2.0f);
	EXPECT_FLOAT_EQ(op[0][1],  sqrt(3.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][0], -sqrt(3.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][1],  1.0f / 2.0f);

	op = Matrix2::rotate(-PI/6);
	EXPECT_FLOAT_EQ(op[0][0],  sqrt(3.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[0][1], -1.0f / 2.0f);
	EXPECT_FLOAT_EQ(op[1][0],  1.0f / 2.0f);
	EXPECT_FLOAT_EQ(op[1][1],  sqrt(3.0f) / 2.0f);
}