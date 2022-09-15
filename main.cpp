# include "containers.h"
# include "stack.hpp"
# include "Vector/vector.hpp"
# include <map>
# include <string>

using namespace ft;

typedef int (*PtrFct)();

template < typename T >
void	displayVec(vector<T> vec)
{
	typename vector<T>::iterator	it = vec.begin();
	typename vector<T>::iterator	ite = vec.end();

	disp("SIZE", vec.size());
	disp("CAPACITY", vec.capacity());
	while (it != ite)
	{
		std::cout << " - " << *it << std::endl;
		it++;
	}
}

int	assignTester(void)
{
	vector<std::string>		v1;
	vector<std::string>		v2;

	displayVec(v1);
	v1.assign(10, "hello");
	displayVec(v1);
	v2.assign(20, "byebye");
	displayVec(v2);
	v1.assign(v2.begin(), v2.begin() + 3);
	displayVec(v1);

	return (0);
}

int	insertTester(void)
{
	vector<int>		v1;
	vector<int>		v2;

	displayVec(v1);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	displayVec(v1);
	v1.insert(v1.begin() + 3, 1, 10);
	displayVec(v1);
	v1.insert(v1.end(), 5, 9);
	displayVec(v1);
	v1.insert(v1.begin(), 5, 11);
	displayVec(v1);
	v1.insert(v1.begin(), v1.begin() + 2, v1.end() - 5);
	displayVec(v1);
	v2.push_back(21);
	v2.push_back(22);
	v2.push_back(23);
	v2.push_back(24);
	v2.push_back(25);
	v2.push_back(26);
	v2.push_back(27);
	v2.push_back(28);
	v2.insert(v2.begin() + 6, v1.begin() + 2, v1.end() - 5);
	displayVec(v2);

	return (0);
}

int	eraseTester(void)
{
	vector<int>		v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	displayVec(v1);
	v1.erase(v1.begin(), v1.begin() + 2);
	displayVec(v1);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "How to use: ./container <fct to test>"<< std::endl;
		return (1);
	}

	std::map<std::string, PtrFct>		fcts;
	PtrFct					fct;
	std::map<std::string, PtrFct>::iterator	it;
	std::map<std::string, PtrFct>::iterator	ite;
	std::string				str = av[1];

	fcts["assign"] = &assignTester;
	fcts["insert"] = &insertTester;
	fcts["erase"] = &eraseTester;
	for (it = fcts.begin(), ite = fcts.end(); it != ite; it++)
	{
		if (!str.compare(it->first))
		{
			fct = it->second;
			return (fct ());
		}
	}
	std::cout << "<fct to test> not found"<< std::endl;
	return (1);
}
