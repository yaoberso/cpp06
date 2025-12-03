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
		ScalarConvert(ScalarConvert &other);
		ScalarConvert &operator=(ScalarConvert &other);
		~ScalarConvert();
		static type FindType(const std::string &str);
};

#endif
