# include "../Vector/vector.hpp"
# include "../Stack/stack.hpp"
# include "../ExtraClass/equal.hpp"
# include <map>
# include <list>
# include <string>
# include <stack>
# include <algorithm>
# include <fstream>
# include <string>
# include <sstream>
# define PROG	"STD<container>"
# include <ctime>
# define RAND_TXT "rand.txt"

using namespace std;


typedef map<int, int>::iterator	map_iterator;
typedef map<int, int>::const_iterator	map_const_iterator;
typedef map<int, int>::reverse_iterator	map_reverse_iterator;
typedef map<int, int>::const_reverse_iterator	map_const_reverse_iterator;
typedef int (*PtrFct)();

	// UTILS

void	dispAct(std::string	str)
{
	std::cout << "------- " << str << " -------" << std::endl;
}

template < class T1, class T2 >
void	displayPair(const pair<T1, T2> p)
{
	std::cout << "FIRST: " << p.first  << " | SECOND: " << p.second << std::endl;
}

void	displayMapIterator(map_const_iterator p)
{
	std::cout << "FIRST: " << p->first  << " | SECOND: "
			<< p->second << std::endl;
}

void	displayMapIterator(const map_iterator p)
{
	std::cout << "FIRST: " << p->first  << " | SECOND: "
			<< p->second << std::endl;
}

void	displayMapReverseIterator(const map_reverse_iterator p)
{
	std::cout << "FIRST: " << p->first  << " | SECOND: "
			<< p->second << std::endl;
}

void	insertWithIterator(map<int, int> mamap, int c, int div)
{
	int	i = c / div;
	map_iterator	it = mamap.begin();

	while (c > i)
	{
		--c;
		++it;
	}
	i = 10;
	c = it->first + i;
	while (i > 0)
	{
		mamap.insert(it, make_pair(c, c));
		--c;
		--i;
	}
}

	// MODIFIERS

int	insertTester(void)
{
	map<int, int>	mamap;
	std::stringstream	ss;
	std::string	line;
	int		i;
	int		c = 0;
	std::fstream	file;
	map_const_iterator	it;
	map_const_iterator	ite;
	clock_t		t;

	file.open(RAND_TXT, std::ios::in);
	if (!file)
		disp("ERROR: 'RAND_TXT' couldn't open", 0);
	t = clock();
	while (std::getline(file, line))
	{
		ss << line;
		ss >> i;
		if (mamap.insert(make_pair(i, i)).second)
			++c;
		ss.clear();
	}
	t = clock() - t;
	std::cout << PROG << ": INSERTING " << c << " elements took " <<
		(float)t/CLOCKS_PER_SEC << " seconds" << std::endl;
	file.close();
	t = clock();
	insertWithIterator(mamap, c, 1);
	insertWithIterator(mamap, c, 2);
	insertWithIterator(mamap, c, 3);
	insertWithIterator(mamap, c, 4);
	insertWithIterator(mamap, c, 5);
	insertWithIterator(mamap, c, 6);
	insertWithIterator(mamap, c, 7);
	insertWithIterator(mamap, c, 8);
	insertWithIterator(mamap, c, 9);
	insertWithIterator(mamap, c, 10);
	insertWithIterator(mamap, c, 11);
	t = clock() - t;
	std::cout << PROG << ": INSERTING WITH ITERATOR " << 110
		<< " elements took " << (float)t/CLOCKS_PER_SEC
		<< " seconds" << std::endl;
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

int	eraseTester(void)
{
	std::stringstream	ss;
	std::fstream	file;
	std::string	line;
	map<int, int>	mamap;
	int		i = 0;
	int		eraseNum = 0;
	int		beginFile;
	clock_t		t;

	file.open(RAND_TXT, std::ios::in);
	if (!file)
		disp("ERROR: 'RAND_TXT' couldn't open", 0);
	std::getline(file, line);
	beginFile = file.tellg();
	while (std::getline(file, line))
	{
		ss << line;
		ss >> i;
		mamap.insert(make_pair(i, i));
		ss.clear();
	}
	file.close();
	file.open(RAND_TXT, std::ios::in);
	if (!file)
		disp("ERROR: 'RAND_TXT' couldn't open", 0);
	t = clock();
	while (std::getline(file, line))
	{
		ss << line;
		ss >> i;
		if (mamap.erase(i))
			++eraseNum;
		ss.clear();
	}
	t = clock() - t;
	std::cout << PROG << ": ERASING " << eraseNum << " elements took " <<
		(float)t/CLOCKS_PER_SEC << " seconds" << std::endl;
	return (0);
}

	// ITERATOR

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

	// ELEMENT_ACCESS

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

	// CAPACITY

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

	// OPERATIONS

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

int	equal_rangeTester(void)
{
	int	n = 15;
	map<int, int>	mamap;
	int	i = 0;
        srand(time(0));
	int	modu = n * 10;
	std::map<int, int>	stdMap;
	pair<map_const_iterator, map_const_iterator>	ret;
	std::pair<std::map<int, int>::const_iterator, 
				std::map<int, int>::const_iterator>	ret2;

	while (n)
	{
		i = rand() % modu;
		mamap.insert(make_pair(i, i));
		stdMap.insert(std::make_pair(i, i));
		--n;
	}
	ret = mamap.equal_range(50);
	ret2 = stdMap.equal_range(50);
	disp("equal_range(50).first", ret.first->first);
	disp("equal_range(50).second", ret.second->first);
	disp("REAL equal_range(50).first", ret2.first->first);
	disp("REAL equal_range(50).second", ret2.second->first);
	ret = mamap.equal_range(0);
	ret2 = stdMap.equal_range(0);
	disp("equal_range(0).first", ret.first->first);
	disp("equal_range(0).second", ret.second->first);
	disp("REAL equal_range(0).first", ret2.first->first);
	disp("REAL equal_range(0).second", ret2.second->first);
	ret = mamap.equal_range(200);
	ret2 = stdMap.equal_range(200);
	disp("equal_range(200).first", ret.first == mamap.end());
	disp("equal_range(200).second", ret.second == mamap.end());
	disp("REAL equal_range(200).first == end()", ret2.first == stdMap.end());
	disp("REAL equal_range(200).second == end()", ret2.second == stdMap.end());
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

	fcts["insert"] = &insertTester;
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
