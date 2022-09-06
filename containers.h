#ifndef CONTAINER_H
# define CONTAINER_H
# include <iostream>
# include <string>
# include <vector>
# include <memory>
# include <limits>

namespace	ft 
{
	template < class Category >
	class	iterator;
	template < class T, class Container = std::vector<T> >
	class	stack;
	template < class T, class Alloc = std::allocator<T> >
	class	vector;
}

#endif
