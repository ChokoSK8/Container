#ifndef ELEMENT_ACCESS_VEC_HPP
# define ELEMENT_ACCESS_VEC_HPP

reference	operator[](size_type n)
{
	return (_first[n]);
};

const_reference	operator[](size_type n) const
{
	return (_first[n]);
};

reference	at(size_type n)
{
	if (n >= _size)
		throw std::out_of_range("vector");
	return (_first[n]);
};

const_reference	at(size_type n) const
{
	if (n >= _size)
		throw std::out_of_range("vector");
	return (_first[n]);
};

reference	front(void)
{
	return (_first[0]);
};

const_reference	front(void) const
{
	return (_first[0]);
};

reference	back(void)
{
	return (_first[_size - 1]);
};

const_reference	back(void) const
{
	return (_first[_size - 1]);
};
#endif
