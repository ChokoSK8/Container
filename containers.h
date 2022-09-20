#ifndef CONTAINER_H
# define CONTAINER_H
# include <iostream>
# include <string>
# include <vector>
# include <memory>
# include <limits>
# include <cstring>
# include <iterator>

template < typename T >
void	disp(std::string str, T val)
{
	std::cout << str << ": " << val << std::endl;
}

namespace	ft 
{
	template < class Iterator >
	struct	iterator_traits;
	template < class InputIterator >
	std::ptrdiff_t	distance(InputIterator first, InputIterator last);
	template < class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T& >
	class	iterator;
	template < class T >
	class	random_access_iterator;
	template < class T >
	class	const_random_access_iterator;
	template < class T >
	class	reverse_iterator;
	template < class T >
	class	const_reverse_iterator;
	template < class T, class Container = std::vector<T> >
	class	stack;
	template < class T, class Alloc = std::allocator<T> >
	class	vector;
	template < bool B, class T>
	struct	enable_if;
	template < class T >
	struct	is_integral;
}

#endif
