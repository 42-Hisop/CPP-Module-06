#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int type;
	
	type = rand() % 3;
	switch (type)
	{
		case 0 : return (new A());
		case 1 : return (new B());
		case 2 : return (new C());
	}
	return (NULL);
}

void	identify( Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
	else 
		std::cout << "unknown" << std::endl;
}

Base::~Base()
{
	return ;
}

int main(void)
{
	Base *new_;

	std::srand(time(NULL));
	new_ = generate();
	identify(new_);
	delete new_;
	
	new_ = generate();
	identify(*new_);
	delete new_;
	
	return (0);
}
