# include <iostream>
# include <vector>
# include <memory>
# include <cstring>
# include <list>

using namespace std;

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

template < typename T >
void	disp(std::string str, T val)
{
	std::cout << str << ": " << val << std::endl;
}

template < typename type >
struct myAlloc : allocator<type> {
	typedef typename allocator<type>::size_type	size_type;
	typedef typename allocator<void>::const_pointer	const_pointer;
	typedef typename allocator<type>::pointer	pointer;
	pointer *	allocate(size_type size, const_pointer hint=0) {
		cout << "HEY" << endl;
		std::cout << "Allocation request size => " << size << std::endl;
		return new type[size];
	}
};

template < typename T >
void	displayVec(std::vector<T> vec)
{
	typename std::vector<T>::iterator	it = vec.begin();
	typename std::vector<T>::iterator	ite = vec.end();

	disp("SIZE", vec.size());
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

typedef struct	s_coordinate {
	int	a;
	int	b;
}		t_coordinate;

int	main()
{
	vector<int>	v1 = makeVec(1, 10);

	displayVec(v1);
	v1.insert(v1.begin(), v1.begin() + 2, v1.end() - 5);
	displayVec(v1);
	return (0);
}
