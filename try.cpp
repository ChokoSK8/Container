# include <iostream>
# include <vector>
# include <memory>
# include <cstring>

using namespace std;

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
	disp("CAPACITY", vec.size());
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

int	main()
{
	vector<int>		v1;
	vector<int>::iterator	it = v1.begin();

	disp("BASE", it.base());
	displayVec(v1);
	v1.push_back(1);;
	v1.push_back(2);;
	v1.push_back(3);;
	v1.push_back(4);;
	v1.push_back(5);;
	v1.push_back(6);;
	v1.push_back(7);;
	it = v1.begin();
	disp("BASE", it.base());
	displayVec(v1);
//	v1.erase(v1.begin(), v1.begin() + 2);
	it = v1.begin();
	disp("BASE", it.base());
	displayVec(v1);
	return (0);
}
