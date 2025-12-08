#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP
#include <string>
#include <cstdlib>
#include <iostream>

enum type{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALIDE
};

class ScalarConvert {
	public:
		static void convert(const std::string &str);
	private:
		ScalarConvert();
		ScalarConvert(const ScalarConvert &other);
		ScalarConvert &operator=(const ScalarConvert &other);
		~ScalarConvert();
		static void convertFromChar(const std::string &str);
        static void convertFromInt(const std::string &str);
		static void convertFromFloat(const std::string &str);
		static void convertFromDouble(const std::string &str);
        static void printAllType(char c, int i, float f, double d);
		static type FindType(const std::string &str);
};

#endif
