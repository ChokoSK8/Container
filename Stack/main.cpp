#include "stack.hpp"
#include <stack>
#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#define RAND_TXT "rand.txt"

using namespace NAMESPACE;

typedef int (*PtrFct)();

int	allTester(void)
{
	stack<int>	stk;
	std::stringstream	ss;
	std::fstream	file;
	std::string	line;
	int	i;

	file.open(RAND_TXT, std::ios::in);
	if (!file)
		disp("ERROR: 'RAND_TXT' couldn't open", 0);
	while (std::getline(file, line))
	{
		ss << line;
		ss >> i;
		stk.push(i);
		ss.clear();
	}
	file.close();
	while (!stk.empty())
	{
		disp("SIZE", stk.size());
		disp("TOP", stk.top());
		stk.pop();
	}
	return (0);
}

void	checkRelationalOp(stack<int>& x, stack<int>& y, int rev = 0)
{
	disp("x == y", x == y);
	disp("x <= y", x <= y);
	disp("x >= y", x >= y);
	disp("x != y", x != y);
	disp("x < y", x < y);
	disp("x > y", x > y);
	if (rev)
		return (checkRelationalOp(y, x));
}

int	relational_operatorTester(void)
{
	stack<int>	stk;
	stack<int>	stk2;
	std::stringstream	ss;
	std::fstream	file;
	std::string	line;
	int	i;
	int	pairVar = 0;

	file.open(RAND_TXT, std::ios::in);
	if (!file)
		disp("ERROR: 'RAND_TXT' couldn't open", 0);
	while (std::getline(file, line))
	{
		ss << line;
		ss >> i;
		if (pairVar % 2)
			stk2.push(i);
		else
			stk.push(i);
		++pairVar;
		ss.clear();
	}
	file.close();

	stack<int>	stk3(stk);

	checkRelationalOp(stk, stk2, 1);
	checkRelationalOp(stk, stk3, 1);
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

	fcts["all"] = &allTester;
	fcts["relational_operator"] = &relational_operatorTester;
	for (it = fcts.begin(), ite = fcts.end(); it != ite; it++)
	{
		if (!str.compare(it->first))
		{
			fct = it->second;
			return (fct ());
		}
	}
	disp("FCT NOT FOUND", 1);
	return (1);
}
