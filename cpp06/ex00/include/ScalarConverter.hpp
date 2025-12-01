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

static bool char_status = 0;
static bool int_status = 0;
static bool float_status = 0;
static bool double_status = 0;

class ScalarConvert {
	public:
		static void convert(const std::string &str);
	private:
		ScalarConvert() = delete;
		ScalarConvert(ScalarConvert &other) = delete;
		ScalarConvert &operator=(ScalarConvert &other) = delete;
		~ScalarConvert() = delete;
		static type FindType(const std::string &str);
};

#endif
