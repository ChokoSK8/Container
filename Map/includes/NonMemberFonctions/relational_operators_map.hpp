#ifndef RELATIONAL_OPERATORS_MAP_HPP
# define RELATIONAL_OPERATORS_MAP_HPP

template < class Key, class T, class Compare, class Alloc > 
bool	operator==(const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{
	typename ft::map<Key, T, Compare, Alloc>::const_iterator	l_cit = lhs.begin();
	typename ft::map<Key, T, Compare, Alloc>::const_iterator	l_cite = lhs.end();
	typename ft::map<Key, T, Compare, Alloc>::const_iterator	r_cit = rhs.begin();

	if (lhs.size() == rhs.size())
	{
		while (l_cit != l_cite)
		{
			if (*l_cit != *r_cit)
				return (false);
			++l_cit;
			++r_cit;
		}
		return (true);
	}
	return (false);
};

template < class Key, class T, class Compare, class Alloc > 
bool	operator!=(const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs == rhs));
};

template < class Key, class T, class Compare, class Alloc > 
bool	operator<=(const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{
	typename ft::map<Key, T, Compare, Alloc>::const_iterator	l_cit = lhs.begin();
	typename ft::map<Key, T, Compare, Alloc>::const_iterator	l_cite = lhs.end();
	typename ft::map<Key, T, Compare, Alloc>::const_iterator	r_cit = rhs.begin();
	typename ft::map<Key, T, Compare, Alloc>::const_iterator	r_cite = rhs.end();

	while (l_cit != l_cite && r_cit != r_cite)
	{
		if (*l_cit != *r_cit)
			return (*l_cit <= *r_cit);
		++l_cit;
		++r_cit;
	}
	return (lhs.size() <= rhs.size());
};
template < class Key, class T, class Compare, class Alloc > 
bool	operator>=(const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (rhs <= lhs);
};


template < class Key, class T, class Compare, class Alloc > 
bool	operator<(const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (!(rhs <= lhs));
};

template < class Key, class T, class Compare, class Alloc > 
bool	operator>(const ft::map<Key, T, Compare, Alloc>& lhs,
			const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs <= rhs));
};
#endif
