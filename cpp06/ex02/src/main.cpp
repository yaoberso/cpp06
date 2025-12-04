#include "../include/Base.hpp"
#include <cstdlib>

Base * generate(void)
{
	srand(time(0));
	int val = rand()%4;
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
	else
	{
		std::cout << "Class C generate!" << std::endl;
		return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "Type: A" << std::endl;
	}
	if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "Type: B" << std::endl;
	}
	if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "Type: C" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type: A" << std::endl;
		return;
	}
	catch(std::bad_cast& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Type: B" << std::endl;
		return;
	}
	catch(std::bad_cast& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Type: C" << std::endl;
		return;
	}
	catch(std::bad_cast& e) {}
}

int main()
{
	Base *b = generate();
	identify(b);
	identify(*b);
	return (0);
}