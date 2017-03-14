#include "CostField.h"
#include "Vector2.h"

Math::CostField::CostField(const int & width, const int & height) :
	width(width),
	height(height)
{
	//initializing all values of the 2D array
	field = new char*[height];
	for (int i = 0; i < height; i++)
		field[i] = new char[width];
	
	reset_field();
}
Math::CostField::~CostField()
{
	//deallocating all values of the field
	for (int i = 0; i < height; i++)
		delete field[i];
	delete[] field;
}
char Math::CostField::get_val(const int & x, const int & y) const
{
	return field[y][x];
}
char Math::CostField::get_val(const Math::Vector2 & vec) const
{
	return field[(int)vec.y][(int)vec.x];
}
void Math::CostField::set_val(const int & x, const int & y, const int & val)
{
	field[y][x] = val;
}
void Math::CostField::set_val(const Math::Vector2 & vec, const int & val)
{
	set_val(vec.x, vec.y, val);
}
void Math::CostField::reset_field()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			field[i][j] = 1;
		}
	}
}
char* Math::CostField::operator[](const int & index) const
{
	return field[index];
}
char*& Math::CostField::operator[](const int & index)
{
	return field[index];
}