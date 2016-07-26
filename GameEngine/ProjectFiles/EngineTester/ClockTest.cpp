#include <gtest\gtest.h>
#include <Windows.h>
#include <Timing\Clock.h>
#include <iostream>
using Timing::Clock;
using std::cout;

TEST(Clock, Initialization)
{
	Clock clock;
	EXPECT_TRUE(clock.init());
	EXPECT_TRUE(clock.shutdown());
}
TEST(Clock, FrameTimeMeasurement)
{
	Clock clock;
	//basic defined tests
	EXPECT_TRUE(clock.init());

	Sleep(1000);

	clock.newFrame();
	float deltaTime = clock.deltaTime();
	EXPECT_TRUE(deltaTime > 0.9f && deltaTime < 1.1f);
	clock.newFrame();

	Sleep(500);
	deltaTime = clock.deltaTime();
	EXPECT_TRUE(0.4f > deltaTime && deltaTime < 0.6f);

	//random tests
	const int NUM_TESTS = 10 + rand() % 10;
	const float THRESHOLD = 0.01f;
	for (unsigned int i = 0; i < NUM_TESTS; i++)
	{
		cout << ".";
		int testMilliseconds = rand() % 8000;
		float testSeconds = testMilliseconds / 1000.0f;

		clock.newFrame();
		Sleep(testMilliseconds);
		clock.newFrame();

		float elapsedSeconds = clock.deltaTime();
		EXPECT_NEAR(elapsedSeconds, testSeconds, THRESHOLD);
	}

	clock.newFrame();
	clock.deltaTime();
	EXPECT_TRUE(clock.shutdown());
}