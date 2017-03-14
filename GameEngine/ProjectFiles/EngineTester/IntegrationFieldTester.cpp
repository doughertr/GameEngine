#include "gtest\gtest.h"
#include "Math\Vector2.h"
#include "Math\CostField.h"
#include "Math\IntegrationField.h"

using Math::Vector2; 
using Math::CostField;
using Math::IntegrationField;

TEST(IntegrationField, testFieldConstructorDestructor)
{
	{
		IntegrationField testField(150, 200);
	}
	ASSERT_EQ(IntegrationField::constructorCount, IntegrationField::destructorCount);
	ASSERT_EQ(IntegrationField::constructorCount, 30000);
	ASSERT_EQ(IntegrationField::destructorCount, 30000);
}
TEST(IntegrationField, testFieldConstruction)
{
	IntegrationField testField1;
	for (int i = 0; i < testField1.get_height(); i++)
	{
		for (int j = 0; j < testField1.get_width(); j++)
		{
			ASSERT_EQ(testField1[i][j], 16000);
		}
	}
}
TEST(IntegrationField, testCost)
{
	IntegrationField testfield;
	testfield.set_cost();
}