# include <iostream>
# include <string>
# include <vector>
# include <memory>
# include <limits>
# include <map>
# include <string> 

using namespace std;
typedef int (*PtrFct)();

template < typename T >
void	disp(std::string str, T val)
{
	std::cout << str << ": " << val << std::endl;
}

template < typename T >
void	displayVec(vector<T> vec)
{
	typename vector<T>::iterator	it = vec.begin();
	typename vector<T>::iterator	ite = vec.end();

	disp("SIZE", vec.size());
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

	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.assign(10, "hello");
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v2.assign(20, "byebye");
	disp("CAPACITY", v2.capacity());
	displayVec(v2);
	disp("CAPACITY BEFORE", v1.capacity());
	v1.assign(v2.begin(), v2.begin() + 3);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);

	return (0);
}

int	push_backTester(void)
{
	vector<int>		v1;

	displayVec(v1);
	v1.push_back(1);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(2);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(3);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(4);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(5);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(6);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(7);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	for (int i = 89 ; i < 200 ; i++)
		v1.push_back(i);
	disp("CAPACITY", v1.capacity());
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
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.insert(v1.begin() + 3, 1, 10);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.insert(v1.end(), 5, 9);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.insert(v1.begin(), 5, 11);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.insert(v1.begin(), v1.begin() + 2, v1.end() - 5);
	disp("CAPACITY", v1.capacity());
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
	disp("CAPACITY", v2.capacity());
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
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.erase(v1.begin(), v1.begin() + 2);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
//	v1.erase(v1.begin() - 1, v1.begin() + 1);
//	displayVec(v1);
//	v1.erase(v1.begin() + 1, v1.begin() - 1);
//	displayVec(v1);
//	v1.erase(v1.end(), v1.end() + 2);
//	displayVec(v1);
	return (0);
}

int	reserveTester(void)
{
	vector<int>		v1;

	v1.reserve(5);
	disp("CAPACITY", v1.capacity());
	v1.push_back(1);
	disp("CAPACITY", v1.capacity());
	v1.push_back(2);
	disp("CAPACITY", v1.capacity());
	v1.push_back(3);
	disp("CAPACITY", v1.capacity());
	v1.push_back(4);
	disp("CAPACITY", v1.capacity());
	v1.push_back(5);
	disp("CAPACITY", v1.capacity());
	v1.push_back(6);
	disp("CAPACITY", v1.capacity());
	v1.push_back(7);
	disp("CAPACITY", v1.capacity());
	v1.push_back(8);
	disp("CAPACITY", v1.capacity());
	v1.reserve(9);
	disp("CAPACITY", v1.capacity());
	return (0);
}

int	pop_backTester(void)
{
	vector<int>	v1;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	while (v1.size())
	{
		v1.pop_back();
		disp("CAPACITY", v1.capacity());
		displayVec(v1);
	}
	return (0);
}

int	swapTester(void)
{
	vector<int>	v1;
	vector<int>	v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v2.push_back(21);
	v2.push_back(22);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	disp("CAPACITY", v2.capacity());
	displayVec(v2);
	disp("------------SWAP----------", 1);
	v1.swap(v2);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	disp("CAPACITY", v2.capacity());
	displayVec(v2);

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
	fcts["reserve"] = &reserveTester;
	fcts["push_back"] = &push_backTester;
	fcts["pop_back"] = &pop_backTester;
	fcts["swap"] = &swapTester;
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
