#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int ac, char **argv)
{
    if (ac != 2)
    {
        std::cout << "Please enter a char, int, float or a double value as argument(solo uno argument!)" << std::endl;
        return (0);
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
