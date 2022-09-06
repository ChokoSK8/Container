#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "containers.h"
# include "iterator.hpp"

template < class T, class Alloc >
class ft::vector
{
	public:
		typedef typename Alloc::value_type	value_type;
		typedef          Alloc			allocator_type;
		typedef typename Alloc::reference	reference;
		typedef typename Alloc::const_reference	const_reference;
		typedef typename Alloc::pointer		pointer;
		typedef typename Alloc::const_pointer	const_pointer;

		// ITERATOR
		typedef ft::iterator<Category, T, Distance, Pointer, Reference>	iterator;
		/*const_iterator
		reverse_iterator
		const_reverse_iterator*/

		typedef typename Alloc::difference_type	difference_type;
		typedef typename Alloc::size_type	size_type;
	
	protected:
		Alloc	_c;

	public:
		explicit vector(const allocator_type& alloc =
				allocator_type()) {
			_c = alloc;
		};
		explicit vector(size_type n,
				const value_type& val = value_type(),
				const allocator_type& alloc =
				allocator_type()) {
			_c = alloc;
			_c.value_type = val;
			_c.allocate(n);
		};
		template < class InputIterator >
		vector(InputIterator first, InputIterator last,
				const allocator_type& alloc =
				allocator_type()) {
			_c = alloc;
			_c.allocate(first);
			while (first--)
			{
				_c.construct(_c.pointer, last);
				_c.pointer++;
			}
		};

		// ALLOCATOR
		allocator_type	get_allocator() const {
			return (_c);
		};
};
#endif
