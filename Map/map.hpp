#ifndef MAP_HPP
# define MAP_HPP
# include "pair.hpp"

template < class Key, class T, class Compare, class Allocator >
class	ft::map
{
	public:
		typedef	Key					key_type;
		typedef T					mapped_type;
		typedef ft::pair<const Key, T>			value_type;
		typedef std::size_t				size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef Compare					key_compare;
		typedef Allocator				allocator_type;
		typedef reference				value_type&;
		typedef const_reference				const value_type&;
		typedef typename Allocator::pointer		pointer;
		typedef typename Allocator::const_pointer	const_pointer;

		// ITERATOR
		typedef ft::random_access_iterator<pointer>		iterator;
		typedef ft::random_access_iterator<const_pointer>	const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	protected:
		pointer		_first;
		size_type	_size;
		allocator_type	_c;

	public:
		explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
		{
			_first = _c.allocate(0);
			_size = 0;
		};
		template < class InputItr >
		map(InputItr first, InputItr last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
		{
			size_type	length = ft::distance(first, last);

			_first = _c.allocate(length);
		//	while (first != last)
		//	{
		//		_c.const
		//	}
		};
};
#endif
