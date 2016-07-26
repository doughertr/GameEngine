#include <gtest\gtest.h>
#include <Math\Vector2.h>
using Math::Vector2;

float RandomFloat(float min, float max)
{
	// this  function assumes max > min, you may want 
	// more robust error checking for a non-debug build
	assert(max > min);
	float random = ((float)rand()) / (float)RAND_MAX;

	// generate (in your case) a float between 0 and (4.5-.78)
	// then add .78, giving you a float between .78 and 4.5
	float range = max - min;
	return (random*range) + min;
};

TEST(Vector2, Constructor)
{
	Vector2 first(1.0f, 2.0f);
	EXPECT_EQ(1.0f, first.x);
	EXPECT_EQ(2.0f, first.y);
}

TEST(Vector2, VectorAddition) 
{
	Vector2 first(1.0f, 2.0f);
	Vector2 second(3.0f, 4.0f);
	
	Vector2 result1 = first + second;
	Vector2 result2 = second + first;

	EXPECT_TRUE(result1.x == 4.0f);
	EXPECT_TRUE(result1.y == 6.0f);

	EXPECT_TRUE(result1.x == result2.x);
	EXPECT_TRUE(result1.y == result2.y);


}

TEST(Vector2, VectorSubtraction)
{
	Vector2 first(9.0f, 8.0f);
	Vector2 second(1.0f, 4.0f);

	Vector2 result1 = first - second;
	Vector2 result2 = second - first;

	EXPECT_TRUE(result1.x == 8.0f);
	EXPECT_TRUE(result1.y == 4.0f);

	EXPECT_TRUE(result2.x == -8.0f);
	EXPECT_TRUE(result2.y == -4.0f);

	EXPECT_TRUE(result1.x == -result2.x);
	EXPECT_TRUE(result1.y = -result2.y);
}

TEST(Vector2, ScalarMultiplication)
{
	Vector2 first(1.0f, 2.0f);
	Vector2 second(1.0f, 2.0f);
	float scalar = 3.0f;

	Vector2 result1 = first * scalar;
	Vector2 result2 = scalar * second;

	EXPECT_TRUE(result1.x == 3.0f);
	EXPECT_TRUE(result1.y == 6.0f);

	EXPECT_TRUE(result1.x == result2.x);
	EXPECT_TRUE(result1.y == result2.y);
}

TEST(Vector2, VectorMultiplication)
{
	Vector2 first(9.0f, 4.0f);
	Vector2 second(7.0f, 3.0f);

	float result1 = first * second;
	float result2 = second * first;

	EXPECT_TRUE(result1 == 75.0f);

	EXPECT_TRUE(result1 == result2);
}

TEST(Vector2, VectorAssignment)
{
	const int NUM_TESTS = 10;
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector2 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector2 second(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		first = second;
		EXPECT_FLOAT_EQ(first.x, second.x);
		EXPECT_FLOAT_EQ(first.y, second.y);
	}
}

TEST(Vector2, VectorConstructorAssignment)
{
	const int NUM_TESTS = 10;
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector2 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector2 second(first);

		first = second;
		EXPECT_FLOAT_EQ(first.x, second.x);
		EXPECT_FLOAT_EQ(first.y, second.y);
	}	
}

TEST(Vector2, VectorPlusEquals)
{
	const int NUM_TESTS = 10;
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector2 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector2 second(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		float originalX = first.x;
		float originalY = first.y;

		first += second;

		EXPECT_FLOAT_EQ(first.x, originalX + second.x);
		EXPECT_FLOAT_EQ(first.y, originalY + second.y);
	}
}

TEST(Vector2, VectorMinusEquals)
{
	const int NUM_TESTS = 10;
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector2 first(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		Vector2 second(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		float originalX = first.x;
		float originalY = first.y;

		first -= second;

		EXPECT_FLOAT_EQ(first.x, originalX - second.x);
		EXPECT_FLOAT_EQ(first.y, originalY - second.y);
	}
}

TEST(Vector2, VectorTimesEquals)
{
	const int NUM_TESTS = 10;
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector2 vec(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		float scalar = RandomFloat(-1000.0f, 1000.0f);

		float originalX = vec.x;
		float originalY = vec.y;

		vec *= scalar;

		EXPECT_FLOAT_EQ(vec.x, originalX * scalar);
		EXPECT_FLOAT_EQ(vec.y, originalY * scalar);
	}
}

TEST(Vector2, VectorDivisionEquals)
{
	const int NUM_TESTS = 10;
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector2 vec(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));
		float scalar = RandomFloat(-1000.0f, 1000.0f);

		float originalX = vec.x;
		float originalY = vec.y;

		vec /= scalar;

		EXPECT_FLOAT_EQ(vec.x, originalX / scalar);
		EXPECT_FLOAT_EQ(vec.y, originalY / scalar);
	}
}
TEST(Vector2, VectorIndexing)
{
	const int NUM_TESTS = 10;
	for (unsigned int i = 0; i < NUM_TESTS; i++) {
		Vector2 vec(RandomFloat(-1000.0f, 1000.0f), RandomFloat(-1000.0f, 1000.0f));

		EXPECT_FLOAT_EQ(vec.x, vec[0]);
		EXPECT_FLOAT_EQ(vec.y, vec[1]);
	}
}

