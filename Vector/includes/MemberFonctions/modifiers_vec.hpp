#ifndef MODIFIERS_VEC_HPP
# define MODIFIERS_VEC_HPP

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

template < class InputIterator > 
void	assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0)
{
	size_type	dist = ft::distance(first, last);
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

void	pop_back(void)
{
	if (_size)
	{
		_c.destroy(end().base() - 1);
		--_size;
	}
};

iterator	insert(iterator position, const value_type& val)
{
	difference_type	dist = ft::distance(begin(), position);

	insert(position, 1, val);
	return (begin() + dist);
};

void	insert(iterator position, size_type n, const value_type& val)
{
	size_type	dist = ft::distance(begin(), position);
	size_type	i = dist + n;
	size_type	newCapacity = getNewCapacity(n);

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

template < class InputIterator >
void	insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0)
{
	if (!checkPosition(position) || !checkOrder(first, last))
		return ;
	
	size_type	range = ft::distance(first, last);
	size_type	dist = ft::distance(begin(), position);
	size_type	i = dist + range;
	pointer		old_first;
	size_type	old_capacity = _capacity;
	size_type	newCapacity = getNewCapacity(range);

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
	iterator	ite = end();
	size_type	c = 1;
	pointer		addrP = position.base();

	if (position - begin() < 0 || end() - position < 0)
		throw std::out_of_range("vector::erase");
	_c.destroy(addrP);
	while (position + c != ite)
	{
		_c.construct(addrP + c - 1, *(addrP + c));
		_c.destroy(addrP + c);
		++c;
	}
	--_size;
	return (position);
};

iterator	erase(iterator first, iterator last)
{
	size_type	dist = ft::distance(first, last);
	size_type	i = 0;
	iterator	ite = end();
	pointer		addrF = first.base();
	pointer		addrL = last.base();

	if (dist < 0 || !doesBelong(first, last))
		throw std::out_of_range("vector::erase");
	_size -= dist;
	while (i < dist)
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
	return (first);
};

void	swap(ft::vector<T, allocator_type>& x)
{
	pointer			firstTmp = _first;
	size_type		sizeTmp = _size;
	size_type		capacityTmp = _capacity;
	allocator_type		cTmp = _c;

	_first = x._first;
	_size = x._size;
	_capacity = x._capacity;
	_c = x._c;
	x._first = firstTmp;
	x._size = sizeTmp;
	x._capacity = capacityTmp;
	x._c = cTmp;
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
