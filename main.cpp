# include "Vector/vector.hpp"
# include "stack.hpp"
# include "equal.hpp"
# include "pair.hpp"
# include "Map/map.hpp"
# include <map>
# include <list>
# include <string>
# include <cstdlib>

using namespace ft;

#define TESTED_NAMESPACE ft

typedef int (*PtrFct)();

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

template < typename T >
void	displayStk(stack<T> stk)
{
	disp("SIZE", stk.size());
	while (!stk.empty())
	{
		std::cout << " - " << stk.top() << std::endl;
		stk.pop();
	}		
}

vector<int>	makeVec(int start, int range)
{
	int		end = start + range;
	vector<int>	vec;

	while (start < end)
	{
		vec.push_back(start);
		++start;
	}
	return (vec);
}

void	dispAct(std::string	str)
{
	std::cout << "------- " << str << " -------" << std::endl;
}

template < class T1, class T2 >
void	displayPair(const pair<T1, T2> p)
{
	std::cout << "FIRST: " << p.first  << " | SECOND: " << p.second << std::endl;
}

template < class T >
void	displayRBrator(const rbrator<T> p)
{
	std::cout << "FIRST: " << p->getKey()  << " | SECOND: "
			<< p->getContent() << " | SIDE: " << p->getSide() << std::endl;
}

template < class T1, class T2 >
void	pairCmpTester(pair<T1, T2>& x, pair<T1, T2>& y, int recur = 1)
{
	disp("PAIR X", 1);
	displayPair(x);
	disp("PAIR Y", 1);
	displayPair(y);
	disp("x == y", x == y);
	disp("x != y", x != y);
	disp("x <= y", x <= y);
	disp("x >= y", x >= y);
	disp("x < y", x < y);
	disp("x > y", x > y);
	if (recur)
		return pairCmpTester(y, x, 0);
}

int	pairANDmake_pairTester(void)
{
	pair<int, double>	p1;
	pair<std::string, char>	p2("hello", 'B');
	pair<std::string, char>	p3(p2);
	pair<float, float>	p4(21.212121, 42.42);
	pair<float, float>	p5(4, 2);

	dispAct("CONSTRUCTOR TESTS");
	disp("PAIR", 1);
	displayPair(p1);
	disp("PAIR", 2);
	displayPair(p2);
	disp("PAIR", 3);
	displayPair(p3);
	disp("PAIR", 4);
	displayPair(p4);

	dispAct("p1 == p4");
	p1 = p4;
	disp("PAIR", 1);
	displayPair(p1);

	dispAct("make_pair(52.3, \"coucou\") --------");
	displayPair(make_pair(52.3, "coucou"));

	dispAct("COMPARAISON");
	pairCmpTester(p4, p5);
	return (0);
}

int	insertTester1(void)
{
	map<int, int>	mamap;
	int	i = 0;
	int	n;

	while (i < 25)
	{
		n = rand() % 1000;
		mamap.insert(make_pair(n, n));
		++i;
	}
	mamap.print();
	return (0);
}

int	iteratorTester(void)
{
	map<int, int>				mamap;
	map<int, int>::iterator			it;
	map<int, int>::iterator			ite;
	pair<map<int, int>::iterator, bool>	ret;
	int	n;
	int	i = 0;
        srand(time(0));

	while (i < 15)
	{
		n = rand() % 50;
		ret = mamap.insert(make_pair(n, n));
		if (!ret.second)
			disp("KEY ALREADY USED", ret.first->getContent());
		++i;
	}
	it = mamap.begin();
	ite = mamap.end();
	mamap.print();
//	int	counter = 1;
//	while (it != ite)
//	{
//		n = it->getKey();
//		displayRBrator(it);
//		++it;
//		if (n > it->getKey() && it != ite)
//			disp("--------ERROR--------", 1);
//		++counter;
//	}
//	disp("counter", counter);
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

	fcts["insert"] = &insertTester1;
	fcts["iterator"] = &iteratorTester;
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
