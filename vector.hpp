#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "containers.h"
# include "iterator.hpp"
# include "const_iterator.hpp"

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
		typedef ft::const_iterator<ft::vector<T> >	const_iterator;
		/*reverse_iterator
		const_reverse_iterator*/

		typedef typename Alloc::difference_type	difference_type;
		typedef typename Alloc::size_type	size_type;
	
	protected:
		pointer		_first;
		size_type	_size;
		size_type	_capacity;
		allocator_type	_c;

	public:
		explicit vector(const allocator_type& alloc =
				allocator_type()) {
			_capacity = 0;
			_c = alloc;
			_size = 0;
			_first = 0;
		};
		vector(const vector<T, allocator_type>& x) {
			const_iterator	it = x.begin();
			const_iterator	ite = x.end();
			size_type	c = 0;

			_size = x.size();
			_capacity = x.capacity();
			_c = allocator_type();
			_first = _c.allocate(_capacity);
			while (it != ite)
			{
				_c.construct(_first + c, *it);
				it++;
				c++;
			}
		};
		~vector() {
			if (_first)
				_c.deallocate(_first, _capacity);
		};
		explicit vector(size_type n,
				const value_type& val = value_type(),
				const allocator_type& alloc =
				allocator_type()) {
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

		// ITERATORS
		iterator	begin(void) {
			return (_first);
		};

		const_iterator	begin(void) const {
			return (_first);
		};

		iterator	end(void) {
			return (_first + _size);
		};

		const_iterator	end(void) const {
			return (_first + _size);
		};

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
		size_type	capacity() const {
			return (_capacity);
		};

		// MODIFIERS
		void	assign(iterator first, iterator last) {
			size_type	distance = last - first;

			if (last - first < 0)
				throw std::length_error("cannot create std::vector larger than max_size()");

			allocator_type	res;
			pointer		resFirst = res.allocate(distance);
			size_type	c = 0;

			while (first != last)
			{
				res.construct(resFirst + c, *first);
				first++;
				c++; 
			}
			_size = distance;
			_c.deallocate(_first, _size);
			_c = res;
			_capacity = distance;
			_first = resFirst;
		}
		void	assign(size_type n, const value_type& val) {
			if (n > _capacity)
			{
				allocator_type	res;

				pointer	resFirst = res.allocate(n);
				size_type	c = 0;

				while (c < n)
				{
					res.construct(resFirst + c, val);
					c++;
				}
				_c.deallocate(_first, _size);
				_size = c;
				_c = res;
				_capacity = n;
				_first = resFirst;
			}
			else
			{
				iterator	it = begin();
				size_type	c = 0;

				clear();
				while (c < n)
				{
					_c.construct(&(it + c), val);
					c++;
					_size++;
				}
			}
		};
		void	push_back(const value_type& val)
		{
			if (_size + 1 > _capacity)
			{
				allocator_type	res;

				if (!_capacity)
					_capacity++;
				else
					_capacity *= 2;

				pointer	resFirst = res.allocate(_capacity);
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
		iterator	erase(iterator position) {
			iterator	it = begin();
			iterator	ite = end();
			size_type	c = 1;

			_c.destroy(&position);
			while (position + c != ite)
			{
				_c.construct(&(position + c - 1), *(position + c));
				_c.destroy(&(position + c));
				c++;
			}
			--_size;
			return (position + 1);
		};
		iterator	erase(iterator first, iterator last) {
			int		distance = last - first;
			int		incr = 0;	

			
			return (first);
		};
		void	clear(void) {
			iterator	it = begin();
			iterator	ite = end();

			while (it != ite)
			{
				_c.destroy(&it);
				it++;
			}
			_size = 0;
		};

		// ALLOCATOR
		allocator_type	get_allocator() const {
			return (_c);
		};

		private:
			void	moveContentForward(int n) {
				size_type	value;
				size_type	ret;
				size_type	x = 0;
				size_type	y = 0;

				while (n-- > 0)
				{
					x = y;
					++y;
					value = *(_first + x);
					_c.destroy(_first + x);
					while (x < _size + y)
					{
						ret = *(_first + x + 1);
						_c.destroy(_first + x + 1);
						_c.construct(_first + x + 1, value);
						value = ret;
						++x;
					}
				}
			};
};
#endif