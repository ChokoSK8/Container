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
		void	resize(size_type n, value_type val = value_type()) {
			size_type	i = _size;

			if (_size < n)
			{
				while (i < n)
				{
					push_back(val);
					++i;
				}
			}
			else if (_size > n)
			{
				while (i > n)
				{
					pop_back();
					--i;
				}
			}
		};
		size_type	capacity() const {
			return (_capacity);
		};
		bool	empty(void) const {
			return (_size == 0);
		};
		void	reserve(size_type n) {
			if (_capacity < n)
				replaceAllocator(begin(), end(), n);
		};

		//	ELEMENT ACCESS
		reference	operator[](size_type n) {
			return (*(_first + n));
		};
		const_reference	operator[](size_type n) const {
			return (*(_first + n));
		};
		reference	at(size_type n) {
			if (n > _size - 1)
				throw std::out_of_range("vector");
			return (*(_first + n));
		};
		const_reference	at(size_type n) const {
			if (n > _size - 1)
				throw std::out_of_range("vector");
			return (*(_first + n));
		};
		reference	front(void) {
			return (*(_first));
		};
		const_reference	front(void) const {
			return (*(_first));
		};
		reference	back(void) {
			return (*(end()));
		};
		const_reference	back(void) const {
			return (*(end()));
		};

		// MODIFIERS
		void	assign(iterator first, iterator last) {
			size_type	distance = last - first;

			if (last - first < 0)
				throw std::length_error("cannot create ft::vector larger than max_size()");

			if (_capacity < distance)
				replaceAllocator(first, last, last - first);
			else
				replaceElements(first, last);
		}
		void	assign(size_type n, const value_type& val) {
			if (n > _capacity)
				replaceAllocator(n, val);
			else
			{
				replaceElements(n, val);
			}
		};
		void	push_back(const value_type& val)
		{
			if (_size + 1 > _capacity)
			{
				if (!_capacity)
					_capacity++;
				else
					_capacity *= 2;
				replaceAllocator(begin(), end(), _capacity);
				_c.construct(&end(), val);
			}
			else
			{
				_c.construct(_first + _size, val);
			}
			_size++;
		}
		void	pop_back(void) {
			if (_size)
			{
				_c.destroy(&(end() - 1));
				--_size;
			}
		};
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
					disp("HEY", 2);
					_c.construct(&it1, *it2);
					disp("HEY", 3);
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
			void	replaceAllocator(iterator first, iterator last, size_type capacity) {
				allocator_type	res;
				pointer		resFirst = res.allocate(capacity);
				size_type	i = 0;

				while (first + i != last)
				{
					res.construct(resFirst + i, *(first + i));
					++i; 
				}
				_c.deallocate(_first, _size);
				_size = last - first;
				_c = res;
				_capacity = capacity;
				_first = resFirst;
			};
			void	replaceAllocator(size_type n, value_type val) {
				allocator_type	res;
				pointer	resFirst = res.allocate(n);
				size_type	i = 0;

				while (i < n)
				{
					res.construct(resFirst + i, val);
					++i;
				}
				_c.deallocate(_first, _size);
				_size = n;
				_c = res;
				_capacity = n;
				_first = resFirst;
			};
			void	replaceElements(size_type n, value_type val) {
				iterator	it = begin();
				size_type	i = 0;

				clear();
				while (i < n)
				{
					_c.construct(&(it + i), val);
					++i;
					++_size;
				}
			};
			void	replaceElements(iterator first, iterator last) {
				size_type	i = 0;

				clear();
				while (first != last)
				{
					_c.construct(_first + i, *first);
					++first;
					++i;
					++_size;
				}
			};
};
#endif
