#include <iostream>

template <typename T, int num>
T	add_num(int x)
{
	return x + num;
}

int	main()
{
	int	x = 3;

	std::cout << "x: " << add_num<int, 5>(x) << std::endl;
}
