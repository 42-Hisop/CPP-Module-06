#include <iostream>

typedef struct s_Data
{
	int		num;
	std::string name;
}				Data;

int main(void)
{
	Data data = {123, "HI"};
	uintptr_t uin;
	Data *after;

	std::cout << "before: " << data.num << " " << data.name << std::endl;
	uin = reinterpret_cast<uintptr_t>(&data);
	std::cout << "uinptr: " << uin << std::endl;
	after = reinterpret_cast<Data *>(uin);
	std::cout << "After: " << after->num << " " << after->name << std::endl;
	return 0;
}
