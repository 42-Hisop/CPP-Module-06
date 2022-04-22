#include "Base.hpp"

Base::~Base()
{
}

Base *generate(void)
{
	int r;

	std::srand(std::time(NULL));
	r = rand() % 3;
	switch (r)
	{
		case 0 : return (new A);
		case 1 : return (new B);
		case 2 : return (new C);
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "p: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "p: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "p: C" << std::endl;
	else
		std::cout << "??" << std::endl;
}

void	identify(Base &p)
{
	Base temp;
	try
	{
		temp = dynamic_cast<A&>(p);
		std::cout << "p: A" << std::endl;
	}
	catch (std::exception &e)
	{
		e.what();
	}

	try
	{
		temp = dynamic_cast<B&>(p);
		std::cout << "p: B" << std::endl;
	}
	catch (std::exception &e)
	{
		e.what();
	}

	try
	{
		temp = dynamic_cast<C&>(p);
		std::cout << "p: C" << std::endl;
	}
	catch (std::exception &e)
	{
		e.what();
	}
}
