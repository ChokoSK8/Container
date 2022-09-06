#ifndef CONTAINER_H
# define CONTAINER_H
# include <iostream>
# include <string>
# include <vector>
# include <memory>

namespace	ft 
{
	template < class Category, class T, class Distance = std::ptrdiff_t,
			class Pointer = T*, class Reference = T& >
	class	iterator;
	template < class T, class Container = std::vector<T> >
	class	stack;
	template < class T, class Alloc = std::allocator<T> >
	class	vector;
}

#endif
