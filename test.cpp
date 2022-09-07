# include <string>
# include <iostream>
# include <vector>
# include <iterator>
# include <limits>

int	main()
{
	std::vector<int>	v3;

	v3.push_back(65);
	v3.push_back(66);
	v3.push_back(67);
	v3.push_back(68);

	std::vector<int>::iterator	it = v3.begin();
	v3.assign(it + 1, it + 3);
	it = v3.begin();
	std::vector<int>::iterator	ite = v3.end();

	std::cout << "DISTANCE: " << ite -it << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	return (0);
}
