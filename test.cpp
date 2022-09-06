# include <string>
# include <iostream>
# include <vector>
# include <iterator>

int	main()
{
	int	a = 10;
	int	b = 1;
	std::vector<int>	v1(a, b);
	std::vector<int>::iterator	i1 = v1.begin();

	std::cout << *i1++ << std::endl;
	std::vector<int>::iterator	i2 = v1.begin();
	std::cout << *i2++ << std::endl;
	return (0);
}
