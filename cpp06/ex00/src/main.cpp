#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		return (1);
	}
	ScalarConvert::convert(argv[1]);
	return (0);
}