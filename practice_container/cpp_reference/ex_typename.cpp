#include <vector>
#include <iostream>

template <typename Container>
void	printContainer(const Container& c)
{
	typename Container::const_iterator	it;
	for (it = c.begin(); it != c.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int	main()
{
	std::vector<int>	v;

	v.reserve(5);
	for (std::vector<int>::size_type i = 0; i < v.capacity(); ++i)
	{
		v.push_back(i);
	}

	printContainer<std::vector<int> >(v);
}
