#ifndef ITERATOR2_HPP
# define ITERATOR2_HPP

template < class Iterator > struct	iterator_traits;

template < class T > struct 		iterator_traits<T*> 
{
	typedef std::ptrdiff_t			difference_type;
	typedef T				value_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

template < class T > struct 		iterator_traits<const T*>
{
	typedef std::ptrdiff_t			difference_type;
	typedef T				value_type;
	typedef const T*			pointer;
	typedef const T&			reference;
	typedef std::random_access_iterator_tag	iterator_category;
};

template < class Category, class T, class Distance = std::ptrdiff_t,
	class Pointer = T*, class Reference = T& > struct	iterator;

struct	input_iterator_tag {};
struct	output_iterator_tag {};
struct	forward_iterator_tag: public input_iterator_tag {};
struct	bidirectional_iterator_tag: public forward_iterator_tag {};
struct	random_access_iterator_tag: public bidirectional_iterator_tag {};

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
