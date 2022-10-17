#ifndef OBSERVERS_MAP_HPP
# define OBSERVERS_MAP_HPP

key_compare	key_comp(void) const
{
	return (key_compare(_keyComp));
};

value_compare	value_comp(void) const
{
	return (value_compare(_keyComp));
};
#endif
