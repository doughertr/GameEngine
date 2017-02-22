#ifndef INTEGRATION_FIELD 
#define INTEGRATION_FIELD
#include <vector>
#include "Vector2.h"
namespace Math
{
	class IntegrationField
	{
	public:
		IntegrationField(const int & width = 100, const int & height = 100);
		~IntegrationField();

		void calculate_field(const int & x, const int & y);
		void reset_field();
	private:
		int width;
		int height;
		int** field;

		void set_val(const int & x, const int & y, const int & val);
		void set_val(const Math::Vector2 & vec, const int & val);

		std::vector<Vector2> get_neighbors(const int & x, const int & y);
		std::vector<Vector2> get_neighbors(const int & x, const int & y);
	};
}
#endif