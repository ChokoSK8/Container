# include <iostream>
# include <vector>
# include <memory>
# include <cstring>
# include <list>

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
	typedef std::iterator_traits<std::list<int>::iterator >	traits;

	if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
		std::cout << "int* is a random-access iterator" << std::endl;
	bool	isBidirectional = typeid(traits::iterator_category) == typeid(std::bidirectional_iterator_tag);
	std::cout << "BIDIRECTIONAL: " << isBidirectional << std::endl;
	return (0);
}
