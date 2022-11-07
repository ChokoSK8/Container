# include "includes/map.hpp"
# include "../ExtraClass/equal.hpp"
# include "../ExtraClass/pair.hpp"
# include <map>
# include <list>
# include <string>
# include <cstdlib>
# include <fstream>
# include <string>
# include <sstream>
# include <ctime>
# define RAND_TXT "rand.txt"

using namespace NAMESPACE;

int main()
{
	map<int, int> v;
	for (int i = 0; i < 10; i++)
		v.insert(pair<int, int>(i * 4, i));

	// for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
	map<int, int>::const_reverse_iterator it = v.rbegin();
	map<int, int>::const_reverse_iterator ite = v.rend();
	std::cout << (*(it)).first << std::endl;
	std::cout << (*(ite)).first << std::endl;
	while (it != ite){
		std::cout << "hello "<< std::endl;
		std::cout << (*(it)).first << std::endl;
		it++;
	}
    // std::cout << std::endl;
	return 0;
}

/*
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

template < class T1, class T2 >
void	displayMap(const map<T1, T2>& mamap)
{
	typename map<T1, T2>::const_iterator	it = mamap.begin();
	typename map<T1, T2>::const_iterator	ite = mamap.end();

	disp("SIZE", mamap.size());
	while (it != ite)
	{
		displayMapIterator(it);
		++it;
	}
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
	std::cout << "INSERTING " << c << " elements took " <<
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
	std::cout << "INSERTING WITH ITERATOR " << 110
		<< " elements took " << (float)t/CLOCKS_PER_SEC
		<< " seconds" << std::endl;
	displayMap(mamap);
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
	clock_t		t;

	file.open(RAND_TXT, std::ios::in);
	if (!file)
		disp("ERROR: 'RAND_TXT' couldn't open", 0);
	std::getline(file, line);
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
	std::cout << "ERASING " << eraseNum << " elements took " <<
		(float)t/CLOCKS_PER_SEC << " seconds" << std::endl;
	return (0);
}

int	swapTester(void)
{
	std::stringstream	ss;
	std::fstream	file;
	std::string	line;
	map<int, int>	mamap;
	map<int, int>	mamap2;
	int	pairVar = 0;
	int	i = 0;

	file.open(RAND_TXT, std::ios::in);
	if (!file)
		disp("ERROR: 'RAND_TXT' couldn't open", 0);
	std::getline(file, line);
	while (std::getline(file, line))
	{
		ss << line;
		ss >> i;
		if (pairVar % 2)
			mamap.insert(make_pair(i, i));
		else
			mamap2.insert(make_pair(i, i));
		++pairVar;
		ss.clear();
	}
	file.close();
	disp("MAMAP", 1);
	displayMap(mamap);
	disp("MAMAP", 2);
	displayMap(mamap2);
	mamap.swap(mamap2);
	disp("MAMAP", 1);
	displayMap(mamap);
	disp("MAMAP", 2);
	displayMap(mamap2);
	swap(mamap, mamap2);
	disp("MAMAP", 1);
	displayMap(mamap);
	disp("MAMAP", 2);
	displayMap(mamap2);
	return (0);
}

	// ELEMENT_ACCESS

int	operatorHookTester(void)
{
	map<int, int>	mamap;
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
		mamap.insert(make_pair(i, i));
		ss.clear();
	}
	displayMap(mamap);
	disp("val of -2", mamap[-2]);
	mamap[-2] = 5;
	disp("val of -2", mamap[-2]);
	disp("val of 12", mamap[12]);
	mamap[12] = 5;
	mamap[50] = 5;
	mamap[281] = 5;
	mamap[999] = 5;
	mamap[768] = 5;
	displayMap(mamap);
	return (0);
}

int	atTester(void)
{
	map<int, int>	mamap;
	std::stringstream	ss;
	std::fstream	file;
	std::string	line;
	int	i;

	file.open(RAND_TXT, std::ios::in);
	if (!file)
		disp("ERROR: 'RAND_TXT' couldn't open", 0);
	std::getline(file, line);
	while (std::getline(file, line))
	{
		ss << line;
		ss >> i;
		mamap.insert(make_pair(i, i));
		ss.clear();
	}
	displayMap(mamap);
	try
	{
		disp("at(1)", mamap.at(1));
	}
	catch (std::exception& e)
	{
		disp("WHAT", e.what());
	}
	try
	{
		disp("at(15)", mamap.at(15));
	}
	catch (std::exception& e)
	{
		disp("WHAT", e.what());
	}
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
	map<int, int>	mamap;
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
		mamap.insert(make_pair(i, i));
		ss.clear();
	}
	file.close();
	disp("lower_bound(50)", mamap.lower_bound(50)->first);
	disp("lower_bound(0)", mamap.lower_bound(0)->first);
	disp("lower_bound(200) is end", mamap.lower_bound(200) == mamap.end());
	return (0);
}

int	upper_boundTester(void)
{
	map<int, int>	mamap;
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
		mamap.insert(make_pair(i, i));
		ss.clear();
	}
	file.close();
	disp("upper_bound(50)", mamap.upper_bound(50)->first);
	disp("upper_bound(0)", mamap.upper_bound(0)->first);
	disp("upper_bound(200) is end", mamap.upper_bound(200) == mamap.end());
	return (0);
}

int	equal_rangeTester(void)
{
	map<int, int>	mamap;
	pair<map<int, int>::const_iterator, 
				map<int, int>::const_iterator>	ret;
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
		mamap.insert(make_pair(i, i));
		ss.clear();
	}
	file.close();
	ret = mamap.equal_range(50);
	disp("equal_range(50).first", ret.first->first);
	disp("equal_range(50).second", ret.second->first);
	ret = mamap.equal_range(0);
	disp("equal_range(0).first", ret.first->first);
	disp("equal_range(0).second", ret.second->first);
	ret = mamap.equal_range(200);
	disp("equal_range(200).first", ret.first == mamap.end());
	disp("equal_range(200).second", ret.second == mamap.end());
	return (0);
}

int	findTester(void)
{
	map<int, int>	mamap;
	map_iterator	it;
	map_iterator	ite = mamap.end();
	std::stringstream	ss;
	std::fstream	file;
	std::string	line;
	int	i = 0;
	int	n = 200;

	file.open(RAND_TXT, std::ios::in);
	if (!file)
		disp("ERROR: 'RAND_TXT' couldn't open", 0);
	while (std::getline(file, line))
	{
		ss << line;
		ss >> i;
		mamap.insert(make_pair(i, i));
		ss.clear();
	}
	file.close();
	while (--n)
	{
		i = rand() % 20000;
		it = mamap.find(i);
		if (it != ite)
			disp("FOUND", i);
		else
			disp("NOT FOUND", i);
	}
	return (0);
};


	// RELATIONAL_OPERATORS

int	relational_operatorsTester(void)
{
	std::stringstream	ss;
	map<int, int>	mamap;
	map<int, int>	mamap2;
	std::fstream	file;
	std::string	line;
	int	pairVar = 0;
	int	i = 0;

	file.open(RAND_TXT, std::ios::in);
	if (!file)
		disp("ERROR: 'RAND_TXT' couldn't open", 0);
	while (std::getline(file, line))
	{
		ss << line;
		ss >> i;
		if (pairVar % 2)
			mamap.insert(make_pair(i, i));
		else
			mamap2.insert(make_pair(i, i));
		++pairVar;
		ss.clear();
	}
	file.close();
	disp("MAMAP", 1);
	displayMap(mamap);
	disp("MAMAP", 2);
	displayMap(mamap2);
	disp("mamap == mamap2", mamap == mamap2);
	disp("mamap <= mamap2", mamap <= mamap2);
	disp("mamap >= mamap2", mamap >= mamap2);
	disp("mamap != mamap2", mamap != mamap2);
	disp("mamap < mamap2", mamap < mamap2);
	disp("mamap > mamap2", mamap > mamap2);

	map<int, int>	mamap3(mamap);

	disp("mamap == mamap3", mamap == mamap3);
	disp("mamap <= mamap3", mamap <= mamap3);
	disp("mamap >= mamap3", mamap >= mamap3);
	disp("mamap != mamap3", mamap != mamap3);
	disp("mamap < mamap3", mamap < mamap3);
	disp("mamap > mamap3", mamap > mamap3);
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
	fcts["erase"] = &eraseTester;
	fcts["swap"] = &swapTester;
	fcts["operator[]"] = &operatorHookTester;
	fcts["at"] = &atTester;
	fcts["max_size"] = &max_sizeTester;
	fcts["lower_bound"] = &lower_boundTester;
	fcts["upper_bound"] = &upper_boundTester;
	fcts["equal_range"] = &equal_rangeTester;
	fcts["find"] = &findTester;
	fcts["relational_operators"] = &relational_operatorsTester;
	for (it = fcts.begin(), ite = fcts.end(); it != ite; it++)
	{
		if (!str.compare(it->first))
		{
			fct = it->second;
			return (fct ());
		}
	}
	disp("FCT NOT FOUND", 1);
	return (0);
}*/
