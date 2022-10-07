# include "Vector/vector.hpp"
# include "stack.hpp"
# include "equal.hpp"
# include "pair.hpp"
# include "Map/map.hpp"
# include <map>
# include <list>
# include <string>
# include <cstdlib>
# include <fstream>
# include <string>
# include <sstream>

using namespace ft;

typedef map<int, int>::iterator	map_iterator;
typedef map<int, int>::const_iterator	map_const_iterator;
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

void	displayMapIterator(const map_iterator p)
{
	std::cout << "FIRST: " << p->first  << " | SECOND: "
			<< p->second << std::endl;
}

//void	displayElements(map<int, int> mamap)
//{
//	map_iterator	it = mamap.begin();
//	map_iterator	ite = mamap.end();
//	int	i = 0;
//	int	n;
//
//	while (it != ite)
//	{
//		n = it->first;
//		displayMapIterator(it);
//		++it;
//		if (n > it->first && it != ite)
//			disp("--------ERROR--------", 1);
//		++i;
//	}
//}

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
	std::stringstream	ss;
	std::string	line;
	int		i;
	std::fstream	file;
	map_iterator	it;
	map_iterator	ite;

	file.open("rand.txt", std::ios::in);
	if (!file)
		disp("ERROR: rand.txt couldn't open", 0);
	while (std::getline(file, line))
	{
		ss << line;
		ss >> i;
		mamap.insert(make_pair(i, i));
		ss.clear();
	}
	file.close();
	it = mamap.begin();
	ite = mamap.end();
	while (it != ite)
	{
		displayMapIterator(it);
		++it;
	}
	disp("SIZE", mamap.size());
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

	while (i < 100)
	{
		n = rand() % 2000;
		ret = mamap.insert(make_pair(n, n));
		if (!ret.second)
			disp("KEY ALREADY USED", ret.first->second);
		++i;
	}
	disp("NUMBER OF ELEMENTS", i);
	return (0);
}

int	element_accessTester(void)
{
	map<int, int>	mamap;
        srand(time(0));

	for (int i = 0; i < 15; ++i)
		mamap.insert(make_pair(i, (int)rand() % 100));
	map<int, int>::iterator	it = mamap.begin();
	map<int, int>::iterator	ite = mamap.end();
	int	i = 0;
	int	n;

	while (it != ite)
	{
		n = it->first;
		++it;
		if (n > it->first && it != ite)
			disp("--------ERROR--------", 1);
		++i;
	}
	disp("val of -2", mamap[-2]);
	mamap[-2] = 5;
	disp("val of -2", mamap[-2]);
	disp("val of 12", mamap[12]);

	it = mamap.begin();
	ite = mamap.end();
	i = 0;
	while (it != ite)
	{
		n = it->first;
		displayMapIterator(it);
		++it;
		if (n > it->first && it != ite)
			disp("--------ERROR--------", 1);
		++i;
	}
	return (0);
}

int	atTester(void)
{
	map<int, int>	mamap;
        srand(time(0));

	for (int i = 0; i < 15; ++i)
		mamap.insert(make_pair(i, (int)rand() % 100));
	map<int, int>::iterator	it = mamap.begin();
	map<int, int>::iterator	ite = mamap.end();
	int	i = 0;
	int	n;

	while (it != ite)
	{
		n = it->first;
		++it;
		if (n > it->first && it != ite)
			disp("--------ERROR--------", 1);
		++i;
	}
	disp("at(1)", mamap.at(1));
	disp("at(4)", mamap.at(4));
	try
	{
		disp("at(15)", mamap.at(15));
	}
	catch (std::exception& e)
	{
		disp("WHAT", e.what());
	}

	// CONST
	const int	conInt = mamap.at(5);
	disp("at(5) const", conInt);
	return (0);
}

int	max_sizeTester(void)
{
	map<int, float>	mamap;
	std::map<int, float>	stdMap;
	map<std::string, std::string>	mamap2;
	std::map<std::string, std::string>	stdMap2;

	disp("mamap<int, float>.max_size()", mamap.max_size());
	disp("stdMap<int, float>.max_size()", stdMap.max_size());
	disp("mamap2<std::string, std::string>.max_size()", mamap2.max_size());
	disp("stdMap2<std::string, std::string>.max_size()", stdMap2.max_size());
	return (0);
}

int	lower_boundTester(void)
{
	int	n = 15;
	map<int, int>	mamap;
	int	i = 0;
        srand(time(0));
	int	modu = n * 10;
	std::map<int, int>	stdMap;

	while (n)
	{
		i = rand() % modu;
		mamap.insert(make_pair(i, i));
		stdMap.insert(std::make_pair(i, i));
		--n;
	}
	disp("lower_bound(50)", mamap.lower_bound(50)->first);
	disp("REAL: lower_bound(50)", stdMap.lower_bound(50)->first);
	disp("lower_bound(0)", mamap.lower_bound(0)->first);
	disp("REAL: lower_bound(0)", stdMap.lower_bound(0)->first);
	disp("lower_bound(200) is end", mamap.lower_bound(200) == mamap.end());
	disp("REAL: lower_bound(200) is end", stdMap.lower_bound(200) == stdMap.end());
	return (0);
}

