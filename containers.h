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
	class	nobe;
	template < class T >
	class	random_access_iterator;
	template < class I >
	class	reverse_iterator;
	template < class T, class Alloc = std::allocator<T> >
	class	vector;
	template < class T, class Container = vector<T> >
	class	stack;
	template < bool B, class T>
	struct	enable_if;
	template < class T >
	struct	is_integral;
	template < class Iterator1, class Iterator2 >
	bool	equal(Iterator1 first1, Iterator1 last1, Iterator2 first2);
	template < class T >
	class	node;
	template < class T >
	class	rbrator;
	template < class T >
	class	const_rbrator;
	template < class I >
	class	reverse_rbrator;
	template < class Iterator >
	bool	equal(Iterator first1, Iterator last1, Iterator first2);
	template < class T1, class T2 >
	struct	pair;
	template < class T1, class T2 >
	pair<T1, T2>	make_pair(T1 x, T2 y);
	template < class Key, class T, class Compare = std::less<Key>,
		class Allocator = std::allocator<node<pair<const Key, T> > > >
	class	map;
}

#endif
