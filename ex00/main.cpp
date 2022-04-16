#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number" << std::endl;
		return (1);
	}
	Convert converter(argv[1]);
	std::cout << converter;

	return (0);
}
