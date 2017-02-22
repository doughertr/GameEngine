#include <list>
#include "IntegrationField.h"

using namespace std;
Math::IntegrationField::IntegrationField(const int & width, const int & height) :
	width(width),
	height(height)
{
	//field = new int[height][width];
}
Math::IntegrationField::~IntegrationField()
{
	delete[] field;
}
void Math::IntegrationField::set_val(const int & x, const int & y, const int & val)
{
	field[y][x] = val;
}
void Math::IntegrationField::set_val(const Math::Vector2 & vec, const int & val)
{
	set_val(vec.x, vec.y, val);
}
void Math::IntegrationField::reset_field()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			field[i][j] = 160000;
		}
	}
}
void Math::IntegrationField::calculate_field(const int & x, const int & y)
{
	Vector2 target(x, y);

	//set every value to a very high value
	reset_field();
	list<Vector2> openList;

	//set selected value to 0
	set_val(target, 0);
	openList.push_back(target);

}
