# include "Vector/vector.hpp"
# include "stack.hpp"
# include "equal.hpp"
# include "pair.hpp"
# include "Map/map.hpp"
# include <map>
# include <list>
# include <string>

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
void	displayPair(pair<T1, T2> p)
{
	std::cout << "FIRST: " << p.first  << " | SECOND: " << p.second << std::endl;
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

int	main()
{
	map<int, int>	mamap;
	pair<int, int>	one(1, 1);
	pair<int, int>	two(2, 2);
	pair<int, int>	three(3, 3);
	pair<int, int>	four(4, 4);
	pair<int, int>	five(5, 5);
	pair<int, int>	six(6, 6);
	pair<int, int>	seven(7, 7);
	pair<int, int>	eight(8, 8);
	pair<int, int>	nine(9, 9);
	pair<int, int>	ten(10, 10);
	pair<int, int>	eleven(11, 11);

	mamap.insert(seven);
	mamap.insert(three);
	mamap.insert(ten);
	mamap.insert(one);
	mamap.insert(two);
	mamap.insert(eleven);
	mamap.insert(six);
	mamap.insert(four);
	mamap.insert(eight);
	mamap.insert(nine);
	mamap.insert(five);
//	mamap.insert(one);
//	mamap.insert(two);
//	mamap.insert(three);
//	mamap.insert(four);
//	mamap.insert(five);
//	mamap.insert(six);
//	mamap.insert(seven);
	return (0);
}
