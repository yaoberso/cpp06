#include "../include/Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer &src) { *this = src; }
Serializer::~Serializer() {}
Serializer &Serializer::operator=(const Serializer &rhs) {
    (void)rhs;
    return *this;
}

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