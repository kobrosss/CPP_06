#include "IRT.hpp"

Base::~Base() {}

Base* generate(void)
{
	int r = std::rand() % 3;

	if(r == 0)
	{
		std::cout << "A class generated";
		return new A;
	}
	else if(r == 1)
	{
		std::cout << "B class generated";
		return new B;
	}
	else
	{
		std::cout << "C class generated";
		return new C;
	}
}

void identity (Base *p)
{
	if(dynamic_cast<A*>(p))
		std::cout << "Pointer with A class";
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer with B class";
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer with C class";
}
