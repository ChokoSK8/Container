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
		size_type	_allocSize;
		allocator_type	_c;

	public:
		explicit vector(const allocator_type& alloc =
				allocator_type()) {
			_allocSize = 0;
			_c = alloc;
			_size = 0;
			_first = 0;
		};
		~vector() {};
		explicit vector(size_type n,
				const value_type& val = value_type(),
				const allocator_type& alloc =
				allocator_type()) {
			_size = n;
			_c = alloc;
			_allocSize = 0;
			_first = _c.allocate(n);
			while (n--)
			{
				_c.construct(_first + _allocSize, val);
				_allocSize++;
			}
		};

		// ITERATORS
		iterator	begin(void) {
			disp("FIRST", _first);
			return (_first);
		};

	//	const_iterator	begin(void) const {
	//		return (_first);
	//	};

		iterator	end(void) {
			return (_first + _size);
		};

	//	const_iterator	end(void) const {
	//		return (_first + _size);
	//	};

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
		template < class InputIterator >
		void	assign(InputIterator first, InputIterator last) {
			size_type	distance = last - first;

			std::cout << "DISTANCE OF ITS: " << distance << std::endl;
			if (last - first < 0)
				throw std::length_error("cannot create std::vector larger than max_size()");

			allocator_type	res;
			pointer		resFirst = res.allocate(distance);
			size_type	c = 0;

			while (first != last)
			{
				std::cout << "VAL: " << *first << std::endl;
				res.construct(resFirst + c, *first);
				first++;
				c++; 
			}
			_size = distance;
			_c.deallocate(_first, _size);
			_c = res;
			_allocSize = distance;
			_first = resFirst;
		}
		void	push_back(const value_type& val)
		{
			if (_size + 1 > _allocSize)
			{
				allocator_type	res;
				if (!_allocSize)
					_allocSize++;
				_allocSize = _size * 2;
				pointer	resFirst = res.allocate(_allocSize);
				size_type	c = 0;
				iterator	it = begin();
				while (c < _size)
				{
					res.construct(resFirst + c, *it);
					c++;
					it++;
				}
				res.construct(resFirst + c, val);
				_c.deallocate(_first, _size);
				_c = res;
				_first = resFirst;
			}
			else
			{
				_c.construct(_first + _size, val);
			}
			_size++;
		}

		// ALLOCATOR
		allocator_type	get_allocator() const {
			return (_c);
		};
};
#endif
