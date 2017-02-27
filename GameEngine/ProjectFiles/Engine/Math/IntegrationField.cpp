#include <list>
#include "Vector2.h"
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
std::list<Math::Vector2> Math::IntegrationField::get_neighbors(const int & x, const int & y) const
{
	int left = x - 1, right = x + 1, up = y - 1, down = y + 1;
	list<Math::Vector2> neighbors;

	//checking all positions of 
	if (left >= 0)
		neighbors.push_back(Vector2(left, y));
	if (right >= 0)
		neighbors.push_back(Vector2(right, y));
	if (up >= 0)
		neighbors.push_back(Vector2(x, up));
	if (down >= 0)
		neighbors.push_back(Vector2(x, down));
	return neighbors;
}
std::list<Math::Vector2> Math::IntegrationField::get_neighbors(const Vector2 & vec) const
{
	return get_neighbors(vec.x, vec.y);
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

	while (openList.size() > 0)
	{
		//start by getting first node in the openlist
		Vector2 current = openList.front();
		openList.pop_front();

		int currentX = current.x;
		int currentY = current.y;

		std::list<Vector2> neighbors = get_neighbors(current);
		int neighborCount = neighbors.size();

		for (int i = 0; i < neighborCount; i++)
		{
			if()
		}
	}
	
}
