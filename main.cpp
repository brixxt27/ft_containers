#include "ft_stack.h"
#include <iostream>

int main()
{
	ft::stack<int> stack_a;

	std::cout << "[1] Is stack empty?: ";
	stack_a.empty() ? std::cout << "yes" : std::cout << "no";

	std::cout << "\n[2] Push numbers in stack_a: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		stack_a.push(i);
	}
	stack_a.pop();

	std::cout << "\n[3] Is stack empty?: ";
	stack_a.empty() ? std::cout << "yes" : std::cout << "no";
	std::cout << "\n[3] Size of the stack?: " << stack_a.size() << std::endl;
	std::cout << "[3] What's the top number of the stack?: " << stack_a.top() << std::endl; // 1, because stack is first in, last out(FILO)

	std::cout << "\n[4] Pop() four times. \n";
	for (int i = 0; i < 4; i++)
	{
		stack_a.pop();
	}
	std::cout << "[4] Push() 42. \n";
	stack_a.push(42);
	std::cout << "[4] What's the top number of the stack?: " << stack_a.top() << std::endl;

	return (0);
}
