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
#endif
