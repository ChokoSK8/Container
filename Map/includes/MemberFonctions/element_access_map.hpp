#ifndef ELEMENT_ACCESS_MAP_HPP
# define ELEMENT_ACCESS_MAP_HPP

mapped_type&	operator[](const key_type& k)
{
	return (insert(ft::make_pair(k, mapped_type())).first->second);
};

mapped_type&	at(const key_type& k)
{
	iterator	found = find(k);

	if (found == end())
		throw std::out_of_range("map::at");
	return (found->second);
};

const mapped_type&	at(const key_type& k) const
{
	iterator	found = find(k);

	if (found == end())
		throw std::out_of_range("map::at");
	return (found->second);
};
#endif
