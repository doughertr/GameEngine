#include <gtest\gtest.h>
#include <Math\Matrix3.h>
#include <Math\Vector2.h>
#include <Math\Vector3.h>
#include "HelperFunctions.h"

using Math::Matrix3;
using Math::Vector2;
using Math::Vector3;

TEST(Matrix3, MatrixConstructor)
{
	Matrix3 indentityMatrix;
	EXPECT_FLOAT_EQ(indentityMatrix.basisVector0.x, 1.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.basisVector0.y, 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.basisVector0.z, 0.0f);

	EXPECT_FLOAT_EQ(indentityMatrix.basisVector1.x, 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.basisVector1.y, 1.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.basisVector1.z, 0.0f);

	EXPECT_FLOAT_EQ(indentityMatrix.translationVector.x, 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.translationVector.y, 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix.translationVector.z, 1.0f);

	Matrix3 otherMatrix(
		 9.1f,  3.0f, -1.0f, 
		 6.0f,  7.0f,  4.0f,
		-5.3f, -9.1f,  5.6f);

	EXPECT_FLOAT_EQ(otherMatrix.basisVector0.x, 9.1f);
	EXPECT_FLOAT_EQ(otherMatrix.basisVector0.y, 6.0f);
	EXPECT_FLOAT_EQ(otherMatrix.basisVector0.z,-5.3f);

	EXPECT_FLOAT_EQ(otherMatrix.basisVector1.x, 3.0f);
	EXPECT_FLOAT_EQ(otherMatrix.basisVector1.y, 7.0f);
	EXPECT_FLOAT_EQ(otherMatrix.basisVector1.z,-9.1f);

	EXPECT_FLOAT_EQ(otherMatrix.translationVector.x,-1.0f);
	EXPECT_FLOAT_EQ(otherMatrix.translationVector.y, 4.0);
	EXPECT_FLOAT_EQ(otherMatrix.translationVector.z, 5.6f);



}
TEST(Matrix3, MatrixArrayConstructor)
{
	float testArray1[3][3] = { 
		{ 5.7f, 9.9f,-3.3f},
		{ 4.6f, 3.0f,10.5f},
		{-2.9f, 0.2f, 6.7f}, };
	Matrix3 testMat1(testArray1);

	EXPECT_FLOAT_EQ(testMat1.basisVector0.x, 5.7f);
	EXPECT_FLOAT_EQ(testMat1.basisVector0.y, 4.6f);
	EXPECT_FLOAT_EQ(testMat1.basisVector0.z,-2.9f);
				
	EXPECT_FLOAT_EQ(testMat1.basisVector1.x, 9.9f);
	EXPECT_FLOAT_EQ(testMat1.basisVector1.y, 3.0f);
	EXPECT_FLOAT_EQ(testMat1.basisVector1.z, 0.2f);
		
	EXPECT_FLOAT_EQ(testMat1.translationVector.x,-3.3f);
	EXPECT_FLOAT_EQ(testMat1.translationVector.y,10.5f);
	EXPECT_FLOAT_EQ(testMat1.translationVector.z, 6.7f);

	float testArray2[3][3] = { 
		{  0.0f, 10.1f, 22.3f},
		{ -5.3f,-99.8f, 10.2f}, 
		{  3.1f, -9.0f,-11.9f}, };

	Matrix3 testMat2(testArray2);

	EXPECT_FLOAT_EQ(testMat2.basisVector0.x, 0.0f);
	EXPECT_FLOAT_EQ(testMat2.basisVector0.y, -5.3f);
	EXPECT_FLOAT_EQ(testMat2.basisVector0.z, 3.1f);
						   
	EXPECT_FLOAT_EQ(testMat2.basisVector1.x, 10.1f);
	EXPECT_FLOAT_EQ(testMat2.basisVector1.y, -99.8f);
	EXPECT_FLOAT_EQ(testMat2.basisVector1.z, -9.0f);
						   
	EXPECT_FLOAT_EQ(testMat2.translationVector.x, 22.3f);
	EXPECT_FLOAT_EQ(testMat2.translationVector.y, 10.2f);
	EXPECT_FLOAT_EQ(testMat2.translationVector.z,-11.9f);

}
TEST(Matrix3, MatrixVectorMultiplication)
{
	Matrix3 testMatrix(
		1.0f, 3.0f, -1.0f,
		6.0f, 7.0f, 4.0f,
		-5.0f, -2.0f, 7.0f);
	const Vector3 testVector(3.0f, 2.0f, 5.0f);

	Matrix3 originalMat(testMatrix);
	Vector3 originalVec(testVector);

	Vector3 result = testMatrix * testVector;
	EXPECT_FLOAT_EQ(result.x, 4.0f);
	EXPECT_FLOAT_EQ(result.y, 52.0f);
	EXPECT_FLOAT_EQ(result.z, 16.0f);

	EXPECT_FLOAT_EQ(originalMat[0][0], testMatrix[0][0]);
	EXPECT_FLOAT_EQ(originalMat[0][1], testMatrix[0][1]);
	EXPECT_FLOAT_EQ(originalMat[0][2], testMatrix[0][2]);

	EXPECT_FLOAT_EQ(originalMat[1][0], testMatrix[1][0]);
	EXPECT_FLOAT_EQ(originalMat[1][1], testMatrix[1][1]);
	EXPECT_FLOAT_EQ(originalMat[1][2], testMatrix[1][2]);

	EXPECT_FLOAT_EQ(originalMat[2][0], testMatrix[2][0]);
	EXPECT_FLOAT_EQ(originalMat[2][1], testMatrix[2][1]);
	EXPECT_FLOAT_EQ(originalMat[2][2], testMatrix[2][2]);

	const unsigned int NUM_TESTS = 10;
	const float MIN = -1000.0f;
	const float MAX = 1000.0f;

	float row0col0, row0col1, row0col2, row1col0, row1col1, row1col2, row2col0, row2col1, row2col2, vectorX, vectorY, vectorZ;
	Matrix3 test2Matrix;
	Vector3 test2Vector;
	Vector3 testResult;
	for (unsigned int i = 1; i <= NUM_TESTS; i++)
	{
		row0col0 = RandomFloat(MIN, MAX);
		row0col1 = RandomFloat(MIN, MAX);
		row0col2 = RandomFloat(MIN, MAX);


		row1col0 = RandomFloat(MIN, MAX);
		row1col1 = RandomFloat(MIN, MAX);
		row1col2 = RandomFloat(MIN, MAX);

		row2col0 = RandomFloat(MIN, MAX);
		row2col1 = RandomFloat(MIN, MAX);
		row2col2 = RandomFloat(MIN, MAX);

		vectorX = RandomFloat(MIN, MAX);
		vectorY = RandomFloat(MIN, MAX);
		vectorZ = RandomFloat(MIN, MAX);

		test2Matrix = Matrix3(
			row0col0, row0col1, row0col2,
			row1col0, row1col1, row1col2,
			row2col0, row2col1, row2col2);
		test2Vector = Vector3(vectorX, vectorY, vectorZ);

		testResult = test2Matrix * test2Vector;
		//Expected to fail
		EXPECT_FLOAT_EQ(testResult.x, row0col0*vectorX + row0col1*vectorY + row0col2*vectorZ);
		EXPECT_FLOAT_EQ(testResult.y, row1col0*vectorX + row1col1*vectorY + row1col2*vectorZ);
		EXPECT_FLOAT_EQ(testResult.z, row2col0*vectorX + row2col1*vectorY + row2col2*vectorZ);

		std::cout << "Test number " << i << " sucessful. Result: " << testResult << std::endl;
	}
}
TEST(Matrix3, MatrixMultiplication)
{
	Matrix3 mat1(
	1.0f, -5.0f, 3.0f,
	3.0f,-10.0f, 6.0f,
	1.0f,  2.0f, 4.0f);
	Matrix3 mat2(
	1.0f, 2.0f, 3.0f,
	4.0f, 5.0f, 6.0f,
	7.0f, 8.0f, 9.0f);

	Matrix3 result1 = mat2 * mat2;
	EXPECT_FLOAT_EQ(result1[0][0], 30.0f);
	EXPECT_FLOAT_EQ(result1[0][1], 66.0f);
	EXPECT_FLOAT_EQ(result1[0][2], 102.0f);

	EXPECT_FLOAT_EQ(result1[1][0], 36.0f);
	EXPECT_FLOAT_EQ(result1[1][1], 81.0f);
	EXPECT_FLOAT_EQ(result1[1][2], 126.0f);

	EXPECT_FLOAT_EQ(result1[2][0], 42.0f);
	EXPECT_FLOAT_EQ(result1[2][1], 96.0f);
	EXPECT_FLOAT_EQ(result1[2][2], 150.0f);
}
TEST(Matrix3, MatrixIndexing)
{
	Matrix3 indentityMatrix;
	EXPECT_FLOAT_EQ(indentityMatrix[0][0], 1.0f);
	EXPECT_FLOAT_EQ(indentityMatrix[0][1], 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix[0][2], 0.0f);

	EXPECT_FLOAT_EQ(indentityMatrix[1][0], 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix[1][1], 1.0f);
	EXPECT_FLOAT_EQ(indentityMatrix[1][2], 0.0f);

	EXPECT_FLOAT_EQ(indentityMatrix[2][0], 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix[2][1], 0.0f);
	EXPECT_FLOAT_EQ(indentityMatrix[2][2], 1.0f);
}
TEST(Matrix3, MatrixZRotation)
{
	const float PI = 3.14159265359f;
	Matrix3 op = Matrix3::rotateZ(0.0f);

	EXPECT_FLOAT_EQ(op[0][0], 1.0f);
	EXPECT_FLOAT_EQ(op[0][1], 0.0f);
	EXPECT_FLOAT_EQ(op[0][2], 0.0f);

	EXPECT_FLOAT_EQ(op[1][0], 0.0f);
	EXPECT_FLOAT_EQ(op[1][1], 1.0f);
	EXPECT_FLOAT_EQ(op[1][2], 0.0f);

	//translation vector should remain unchanged
	EXPECT_FLOAT_EQ(op[2][0], 0.0f);
	EXPECT_FLOAT_EQ(op[2][1], 0.0f);
	EXPECT_FLOAT_EQ(op[2][2], 1.0f);

	//=====================================
	//NOTE: PI and PI/2 Tests were having 
	//trouble with float equals, returning
	//values very close but not equal to 
	//zero (becuase of floating point error)
	//Added very small threashold instead
	//=====================================

	op = Matrix3::rotateZ(PI);
	EXPECT_NEAR(op[0][0], -1.0f, 0.00001f);
	EXPECT_NEAR(op[0][1], 0.0f, 0.00001f);
	EXPECT_FLOAT_EQ(op[0][2], 0.0f);

	EXPECT_NEAR(op[1][0], 0.0f, 0.00001f);
	EXPECT_NEAR(op[1][1], -1.0f, 0.00001f);
	EXPECT_FLOAT_EQ(op[1][2], 0.0f);

	//translation vector should remain unchanged
	EXPECT_FLOAT_EQ(op[2][0], 0.0f);
	EXPECT_FLOAT_EQ(op[2][1], 0.0f);
	EXPECT_FLOAT_EQ(op[2][2], 1.0f);


	op = Matrix3::rotateZ(PI / 2);
	EXPECT_NEAR(op[0][0], 0.0f, 0.00001f);
	EXPECT_NEAR(op[0][1], 1.0f, 0.00001f);
	EXPECT_FLOAT_EQ(op[0][2], 0.0f);

	EXPECT_NEAR(op[1][0], -1.0f, 0.00001f);
	EXPECT_NEAR(op[1][1], 0.0f, 0.00001f);
	EXPECT_FLOAT_EQ(op[1][2], 0.0f);

	//translation vector should remain unchanged
	EXPECT_FLOAT_EQ(op[2][0], 0.0f);
	EXPECT_FLOAT_EQ(op[2][1], 0.0f);
	EXPECT_FLOAT_EQ(op[2][2], 1.0f);


	//=====================================

	op = Matrix3::rotateZ(PI / 4);
	EXPECT_FLOAT_EQ(op[0][0], sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[0][1], sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[0][2], 0.0f);

	EXPECT_FLOAT_EQ(op[1][0], -sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][1], sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][2], 0.0f);


	//translation vector should remain unchanged
	EXPECT_FLOAT_EQ(op[2][0], 0.0f);
	EXPECT_FLOAT_EQ(op[2][1], 0.0f);
	EXPECT_FLOAT_EQ(op[2][2], 1.0f);

	op = Matrix3::rotateZ(-PI / 4);
	EXPECT_FLOAT_EQ(op[0][0], sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[0][1], -sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[0][2], 0.0f);

	EXPECT_FLOAT_EQ(op[1][0], sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][1], sqrt(2.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][2], 0.0f);


	//translation vector should remain unchanged
	EXPECT_FLOAT_EQ(op[2][0], 0.0f);
	EXPECT_FLOAT_EQ(op[2][1], 0.0f);
	EXPECT_FLOAT_EQ(op[2][2], 1.0f);

	op = Matrix3::rotateZ(PI / 3);
	EXPECT_FLOAT_EQ(op[0][0], 1.0f / 2.0f);
	EXPECT_FLOAT_EQ(op[0][1], sqrt(3.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[0][2], 0.0f);

	EXPECT_FLOAT_EQ(op[1][0], -sqrt(3.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][1], 1.0f / 2.0f);
	EXPECT_FLOAT_EQ(op[1][2], 0.0f);


	//translation vector should remain unchanged
	EXPECT_FLOAT_EQ(op[2][0], 0.0f);
	EXPECT_FLOAT_EQ(op[2][1], 0.0f);
	EXPECT_FLOAT_EQ(op[2][2], 1.0f);

	op = Matrix3::rotateZ(-PI / 6);
	EXPECT_FLOAT_EQ(op[0][0], sqrt(3.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[0][1], -1.0f / 2.0f);
	EXPECT_FLOAT_EQ(op[0][2], 0.0f);

	EXPECT_FLOAT_EQ(op[1][0], 1.0f / 2.0f);
	EXPECT_FLOAT_EQ(op[1][1], sqrt(3.0f) / 2.0f);
	EXPECT_FLOAT_EQ(op[1][2], 0.0f);

	//translation vector should remain unchanged
	EXPECT_FLOAT_EQ(op[2][0], 0.0f);
	EXPECT_FLOAT_EQ(op[2][1], 0.0f);
	EXPECT_FLOAT_EQ(op[2][2], 1.0f);
}
TEST(Matrix3, MatrixPointTranslation)
{
	Matrix3 trans = Matrix3::translate(6.0f, 7.0f);
	Vector3 vect(-5.0f, 2.0f, 1.0f);
	Vector3 result = trans * vect;

	EXPECT_FLOAT_EQ(result.x, 1.0f);
	EXPECT_FLOAT_EQ(result.y, 9.0f);
	EXPECT_FLOAT_EQ(result.z, 1.0f);

	Matrix3 trans2 = Matrix3::translate(9.0f, -4.0f);
	Vector3 vect2(-1.0f, -13.0f, 1.0f);
	Vector3 result2 = trans2 * vect2;

	EXPECT_FLOAT_EQ(result2.x, 8.0f);
	EXPECT_FLOAT_EQ(result2.y, -17.0f);
	EXPECT_FLOAT_EQ(result2.z, 1.0f);

}
TEST(Matrix3, MatrixVectorTranslation)
{
	Matrix3 trans = Matrix3::translate(Vector3(6.0f, 7.0f));
	Vector3 vect(-5.0f, 2.0f, 1.0f);
	Vector3 result = trans * vect;

	EXPECT_FLOAT_EQ(result.x, 1.0f);
	EXPECT_FLOAT_EQ(result.y, 9.0f);
	EXPECT_FLOAT_EQ(result.z, 1.0f);

	Matrix3 trans2 = Matrix3::translate(Vector3(9.0f, -4.0f));
	Vector3 vect2(-1.0f, -13.0f, 1.0f);
	Vector3 result2 = trans2 * vect2;

	EXPECT_FLOAT_EQ(result2.x, 8.0f);
	EXPECT_FLOAT_EQ(result2.y, -17.0f);
	EXPECT_FLOAT_EQ(result2.z, 1.0f);
}