#include <iostream>

typedef struct s_Data
{
	int		num;
	std::string name;
}				Data;

uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main(void)
{
	Data data = {123, "HI"};
	uintptr_t uin;
	Data *after;

	std::cout << "before: " << data.num << " " << data.name << std::endl;
	uin = serialize(&data);
	std::cout << "uinptr: " << uin << std::endl;
	after = deserialize(uin);
	std::cout << "After: " << after->num << " " << after->name << std::endl;
	
	return 0;
}
