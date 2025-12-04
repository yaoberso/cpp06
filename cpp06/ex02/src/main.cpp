#include "../include/Base.hpp"
#include <cstdlib>
#include <typeinfo>

Base * generate(void)
{
	int val = rand()%3;
	if(val == 0)
	{
		std::cout << "Class A generate!" << std::endl;
		return new A();
	}
	if(val == 1)
	{
		std::cout << "Class B generate!" << std::endl;
		return new B();
	}
	std::cout << "Class C generate!" << std::endl;
	return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A&>(p) != NULL)
	{
		std::cout << "Type: A" << std::endl;
	}
	if (p == new B)
	{
		std::cout << "Type: B" << std::endl;
	}
	if (p == new C)
	{
		std::cout << "Type: C" << std::endl;
	}
}

void identify(Base& p)
{
	if (dynamic_cast<A&>(p) != NULL)
	{
		std::cout << "Type: " << typeid(p).name() << std::endl;
	}
	if (b == new B)
	{
		std::cout << "Type: " << typeid(p).name() << std::endl;
	}
	if (b == new C)
	{
		std::cout << "Type: " << typeid(p).name() << std::endl;
	}
}

int main()
{
	Base *b = generate();
	identify(b);
	identify(b);
	return (0);
}