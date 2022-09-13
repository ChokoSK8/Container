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
		// TODO
		void	resize(size_type n, value_type val = value_type()) {
			(void)val;
			_size = n;
		};
		size_type	capacity() const {
			return (_capacity);
		};

		// MODIFIERS
		void	assign(iterator first, iterator last) {
			size_type	distance = last - first;

			if (last - first < 0)
				throw std::length_error("cannot create ft::vector larger than max_size()");

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
				++c;
			}
			--_size;
			return (position + 1);
		};
		iterator	erase(iterator first, iterator last) {
			int			distance = last - first;
			int			i = 0;	
			iterator	ite = end();
			size_type	value;
			pointer		addr;

			_size -= distance;
			while (i < distance)
			{
				addr = &(first + i);
				_c.destroy(addr);
				++i;
			}
			if (distance < 0)
				moveContentForward(first, distance * (-1));
			disp("VEC IN ERASE", 1);
			displayVec();
			i = 0;
			while (last + i != ite && i != distance * (-1))
			{
				addr = &(first + i);
				value = *(last + i);
				disp("VALUE IN ERASE", value);
				_c.destroy(addr);
				_c.construct(addr, value);
				++i;
			}
			return (last);
		};
		void	swap(ft::vector<T, allocator_type>& x) {
			iterator	it1 = begin();
			iterator	it2 = x.begin();
			iterator	ite1 = end();
			iterator	ite2 = x.end();
			size_type	tmp;
			allocator_type	x_alloc = x.get_allocator();

			while (it1 != ite1 && it2 != ite2)
			{
				tmp = *it1;
				_c.destroy(&it1);
				_c.construct(&it1, *it2);
				x_alloc.destroy(&it2);
				x_alloc.construct(&it2, tmp);
				++it1;
				++it2;
			}
			if (_size > x.size())
			{
				while (it1 != ite1)
				{
					x_alloc.construct(&it2, *it1);
					_c.destroy(&it1);
					++it1;
					++it2;
				}
			}
			else
			{
				while (it2 != ite2)
				{
					_c.construct(&it1, *it2);
					++it1;
					++it2;
				}
			}
			tmp = _size;
			_size = x.size();
			x.resize(tmp);
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
			void	moveContentFrom(iterator from, int n) {
				int	i = 0;
				pointer	addr;
				size_type	value;

				while (i < n)
				{
					addr = &(from + i + n);
				//	disp("ADDR", addr);
					value = *(from + i);
				//	disp("VALUE", value);
				//	_c.destroy(addr);
					_c.construct(addr, value);
					++i;
				}
			};
			void	moveContentForward(iterator from, int n) {
				size_type	value;
				size_type	ret;
				size_type	x = 0;
				size_type	y = 0;
				pointer	addr;

				while (n-- > 0)
				{
					x = y;
					++y;
					value = *(from + x);
					addr = &(from + x);
					_c.destroy(addr);
					while (x < _size + y)
					{
						ret = *(from + x + 1);
						addr = &(from + x + 1);
						_c.destroy(addr);
						_c.construct(addr, value);
						value = ret;
						++x;
					}
				}
			};
			void	displayVec(void)
			{
				iterator	it = begin();
				iterator	ite = end();

				disp("SIZE", size());
				while (it != ite)
				{
					std::cout << " - " << *it << std::endl;
					it++;
				}
			}
			/*void	swap(iterator x, iterator y) {
				size_type	val1 = *x;
				pointer	ptr1 = &x;
				size_type	val2 = *y;
				pointer	ptr2 = &y;


			};*/
};
#endif
