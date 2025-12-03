#include "../include/Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t s = reinterpret_cast<uintptr_t>(ptr);
	return(s);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *d = reinterpret_cast<Data *>(raw);
	return (d);
}