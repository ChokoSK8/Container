#ifndef ELEMENT_ACCESS_MAP_HPP
# define ELEMENT_ACCESS_MAP_HPP

mapped_type&	operator[](const key_type& k)
{
	return (insert(make_pair(k, mapped_type())).first->getContent());
};
mapped_type&	at(const key_type& k)
{
	iterator	found = find(k);

	if (found == end())
		throw std::out_of_range("map::at");
	return (found->getContent());
};
//const mapped_type&	at(const key_type& k) const
//{
//	const_iterator	found = find(k);
//
//	disp("HEY", 1);
//	if (found == end())
//		throw std::out_of_range("map::at");
//	return (found->getContent());
//};
#endif
