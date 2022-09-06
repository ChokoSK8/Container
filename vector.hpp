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
		typedef ft::iterator<ft::vector<T> >	iterator;
		/*const_iterator
		reverse_iterator
		const_reverse_iterator*/

		typedef typename Alloc::difference_type	difference_type;
		typedef typename Alloc::size_type	size_type;
	
	protected:
		pointer		_first;
		size_type	_size;
		allocator_type	_c;

	public:
		explicit vector(const allocator_type& alloc =
				allocator_type()) {
			_c = alloc;
			_size = 0;
			_first = 0;
		};
		explicit vector(size_type n,
				const value_type& val = value_type(),
				const allocator_type& alloc =
				allocator_type()) {
			std::cout << "HEY" << std::endl;
			_size = 0;
			_c = alloc;
			_first = _c.allocate(n);
		};
//		template < class InputIterator >
//		vector(InputIterator first, InputIterator last,
//				const allocator_type& alloc =
//				allocator_type()) {
//			_c = alloc;
//			_c.allocate(first);
//			while (first--)
//			{
//				_c.construct(_c.pointer, last);
//				_c.pointer++;
//			}
//		};

		// CAPACITY
		size_type	size(void) const {
			return (_size);
		};

		size_type	max_size(void) const {
			return (std::numeric_limits<size_type>::max() * 2 + 1);
		};

	//	void	resize(size_type n, value_type val = value_type()) {
	//		
	//	};

		// MODIFIERS
		void	push_back(const value_type& val)
		{
		}

		// ALLOCATOR
		allocator_type	get_allocator() const {
			return (_c);
		};
};
#endif
