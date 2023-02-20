#include <stack>
#include <iostream>

int	main()
{
	std::stack<int>	s;

	s.push(3);
	s.push(2);
	s.push(1);

	std::cout << s.top() << std::endl;
	std::cout << s.top() << std::endl;
	std::cout << s.size() << std::endl;
}
