#include "C.hpp"

C::C(void)
{
	return ;
}

C::C(C const &other)
{
	(void)other;
}

C::~C()
{
	return ;
}

C const	&C::operator=(C const &other)
{
	(void)other;
	return (*this);
}

