#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include "containers.h"

template < class Category, class T, class Distance,
		class Pointer, class Reference >
class	ft::iterator
{
	public:
		typedef Category	iterator_category;
		typedef T		value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
};
#endif
