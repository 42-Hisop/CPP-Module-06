#include "B.hpp"

B::B(void)
{
	return ;
}

B::B(B const &other)
{
	(void)other;
}

B::~B()
{
	return ;
}

B const		&B::operator=(B const &other)
{
	(void)other;
	return (*this);
}
