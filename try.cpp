# include <iostream>
# include <vector>
# include <memory>
# include <map>
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

std::map<int, int>	makeMap(int n)
{
	std::map<int, int>	mamap;
	int	i = 0;
        srand(time(0));

	while (n)
	{
		i = rand() % 2000;
		mamap.insert(make_pair(i, i));
		--n;
	}
	return (mamap);
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

template < typename T1, typename T2>
void	displayMap(std::map<T1, T2> mamap)
{
	typename std::map<T1, T2>::iterator	it = mamap.begin();
	typename std::map<T1, T2>::iterator	ite = mamap.end();

	disp("SIZE", mamap.size());
	while (it != ite)
	{
		std::cout << "FIRST:" << it->first;
		std::cout << " | SECOND: " << it->second << std::endl;
		it++;
	}
}

typedef struct	s_coordinate {
	int	a;
	int	b;
}		t_coordinate;

int	main()
{
	std::map<int, int>	mamap;
	std::map<int, int>	mamap2 = makeMap(50);

//	mamap[7] = 7;
//	mamap[8] = 8;
//	mamap[9] = 9;
//	mamap[1] = 1;
//	mamap[2] = 2;
//	mamap[3] = 3;
//	mamap[4] = 4;
//	mamap[5] = 5;
//	mamap[6] = 6;
	mamap.insert(mamap2.begin(), mamap2.end());
	displayMap(mamap);
	disp("VAL OF -2", mamap[-2]);
	return (0);
}
