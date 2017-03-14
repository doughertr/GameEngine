#include <vector>
#include <list>
#include "Vector2.h"
#include "IntegrationField.h"

using namespace std;

int Math::IntegrationField::constructorCount = 0;
int Math::IntegrationField::destructorCount = 0;
Math::IntegrationField::IntegrationField(const int & width, const int & height) :
	width(width),
	height(height)
{
	//initializing all values of the 2D array
	field = new int*[height];
	for (int i = 0; i < height; i++)
	{
		field[i] = new int[width];
		constructorCount++;
	}

	reset_field();
}
Math::IntegrationField::~IntegrationField()
{
	//deallocating all values of the field
	for (int i = 0; i < height; i++)
	{
		delete field[i];
		destructorCount++;
	}
	delete[] field;
}
int Math::IntegrationField::get_width() const { return width; }
int Math::IntegrationField::get_height() const { return height; }
char Math::IntegrationField::get_cost(const int & x, const int & y)
{
	return cost[y][x];
}
void Math::IntegrationField::set_cost(const int & x, const int & y, const int & cost) const
{
	this->cost[y][x] = cost;
	calculate_field(this->currentX, this->currentY);
}
int Math::IntegrationField::get_val(const int & x, const int & y) const
{
	return field[y][x];
}
int Math::IntegrationField::get_val(const Math::Vector2 & vec) const
{
	return field[(int)vec.y][(int)vec.x];
}
void Math::IntegrationField::set_val(const int & x, const int & y, const int & val)
{
	field[y][x] = val;
}
void Math::IntegrationField::set_val(const Math::Vector2 & vec, const int & val)
{
	set_val(vec.x, vec.y, val);
}
int* Math::IntegrationField::operator[](const int & index) const
{
	return field[index];
}
int*& Math::IntegrationField::operator[](const int & index)
{
	return field[index];
}
std::vector<Math::Vector2> Math::IntegrationField::get_neighbors(const int & x, const int & y) const
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
std::vector<Math::Vector2> Math::IntegrationField::get_neighbors(const Vector2 & vec) const
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
	this->currentX = x;
	this->currentY = y;

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
		Math::Vector2 current = openList.front();
		openList.pop_front();

		int currentX = current.x;
		int currentY = current.y;

		std::vector<Math::Vector2> neighbors = get_neighbors(current);
		int neighborCount = neighbors.size();

		for(int i = 0; i < neighborCount; i++)
		{
			int endNodeCost = get_val(current);
			if (endNodeCost < get_val(neighbors[i]))
			{

			}
		}
	}
}
void Math::IntegrationField::reevaluate()
{
	calculate_field(this->currentX, this->currentY);
}
