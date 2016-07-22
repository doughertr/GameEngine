#include <gtest\gtest.h>
#include <Math\Vector2.h>
using Math::Vector2;

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