#ifndef CONTAINER_H
# define CONTAINER_H
# include <iostream>
# include <string>
# include <vector>
# include <memory>
# include <limits>

template < typename T >
void	disp(std::string str, T val)
{
	std::cout << str << ": " << val << std::endl;
}

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
