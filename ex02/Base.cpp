#include "Base.hpp"

Base::~Base()
{
}

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

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
	std::cout << "pointer" << std::endl;
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "??" << std::endl;
}

void	identify(Base &p)
{
	Base temp;
	std::cout << "reference" << std::endl;
	try
	{
		temp = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		e.what();
	}

	try
	{
		temp = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		e.what();
	}

	try
	{
		temp = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		e.what();
	}
}
