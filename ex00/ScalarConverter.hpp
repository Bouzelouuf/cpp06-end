#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>

// # define MIN_INT std::numeric_limits<int>::min() //-2147483648
// # define MAX_INT std::numeric_limits<int>::max() //2147483647
// # define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
// # define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
// # define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
// # define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &other);
	public:
		static void convert(const std::string& str);
		static Type isWhat(const std::string& input);
};

#endif
