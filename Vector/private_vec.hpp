#ifndef PRIVATE_VEC_HPP
# define PRIVATE_VEC_HPP

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
};

void	replaceAllocator(iterator first, iterator last, size_type capacity)
{
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

void	replaceAllocator(size_type n, value_type val)
{
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

void	replaceElements(size_type n, value_type val)
{
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

void	replaceElements(iterator first, iterator last)
{
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

int	checkPosition(iterator position)
{
	int	distBegin = position - begin();
	int	distEnd = end() - position;

	if (distBegin < 0 || distEnd < 0)
	{
		std::cout << "vector::insert --> position not valid"
			<< std::endl;
		return (0);
	}
	return (1);
};

template < class InputIterator >
int	checkOrder(InputIterator first, InputIterator last)
{
	int	dist = last - first;

	if (dist < 0)
	{
		throw std::out_of_range("InputIterator's order invalid");
		return (0);
	}
	return (1);
}

void	moveContentForward(size_type n_moves, size_type to)
{
	size_type	i = _size + n_moves;
	size_type	j = 1;

	while (i > to)
	{
		if (i < _size)
			_c.destroy(_first + i);
		_c.construct(_first + i - 1, _first[_size - j]);
		--i;
		++j;
	}
};

pointer	copyVecAndIncreaseCapacity(size_type newCapacity)
{
	if (newCapacity < _capacity)
		newCapacity = _capacity;

	allocator_type	res;
	pointer		resFirst = res.allocate(newCapacity);
	size_type	i = 0;
	pointer		old = _first;

	while (i < _size)
	{
		res.construct(resFirst + i, *(_first + i));
		++i;
	}
	_c = res;
	_capacity = newCapacity;
	_first = resFirst;
	return (old);
};
#endif
