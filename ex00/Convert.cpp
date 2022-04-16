#include "Convert.hpp"

Convert::Convert(char *input) : _input(input)
{
	return ;
}

Convert::Convert(const Convert &src)
{
	*this = src;
}

Convert::~Convert()
{
	return ;
}

Convert &Convert::operator=(const Convert &other)
{
	if (this != &other)
		_input = other._input;
	return (*this);
}

char	Convert::getChar(void) const
{
	char ret;

	try
	{
		ret = static_cast<char>(std::stoi(this->_input));
	}
	catch(const std::exception &e)
	{
		throw Convert::cannotConvert();
	}
	if (ret < 32 || ret > 126)
		throw Convert::nonDisplay();
	return (ret);
}

int	Convert::getInt(void) const
{
	int ret = 0;

	try
	{
		ret = std::stoi(this->_input);
	}
	catch(const std::exception &e)
	{
		throw Convert::cannotConvert();
	}
	return (ret);
}

float	Convert::getFloat(void) const
{
	float ret = 0;

	try
	{
		ret = std::stof(this->_input);
	}
	catch(const std::exception &e)
	{
		throw Convert::cannotConvert();
	}
	return (ret);
}

double	Convert::getDouble(void) const
{
	double ret = 0;
	
	try
	{
		ret = std::stod(this->_input);
	}
	catch(const std::exception &e)
	{
		throw Convert::cannotConvert();
	}
	return (ret);
}



std::ostream &operator<<(std::ostream &flux, Convert const &conv)
{
	try
	{
		flux << "char : ";
		char c  = conv.getChar();
		flux << "\'" << c << "\'" << std::endl;

	}
	catch (const std::exception &e)
	{
		flux << e.what() << std::endl;
	}

	try
	{
		flux << "int : " << conv.getInt() << std::endl;
	}
	catch(const std::exception &e)
	{
		flux << e.what() << std::endl;
	}

	try
	{
		flux << "float : " << conv.getFloat();
		if (conv.getFloat() - static_cast<int>(conv.getFloat()) == 0)
				flux << ".0";
		flux << "f" << std::endl;
	}
	catch(const std::exception &e)
	{
		flux << e.what() << std::endl;
	}

	try
	{
		flux << "double : " << conv.getDouble();
		if (conv.getDouble() - static_cast<int>(conv.getDouble()) == 0)
			flux << ".0";
		flux << std::endl;
	}
	catch(const std::exception &e)
	{
		flux << e.what() << std::endl;
	}
	return (flux);
}
