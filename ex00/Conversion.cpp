#include "Conversion.hpp"

class	NonDisplay : public std::exception
{
	public :
		const char *what() const throw()
		{
			return "non display";
		}
};

class	NonConvert : public std::exception
{
	public :
		const char *what() const throw()
		{
			return "impossible";
		}
};

Conversion::Conversion()
{
}

Conversion::Conversion(char *input) : _input(input)
{	
}

Conversion::Conversion(const Conversion &other)
{
	*this = other;
}

Conversion 	&Conversion::operator=(const Conversion &other)
{
	if (this != &other)
		_input = other._input;
	return *this;
}

Conversion::~Conversion()
{
}

char Conversion::getChar(void) const
{
	char c;
	int temp;
	
	try
	{
		temp = std::stoi(this->_input);
		if (temp < -128 || 127 < temp)
			throw NonConvert();
		c = static_cast<char>(temp);
	}
	catch (const std::exception &e)
	{
		throw NonConvert();
	}
	if (c < 32 || 126 < c)
		throw NonDisplay();
	return c;
}

int	Conversion::getInt(void) const
{
	int i;

	try
	{
		i = std::stoi(this->_input);
		return i;
	}
	catch (const std::exception &e)
	{
		throw NonConvert();
	}
}

float Conversion::getFloat(void) const
{
	float f;

	try
	{
		f = std::stof(this->_input);
		return f;
	}
	catch (const std::exception &e)
	{
		throw NonConvert();
	}
}

double	Conversion::getDouble(void) const
{
	double d;

	try
	{
		d = std::stod(this->_input);
		return d;
	}
	catch (const std::exception &e)
	{
		throw NonConvert();
	}
}

std::ostream &operator<<(std::ostream &flux, const Conversion &src)
{
	try
	{
		flux << "char : ";
		char c = src.getChar();
		flux << "\'" << c << "\'" << std::endl;
	}
	catch (const std::exception &e)
	{
		flux << e.what() << std::endl;
	}
	
	try
	{
		flux << "int : " << src.getInt() << std::endl;
	}
	catch (const std::exception &e)
	{
		flux << e.what() << std::endl;
	}
	
	try
	{
		flux << "float : ";
		float f = src.getFloat();
		flux << f;
		if (f - static_cast<long long>(f) == 0)
			flux << ".0";
		flux << "f" << std::endl;
	}
	catch (const std::exception &e)
	{
		flux << e.what() << std::endl;
	}

	try
	{
		flux << "double : ";
		double d = src.getDouble();
		flux << d;
		if (d - static_cast<long long>(d) == 0)
			flux << ".0";
		flux << std::endl;
	}
	catch (const std::exception &e)
	{
		flux << e.what() << std::endl;
	}
	return flux;
}
