#ifndef MODIFIERS_VEC_HPP
# define MODIFIERS_VEC_HPP
# include "../containers.h"

void	assign(iterator first, iterator last)
{
	size_type	dist = last - first;
	size_type	i = 0;

	if (dist > max_size())
		throw std::length_error("cannot create ft::vector larger than max_size()");
	resize(dist);
	while (first != last)
	{
		_c.destroy(_first + i);
		_c.construct(_first + i, *first);
		++i;
		++first;
	}
};

void	assign(size_type n, const value_type& val)
{
	clear();
	if (n > _capacity)
	{
		_c.deallocate(_first, _capacity);
		_first = _c.allocate(n - _capacity);
		_capacity = n;
	}
	while (_size < n)
	{
		_c.construct(&_first[_size], val);
		++_size;
	}
};

void	push_back(const value_type& val)
{
	size_type	newCapacity;

	if (_size + 1 > _capacity)
	{
		if (!_capacity)
			newCapacity = 1;
		else
			newCapacity = _capacity * 2;
		reserve(newCapacity);
		_c.construct(_first + _size, val);
	}
	else
	{
		_c.construct(_first + _size, val);
	}
	++_size;
};

void	pop_back(void) {
	if (_size)
	{
		_c.destroy(&(end() - 1));
		--_size;
	}
};

void	insert(iterator position, const value_type& val)
{
	insert(position, 1, val);
};

void	insert(iterator position, size_type n, const value_type& val)
{
	size_type	dist = position - begin();
	size_type	i = dist + n;
	size_type	newCapacity = getNewCapacity(_size + n);

	if (!checkPosition(position))
		return ;
	reserve(newCapacity);
	moveContentForward(n, i);
	while (dist < i)
	{
		_c.destroy(_first + dist);
		_c.construct(_first + dist, val);
		++dist;
	}
	_size += n;
};

//template < class InputIterator >
void	insert(iterator position, iterator first, iterator last)
{
	if (!checkPosition(position) || !checkOrder(first, last))
		return ;
	
	size_type	range = last - first;
	size_type	dist = position - begin();
	size_type	i = dist + range;
	pointer		old_first;
	size_type	old_capacity = _capacity;
	size_type	newCapacity = getNewCapacity(_size + range);

	old_first = copyVecAndIncreaseCapacity(newCapacity);
	moveContentForward(range, dist + range);
	while (dist < i)
	{
		_c.destroy(_first + dist);
		_c.construct(_first + dist, *first);
		++dist;
		++first;
	}
	_size += range;
	_c.deallocate(old_first, old_capacity);
};

iterator	erase(iterator position)
{
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

iterator	erase(iterator first, iterator last)
{
	int		distance = last - first;
	int		i = 0;	
	iterator	ite = end();
	pointer		addrF = first.base();
	pointer		addrL = last.base();

	if (distance < 0 || !doesBelong(first, last))
		throw std::out_of_range("vector::erase");
	_size -= distance;
	while (i < distance)
	{
		_c.destroy(addrF + i);
		++i;
	}
	i = 0;
	while (last + i != ite)
	{
		_c.destroy(addrF + i);
		_c.construct(addrF + i, *(addrL + i));
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

void	clear(void)
{
	size_type	i = 0;

	while (i < _size)
	{
		_c.destroy(_first + i);
		++i;
	}
	_size = 0;
};
#endif
