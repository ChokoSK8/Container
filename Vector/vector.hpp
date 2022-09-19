#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "../containers.h"
# include "../iterator.hpp"
# include "../random_access_iterator.hpp"
# include "../const_random_access_iterator.hpp"
# include "../reverse_iterator.hpp"
# include "../const_reverse_iterator.hpp"
# include "../enable_if.hpp"

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
		typedef ft::random_access_iterator<T>			iterator;
		typedef ft::const_random_access_iterator<T>		const_iterator;
		typedef ft::reverse_iterator<T>				reverse_iterator;
		typedef ft::const_reverse_iterator<T>			const_reverse_iterator;

		typedef typename Alloc::difference_type	difference_type;
		typedef typename Alloc::size_type	size_type;
	
	protected:
		pointer		_first;
		size_type	_size;
		size_type	_capacity;
		allocator_type	_c;

	public:
		explicit vector(const allocator_type& = allocator_type())
		{
			_capacity = 0;
			_size = 0;
			_first = _c.allocate(0);
		};
		vector(const vector<T, allocator_type>& x)
		{
			const_iterator	it = x.begin();
			const_iterator	ite = x.end();
			size_type	c = 0;

			_size = x.size();
			_capacity = x.capacity()  < _size ? x.capacity() : _size;
			_c = x.get_allocator();
			_first = _c.allocate(_capacity);
			while (it != ite)
			{
				_c.construct(_first + c, *it);
				++it;
				++c;
			}
		};
		~vector()
		{
			_c.deallocate(_first, _capacity);
		};
		explicit	vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
		{
			_size = n;
			_c = alloc;
			_capacity = 0;
			_first = _c.allocate(n);
			while (n--)
			{
				_c.construct(_first + _capacity, val);
				_capacity++;
			}
		};
		template < class InputIterator >
		explicit	vector(InputIterator start, InputIterator end)
		{
			size_type	i = 0;
			size_type	dist = ft::distance(start, end);

			if (dist > max_size() || dist < 0)
				throw std::out_of_range("vector(start, end)");
			_first = _c.allocate(dist);
			_capacity = dist;
			_size = dist;
			while (start != end)
			{
				_c.construct(_first + i, *start);
				++start;
				++i;
			}
		}

		// ITERATORS
			# include "iterator_vec.hpp"

		// CAPACITY
			# include "capacity_vec.hpp"

		// ELEMENT_ACCES
			# include "element_access_vec.hpp"

		// MODIFIERS
			# include "modifiers_vec.hpp"

		// ALLOCATOR
		allocator_type	get_allocator() const
		{
			return (_c);
		};

	private:
		# include "private_vec.hpp"
};
#endif
