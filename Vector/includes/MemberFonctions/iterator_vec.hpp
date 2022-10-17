#ifndef ITERATOR_VEC_HPP
# define ITERATOR_VEC_HPP

iterator	begin(void)
{
	return (iterator(_first));
};

const_iterator	begin(void) const
{
	return (const_iterator(_first));
};

iterator	end(void)
{
	return (iterator(_first + _size));
};

const_iterator	end(void) const
{
	return (const_iterator(_first + _size));
};

reverse_iterator	rbegin(void)
{
	return (end());
};

const_reverse_iterator	rbegin(void) const
{
	return (end());
};

reverse_iterator	rend(void)
{
	return (begin());
};

const_reverse_iterator	rend(void) const
{
	return (begin());
};

#endif
