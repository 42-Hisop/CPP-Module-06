#include "Base.hpp"
#include <unistd.h>

int main()
{
	Base *p;

	p = generate();
	identify(p);
	delete p;

	usleep(1000 * 1000);

	p = generate();
	identify(*p);
	delete p;

	return (0);
}
