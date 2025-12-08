
#include "../include/Serializer.hpp"
#include <sstream>

int main()
{
	Data d;
	d.data = 10;
	Data *original_ptr = &d;
	std::cout << d.data << std::endl;
	uintptr_t u = Serializer::serialize(original_ptr);
	std::cout << "------------serialize------------" << std::endl;
	std::cout << "uintptr_t: " << "0x" << std::hex << u << std::hex << std::endl;
	std::cout << "------------deserialize------------" << std::endl;
	Data *a = Serializer::deserialize(u);
	std::cout << "Data *: " << a << std::endl;
	std::cout << std::dec << a->data << std::endl;
	return (0);
}