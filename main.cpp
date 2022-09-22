# include "Vector/vector.hpp"
# include "stack.hpp"
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

int	main()
{
	stack<int>	stk1;

	stk1.push(10);
	displayStk(stk1);
	return (0);
}
