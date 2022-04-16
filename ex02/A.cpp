#include "A.hpp"

A::A(void)
{
	return ;
}

A::A(A const &other)
{
	(void)other;
}

A::~A()
{
	return ;
}

A const	&A::operator=(A const &other)
{
	(void)other;
	return (*this);
}

