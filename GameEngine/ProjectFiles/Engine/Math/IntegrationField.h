#ifndef INTEGRATION_FIELD 
#define INTEGRATION_FIELD
#include <vector>
#include "Vector2.h"
#include "CostField.h"

namespace Math
{
	class IntegrationField
	{
	public:
		IntegrationField(const int & width = 100, const int & height = 100);
		~IntegrationField();

		static int constructorCount;
		static int destructorCount;

		int get_width() const;
		int get_height() const;
		
		char get_cost(const int & x, const int & y);
		void set_cost(const int & x, const int & y, const int & cost) const;

		int* operator[](const int & index) const;
		int*& operator[](const int & index);

		void calculate_field(const int & startX, const int & startY);
		void reset_field();
	private:
		int width;
		int height;
		int currentX;
		int currentY;
		int current;
		int** field;
		CostField cost;

		int get_val(const int & x, const int & y) const;
		int get_val(const Vector2 & vec) const;
		void set_val(const int & x, const int & y, const int & val);
		void set_val(const Vector2 & vec, const int & val);

		std::vector<Vector2> get_neighbors(const int & x, const int & y) const;
		std::vector<Vector2> get_neighbors(const Vector2 & vec) const;

		void reevaluate();
	};
}
#endif