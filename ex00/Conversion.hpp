#ifndef CONVERSION_HPP
#define CONVERSION_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

class Conversion
{
	private : 
		std::string _input;
	public :
		Conversion();
		Conversion(char *input);
		Conversion(const Conversion &other);
		~Conversion();

		Conversion &operator=(const Conversion &other);

		char getChar() const;
		int	getInt() const;
		float	getFloat() const;
		double	getDouble() const;

		class NonDisplay : public std::exception
		{
			public :
				virtual	const char *what() const throw();
		};
		
		class NonConvert : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream &flux, const Conversion &src);

#endif
