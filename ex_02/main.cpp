#include "IRT.hpp"

int main ()
{
	std::srand(std::time(NULL));

	Base *i = generate();

	identity(i);
	identity(*i);

	delete i;
	return 0;
}
