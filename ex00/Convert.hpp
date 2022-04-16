#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <iostream>
#include <cctype>
#include <cmath>
#include <climits>

class Convert
{
	private :
		std::string _input;
	public :
		Convert(char *input);
		Convert(const Convert &src);
		~Convert();

		Convert &operator=(const Convert &other);
	
		char	getChar() const;
		int		getInt() const;
		float	getFloat() const;
		double	getDouble() const;
	

		class	nonDisplay : public std::exception
		{
			public :
				virtual const char *what() const throw()
				{
					return ("Non displayable");
				}
		};

		class	cannotConvert : public std::exception
		{	
			public :
				virtual const char *what() const throw()
				{
					return ("impossible");
				}
		};	
};

std::ostream &operator<<(std::ostream &flux, const Convert &src);

#endif
