#include <gtest\gtest.h>
#include <Math\Vector3.h>
using Math::Vector3;
#ifndef RANDOM_FLOAT_FUNC
#define RANDOM_FLOAT_FUNC
#endif
const int NUM_TESTS = 10;

float RandomFloat(float min, float max);


TEST(Vector3, Constructor)
{
	Vector3 first(1.0f, 2.0f, 9.0f);
	EXPECT_FLOAT_EQ(1.0f, first.x);
	EXPECT_FLOAT_EQ(2.0f, first.y);
	EXPECT_FLOAT_EQ(9.0f, first.z);
}

TEST(Vector3, VectorAddition)
{
	Vector3 first(1.0f, 2.0f, 4.5f);
	Vector3 second(3.0f, 4.0f, 3.0f);

	Vector3 result1 = first + second;
	Vector3 result2 = second + first;

	EXPECT_FLOAT_EQ(result1.x, 4.0f);
	EXPECT_FLOAT_EQ(result1.y,  6.0f);
	EXPECT_FLOAT_EQ(result1.z, 7.5f);

	EXPECT_FLOAT_EQ(result1.x, result2.x);
	EXPECT_FLOAT_EQ(result1.y, result2.y);
	EXPECT_FLOAT_EQ(result1.z, result2.z);

	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector3 second(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		Vector3 result = first + second;

		EXPECT_FLOAT_EQ(result.x, first.x + second.x);
		EXPECT_FLOAT_EQ(result.y, first.y + second.y);
		EXPECT_FLOAT_EQ(result.z, first.z + second.z);
	}

}

TEST(Vector3, VectorSubtraction)
{
	Vector3 first(9.0f, 8.0f, 10.0f);
	Vector3 second(1.0f, 4.0f, -3.0f);

	Vector3 result1 = first - second;
	Vector3 result2 = second - first;

	EXPECT_FLOAT_EQ(result1.x, 8.0f);
	EXPECT_FLOAT_EQ(result1.y, 4.0f);
	EXPECT_FLOAT_EQ(result1.z, 13.0f);

	EXPECT_FLOAT_EQ(result2.x, -8.0f);
	EXPECT_FLOAT_EQ(result2.y, -4.0f);
	EXPECT_FLOAT_EQ(result2.z, -13.0f);

	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector3 second(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		Vector3 result = first - second;

		EXPECT_FLOAT_EQ(result.x, first.x - second.x);
		EXPECT_FLOAT_EQ(result.y, first.y - second.y);
		EXPECT_FLOAT_EQ(result.z, first.z - second.z);
	}
}

TEST(Vector3, ScalarMultiplication)
{
	Vector3 first(1.0f, 2.0f, 9.0f);
	Vector3 second(7.0f, 2.0f, 3.0f);
	float scalar = 3.0f;

	Vector3 result1 = first * scalar;
	Vector3 result2 = scalar * second;

	EXPECT_FLOAT_EQ(result1.x, 3.0f);
	EXPECT_FLOAT_EQ(result1.y, 6.0f);
	EXPECT_FLOAT_EQ(result1.z, 27.0f);

	EXPECT_FLOAT_EQ(result2.x, 21.0f);
	EXPECT_FLOAT_EQ(result2.y, 6.0f);
	EXPECT_FLOAT_EQ(result2.z, 9.0f);

	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 testVect(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		float testScalar = RandomFloat(-1000.0f, 1000.0f);

		Vector3 result = testVect * testScalar;

		EXPECT_FLOAT_EQ(result.x, testVect.x * testScalar);
		EXPECT_FLOAT_EQ(result.y, testVect.y * testScalar);
		EXPECT_FLOAT_EQ(result.z, testVect.z * testScalar);
	}
}

TEST(Vector3, VectorMultiplication)
{
	Vector3 vec1(9.0f, 4.0f, 5.0f);
	Vector3 vec2(7.0f, 3.0f, 3.0f);

	float result1 = vec1 * vec2;
	float result2 = vec2 * vec1;

	EXPECT_FLOAT_EQ(result1, 90.0f);

	EXPECT_TRUE(result1 == result2);

	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector3 second(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		float result = first * second;

		EXPECT_FLOAT_EQ(result, first.x * second.x + first.y * second.y + first.z * second.z);
	}
}

TEST(Vector3, VectorAssignment)
{
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector3 second(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		first = second;
		EXPECT_FLOAT_EQ(first.x, second.x);
		EXPECT_FLOAT_EQ(first.y, second.y);
		EXPECT_FLOAT_EQ(first.z, second.z);
	}
}

TEST(Vector3, VectorConstructorAssignment)
{
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector3 second(first);

		first = second;
		EXPECT_FLOAT_EQ(first.x, second.x);
		EXPECT_FLOAT_EQ(first.y, second.y);
		EXPECT_FLOAT_EQ(first.z, second.z);
	}
}

TEST(Vector3, VectorPlusEquals)
{
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector3 second(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		float originalX = first.x;
		float originalY = first.y;
		float originalZ = first.z;

		first += second;

		EXPECT_FLOAT_EQ(first.x, originalX + second.x);
		EXPECT_FLOAT_EQ(first.y, originalY + second.y);
		EXPECT_FLOAT_EQ(first.z, originalZ + second.z);
	}
}

TEST(Vector3, VectorMinusEquals)
{
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector3 second(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		float originalX = first.x;
		float originalY = first.y;
		float originalZ = first.z;

		first -= second;

		EXPECT_FLOAT_EQ(first.x, originalX - second.x);
		EXPECT_FLOAT_EQ(first.y, originalY - second.y);
		EXPECT_FLOAT_EQ(first.z, originalZ - second.z);
	}
}

TEST(Vector3, VectorTimesEquals)
{
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 vec(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		float scalar = RandomFloat(-1000.0f, 1000.0f);

		float originalX = vec.x;
		float originalY = vec.y;
		float originalZ = vec.z;

		vec *= scalar;

		EXPECT_FLOAT_EQ(vec.x, originalX * scalar);
		EXPECT_FLOAT_EQ(vec.y, originalY * scalar);
		EXPECT_FLOAT_EQ(vec.z, originalZ * scalar);
	}
}

TEST(Vector3, VectorDivisionEquals)
{
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 vec(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		float scalar = RandomFloat(-1000.0f, 1000.0f);

		float originalX = vec.x;
		float originalY = vec.y;
		float originalZ = vec.z;

		vec /= scalar;

		EXPECT_FLOAT_EQ(vec.x, originalX / scalar);
		EXPECT_FLOAT_EQ(vec.y, originalY / scalar);
		EXPECT_FLOAT_EQ(vec.z, originalZ / scalar);
	}
}
TEST(Vector3, VectorIndexing)
{
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector3 vec(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		EXPECT_FLOAT_EQ(vec.x, vec[0]);
		EXPECT_FLOAT_EQ(vec.y, vec[1]);
		EXPECT_FLOAT_EQ(vec.z, vec[2]);
	}
}

