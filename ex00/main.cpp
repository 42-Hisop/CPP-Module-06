#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong input" << std::endl;
		return (1);
	}
	Conversion conversion(argv[1]);
	std::cout << conversion;

	return (0);
}
