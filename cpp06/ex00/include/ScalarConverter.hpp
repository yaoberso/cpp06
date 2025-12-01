#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP
#include <string>
#include <cstdlib>

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
		ScalarConvert() = delete;
		ScalarConvert(ScalarConvert &other) = delete;
		ScalarConvert &operator=(ScalarConvert &other) = delete;
		~ScalarConvert() = delete;
		static type FindType(const std::string &str);
};

#endif
