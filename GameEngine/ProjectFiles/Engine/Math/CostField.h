#ifndef COST_FIELD_H
#define COST_FIELD_H
#include "Vector2.h"

namespace Math
{
	class CostField
	{
	public:
		CostField(const int & width = 100, const int & height = 100);
		~CostField();

		char get_val(const int & x, const int & y) const;
		char get_val(const Math::Vector2 & vec) const;
		void set_val(const int & x, const int & y, const int & val);
		void set_val(const Math::Vector2 & vec, const int & val);
		
		void reset_field();

		//accessor
		char* operator[](const int & index) const;
		//modifyer
		char*& operator[](const int & index);
	private:
		char** field;

		int width;
		int height;
	};

#endif