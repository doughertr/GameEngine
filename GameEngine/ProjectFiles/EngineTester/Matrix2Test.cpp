#include <gtest\gtest.h>
#include <Math\Matrix2.h>
#include <Math\Vector2.h>
using Math::Matrix2;
using Math::Vector2;

float RandomFloat(float min, float max);

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
TEST(Matrix2, MatrixAndVectorMultiplication)
{
	const Matrix2 testMatrix(2, -3,
			                 4, -5);
	const Vector2 testVector(3, 9);

	Matrix2 originalMat(testMatrix);
	Vector2 originalVec(testVector);

	Vector2 result = testMatrix * testVector;
	EXPECT_FLOAT_EQ(result.x, -21.0f);
	EXPECT_FLOAT_EQ(result.y, -33.0f);

	EXPECT_FLOAT_EQ(originalMat[0][0], testMatrix[0][0]);
	EXPECT_FLOAT_EQ(originalMat[0][1], testMatrix[0][1]);
	EXPECT_FLOAT_EQ(originalMat[1][0], testMatrix[1][0]);
	EXPECT_FLOAT_EQ(originalMat[1][1], testMatrix[1][1]);

	const unsigned int NUM_TESTS = 10;
	const float MIN = -1000.0f;
	const float MAX = 1000.0f;

	float row0col0, row0col1, row1col0, row1col1, vectorX, vectorY;
	Matrix2 test2Matrix;
	Vector2 test2Vector;
	Vector2 testResult;
	for (unsigned int i = 1; i <= NUM_TESTS; i++)
	{
		row0col0 = RandomFloat(MIN, MAX);
		row0col1 = RandomFloat(MIN, MAX);
		row1col0 = RandomFloat(MIN, MAX);
		row1col1 = RandomFloat(MIN, MAX);

		vectorX = RandomFloat(MIN, MAX);
		vectorY = RandomFloat(MIN, MAX);

		test2Matrix = Matrix2(row0col0, row0col1,
							  row1col0, row1col1);
		test2Vector = Vector2(vectorX, vectorY);
		
		testResult = test2Matrix * test2Vector;
		EXPECT_FLOAT_EQ(testResult.x, row0col0*vectorX + row0col1*vectorY);
		EXPECT_FLOAT_EQ(testResult.y, row1col0*vectorX + row1col1*vectorY);
		std::cout << "Test number " << i << " sucessful. Result: " << testResult << std::endl;
	}
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