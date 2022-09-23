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

template < class T >
bool	predicate(const T& x, const T& y)
{
	return (x == y);
}

template < class Container >
void	equalTest(Container x, Container y, int reverse = 1)
{
	disp("equal(x.begin(), x.end(), y.begin(), y.end())",
		equal(x.begin(), x.end(), y.begin()));
	disp("equal(x.begin() + 2, x.end() - 2, y.begin(), y.end())",
		equal(x.begin() + 2, x.end() - 2, y.begin()));
	disp("equal(x.begin() + 2, x.end() - 2, y.begin() + 2, y.end() - 2)",
		equal(x.begin() + 2, x.end() - 2, y.begin() + 2));
	if (reverse)
		return (equalTest(y, x, 0));
}

template < class Container1, class Container2 >
void	equalTest(Container1 x, Container2 y, int reverse = 1)
{
	disp("equal(x.begin(), x.end(), y.begin(), y.end())",
		equal(x.begin(), x.end(), y.begin()));
	disp("equal(x.begin() + 2, x.end() - 2, y.begin(), y.end())",
		equal(x.begin() + 2, x.end() - 2, y.begin()));
	disp("equal(x.begin() + 2, x.end() - 2, y.begin() + 2, y.end() - 2)",
		equal(x.begin() + 2, x.end() - 2, y.begin() + 2));
	if (reverse)
		return (equalTest(y, x, 0));
}

int	equalTester(void)
{
	vector<int>	v1 = makeVec(1, 10);
	vector<int>	v2 = makeVec(1, 5);
	vector<int>	v3 = makeVec(2, 11);

	equalTest(v1, v2);
	equalTest(v1, v3);
	equalTest(v2, v3);
	return (0);
}

int	main()
{
	return (equalTester());
}
