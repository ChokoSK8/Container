# include <string>
# include <iostream>
# include <vector>
# include <iterator>
# include <limits>

int	main()
{
	int	a = 10;
	int	b = 1;
	std::vector<int>	v1(a);

	std::vector<int>::iterator	it = v1.begin();
	std::vector<int>::iterator	ite = v1.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}	
	return (0);
}
