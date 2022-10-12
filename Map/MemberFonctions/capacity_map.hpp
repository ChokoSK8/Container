#ifndef CAPACITY_MAP_HPP
# define CAPACITY_MAP_HPP
# include <sstream>

bool	empty(void) const
{
	return (_size == 0);
};

size_type	size(void) const
{
	return (_size);
};

size_type	max_size(void) const
{
	return (_c.max_size());
};
#endif
