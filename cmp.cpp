# include "Vector/vector.hpp"
# include "stack.hpp"
# include "equal.hpp"
# include <map>
# include <list>
# include <string>
# include <stack>
# include <algorithm>

using namespace std;

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


template < class T1, class T2 >
void	displayPair(pair<T1, T2> p)
{
	std::cout << "FIRST: " << p.first  << " | SECOND: " << p.second << std::endl;
}

int	main()
{
	pair<int, double>	p1;
	pair<std::string, char>	p2("hello", 'B');
	pair<std::string, char>	p3(p2);
	pair<float, float>	p4(21.212121, 42.42);

	disp("PAIR", 1);
	displayPair(p1);
	disp("PAIR", 2);
	displayPair(p2);
	disp("PAIR", 3);
	displayPair(p3);
	disp("PAIR", 4);
	displayPair(p4);
	disp("-------   p1 = p4  -------", 1);
	p1 = p4;
	disp("PAIR", 1);
	displayPair(p1);
	displayPair(make_pair(52.3, "coucou"));
	return (0);
}
