#ifndef CAPACITY_VEC_HPP
# define CAPACITY_VEC_HPP

size_type	size(void) const {
	return (_size);
};

size_type	max_size(void) const {
	return (_c.max_size());
};

//void	resize(size_type n, value_type val = value_type()) {
//	reserve(n);
//	if (_size < n)
//		// INSERT insert(end(), n, val);
//};

size_type	capacity() const {
	return (_capacity);
};

bool	empty(void) const {
	return (_size == 0);
};

void	reserve(size_type n) {
	size_type	tmp = _size;
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
		_size = tmp;
		_c.deallocate(_first, _capacity);
		_c = res;
		_capacity = n;
		_first = resFirst;
	}
};
#endif
