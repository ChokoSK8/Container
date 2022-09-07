# include "containers.h"
# include "stack.hpp"
# include "vector.hpp"

template < typename T >
void	displayVec(ft::vector<T> vec)
{
	ft::vector<int>::iterator	it = vec.begin();
	ft::vector<int>::iterator	ite = vec.end();

	while (it != ite)
	{
		std::cout << " - " << *it << std::endl;
		std::cout << " - " << *(vec.begin()) << std::endl;
		it++;
	}
}

int	main()
{
	ft::vector<int>	vec1;

	std::cout << vec1.size() << std::endl;

	//	PUSH_BACK
	std::cout << "\n\t-----PUSH_BACK TESTS-----\n" << std::endl;

	vec1.push_back(10);
	vec1.push_back(11);
	vec1.push_back(12);
	vec1.push_back(13);
	vec1.push_back(14);
	vec1.push_back(15);
	std::cout << vec1.size() << std::endl;

	std::cout << "VEC1: " << std::endl;
	displayVec(vec1);
	std::cout << "VEC1: " << std::endl;
	displayVec(vec1);

/*	//	ASSIGN
	std::cout << "\n\n\t-----ASSIGN TESTS-----\n" << std::endl;

	ft::vector<int>	vec2;
	ft::vector<int>::iterator	it1 = vec1.begin();
//	vec2.assign(it1 + 1, it1 + 3);
	std::cout << *it1 << std::endl;
	disp("IT1: ", *it1);
	disp("IT1 + 1: ", *(it1 + 1));
	disp("IT1 + 3: ", *(it1 + 3));
	std::cout << "VEC2: " << std::endl;
	displayVec(vec2);
*/	
	return (0);
}
