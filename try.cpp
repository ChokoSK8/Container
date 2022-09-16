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
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

int	main()
{
	vector<int>	v1;
	vector<int>	v2;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v2.push_back(21);
	v2.push_back(22);
	disp("CAPACITY 1", v1.capacity());
	disp("FIRST 1", v1.begin().base());
	displayVec(v1);
	v1.reserve(2);
	disp("CAPACITY 1", v1.capacity());
	disp("FIRST 1", v1.begin().base());
	displayVec(v1);
//	disp("CAPACITY 2", v2.capacity());
//	disp("FIRST 2", v2.begin().base());
//	displayVec(v2);
//	disp("-----------SWAP------------", 1);
//	v1.swap(v2);
//	disp("CAPACITY 1", v1.capacity());
//	disp("FIRST 1", v1.begin().base());
//	displayVec(v1);
//	disp("CAPACITY 2", v2.capacity());
//	disp("FIRST 2", v2.begin().base());
//	displayVec(v2);
	return (0);
}
