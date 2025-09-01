#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void) other;
	return *this;
}

static void convertFromChar(const std::string &input)
{
	size_t len = input.length();
	char c = 0;
	if (len == 1)
		c = input[0];
	else
		c = input[1];
	if (isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	}
	else
		std::cout << "Non displayable" << std::endl;
}

static void convertFromInt(const std::string &input)
{
	long l = std::atol(input.c_str());
	// ???

	if (l < 0 || l > 127)
		std::cout << "char: impossible" << std::endl;
	else
	{
		if (isprint(l))
			std::cout << "char: '" << static_cast<char>(l) << "'" << std::endl;
		else
			std::cout << "char: Non Displayable" << std::endl;
	}
	if (l < INT_MIN || l > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<float>(l) << ".0f" << std::endl;
	std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	//size_t = input.length();
	std::cout << "Converting: " << input << std::endl;
	Type type = isWhat(input);
	std::cout << "Detected type: " << type << std::endl;
	switch(type)
	{
		case INVALID:
			std::cout << "Invalid input" << std::endl;
		case CHAR:
			convertFromChar(input);
			break;
		case INT:
			convertFromInt(input);
			break;
		// case FLOAT:
		// 	convertFromFloat(input);
		// 	break;
		// case DOUBLE:
		// 	convertFromDouble(input);
		// 	break;
		default:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
	}
}





static bool isChar(const std::string &input)
{
	if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
		return true;
	if (input.length() == 1 && !isdigit(input[0]))
		return true;
	return false;
}

static bool isInt(const std::string &input)
{
	if (input.empty())
		return (false);
	size_t flag_len = 0;
	if (input[0] == '-' || input[0] == '+')
		flag_len = 1;
	if (flag_len >= input.length())
		return (false);
	for (size_t i = flag_len; i < input.length() ; i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	return (true);
}

static bool isFloat(const std::string &input)
{
	if (input.empty())
		return false;
	size_t dot = input.find('.');
	if (dot == std::string::npos)
		return false;
	size_t len = input.length();
	for (int i = dot - 1; i >= 0; i--)
	{
		if (!isdigit(input[i]) && i != 0)
			return false;
		if (!isdigit(input[i]) && i == 0 && input[i] != '-' && input[i] != '+')
			return false;
	}
	for (size_t j = dot + 1; j < len; j++)
	{
		if(!isdigit(input[j]) && input[j] != 'f')
			return (false);
		if (input[j] == 'f' && j != len - 1)
			return false;
	}
	return true;
}

Type ScalarConverter::isWhat(const std::string& input)
{
	if (input == "nanf" || input == "+inff" || input == "-inff")
		return FLOAT;
	if (input == "nan" || input == "+inf" || input == "-inf")
		return DOUBLE;
	if ( input.find('.') == std::string::npos)
	{
		if (isChar(input) == true)
			return CHAR;
		if (isInt(input) == true)
			return INT;
	}
	if (input.find('f') != std::string::npos  && input.find('.') != std::string::npos)
	{
		if (isFloat(input) == true)
			return FLOAT;
	}
	else if (input.find('f') == std::string::npos && input.find('.') != std::string::npos)
	{
		if (isFloat(input) == true)
			return DOUBLE;
	}
	return INVALID;
}
