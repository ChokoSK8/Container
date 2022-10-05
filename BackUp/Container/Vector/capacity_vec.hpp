#ifndef CAPACITY_VEC_HPP
# define CAPACITY_VEC_HPP

size_type	size(void) const
{
	return (_size);
};

size_type	max_size(void) const
{
	return (_c.max_size());
};

void	resize(size_type n, value_type val = value_type())
{
	if (_size < n)
	{
		if (_capacity < n)
			reserve(n);
		insert(end(), n - _size, val);
	}
	else if (_size > n)
		erase(begin() + n, end());
};

size_type	capacity() const
{
	return (_capacity);
};

bool	empty(void) const
{
	return (_size == 0);
};

void	reserve(size_type n)
{
	if (_capacity < n)
	{
		allocator_type	res;
		pointer		resFirst = res.allocate(n);
		size_type	i = 0;
	
		while (i < _size)
		{
			res.construct(resFirst + i, _first[i]);
			++i;
		}
		clear();
		_size = i;
		_c.deallocate(_first, _capacity);
		_c = res;
		_capacity = n;
		_first = resFirst;
	}
};
#endif
