#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <string>
#include <cstdlib>
#include <iostream>
#include <stdint.h>

struct Data
{
	int data;
};

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		~Serializer();
};

#endif