int	upper_boundTester(void)
{
	int	n = 15;
	map<int, int>	mamap;
	int	i = 0;
        srand(time(0));
	int	modu = n * 10;
	std::map<int, int>	stdMap;

	while (n)
	{
		i = rand() % modu;
		mamap.insert(make_pair(i, i));
		stdMap.insert(std::make_pair(i, i));
		--n;
	}
	disp("upper_bound(50)", mamap.upper_bound(50)->first);
	disp("REAL: upper_bound(50)", stdMap.upper_bound(50)->first);
	disp("upper_bound(0)", mamap.upper_bound(0)->first);
	disp("REAL: upper_bound(0)", stdMap.upper_bound(0)->first);
	disp("upper_bound(200) is end", mamap.upper_bound(200) == mamap.end());
	disp("REAL: upper_bound(200) is end", stdMap.upper_bound(200) == stdMap.end());
	return (0);
}

//int	equal_rangeTester(void)
//{
//	int	n = 15;
//	map<int, int>	mamap;
//	int	i = 0;
//        srand(time(0));
//	int	modu = n * 10;
//	std::map<int, int>	stdMap;
//	pair<map_const_iterator, map_const_iterator>	ret;
//	std::pair<std::map<int, int>::const_iterator, 
//				std::map<int, int>::const_iterator>	ret2;
//
//	while (n)
//	{
//		i = rand() % modu;
//		mamap.insert(make_pair(i, i));
//		stdMap.insert(std::make_pair(i, i));
//		--n;
//	}
//	mamap.print();
//	ret = mamap.equal_range(50);
//	ret2 = stdMap.equal_range(50);
//	disp("equal_range(50).first", ret.first->first);
//	disp("equal_range(50).second", ret.second->first);
//	disp("REAL equal_range(50).first", ret2.first->first);
//	disp("REAL equal_range(50).second", ret2.second->first);
//	ret = mamap.equal_range(0);
//	ret2 = stdMap.equal_range(0);
//	disp("equal_range(0).first", ret.first->first);
//	disp("equal_range(0).second", ret.second->first);
//	disp("REAL equal_range(0).first", ret2.first->first);
//	disp("REAL equal_range(0).second", ret2.second->first);
//	ret = mamap.equal_range(200);
//	ret2 = stdMap.equal_range(200);
//	disp("equal_range(200).first", ret.first == mamap.end());
//	disp("equal_range(200).second", ret.second == mamap.end());
//	disp("REAL equal_range(200).first == end()", ret2.first == stdMap.end());
//	disp("REAL equal_range(200).second == end()", ret2.second == stdMap.end());
//	return (0);
//}

int	eraseTester(void)
{
	int	n = 30;
	map<int, int>	mamap;
	map_iterator	it;
	map_iterator	ite;
	int	i = 0;
        srand(time(0));

	mamap.insert(make_pair(10, 10));
	while (n)
	{
		i = rand() % 5000;
		mamap.insert(make_pair(i, i));
		--n;
	}
	while (!mamap.empty())
	{
		i = rand() % 5000;
		while (mamap.find(i) == mamap.end())
			i = rand() % 5000;
		disp("ERASE", i);
		mamap.erase(i);
		--n;
	}
	it = mamap.begin();
	ite = mamap.end();
	i = 0;

	while (it != ite)
	{
		n = it->first;
//		displayRBrator(it);
		++it;
		if (n > it->first && it != ite)
			disp("--------ERROR--------", 1);
		++i;
	}
	disp("NUMBER OF ELEMENTS", i);
//	mamap.print();
	return (0);
}

int	findTester(void)
{
	map<int, int>	mamap;
	map_iterator	it;
	int	n = 20;
	int	i;
	srand(time(0));

	while (n)
	{
		i = rand() % 50;
		mamap.insert(make_pair(i, i));
		--n;
	}
//	mamap.print();
	n = 20;
	while (--n)
	{
		i = rand() % 50;
		it = mamap.find(i);
		if (it != mamap.end())
			disp("FOUND", i);
		else
			disp("NOT FOUND", i);
	}
	return (0);
};

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
	fcts["element_access"] = &element_accessTester;
	fcts["at"] = &atTester;
	fcts["max_size"] = &max_sizeTester;
	fcts["lower_bound"] = &lower_boundTester;
	fcts["upper_bound"] = &upper_boundTester;
//	fcts["equal_range"] = &equal_rangeTester;
	fcts["erase"] = &eraseTester;
	fcts["find"] = &findTester;
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
