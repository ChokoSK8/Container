#ifndef ITERATOR_HPP
# define ITERATOR_HPP

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

template < class InputIterator >
std::ptrdiff_t	ft::distance(InputIterator first, InputIterator last)
{
	std::ptrdiff_t	res = 0;
	while (first != last)
	{
		++res;
		++first;
	}
	return (res);
}
#endif
