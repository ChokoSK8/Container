#ifndef COMPARAISON_OPERATOR_VEC_HPP
# define COMPARAISON_OPERATOR_VEC_HPP

template <class T, class Alloc>  bool operator==(const ft::vector<T,Alloc>& lhs,
		const ft::vector<T,Alloc>& rhs)
{
	typename ft::vector<T, Alloc>::const_iterator	itl = lhs.begin();
	typename ft::vector<T, Alloc>::const_iterator	itr = rhs.begin();
	typename ft::vector<T, Alloc>::const_iterator	itel = lhs.end();
	typename ft::vector<T, Alloc>::const_iterator	iter = rhs.end();

	if (lhs.size() != rhs.size())
		return (false);
	while (itl != itel && itr != iter)
	{
		if (*itl != *itr)
			return (false);
		++itl;
		++itr;
	}
	if (itl != itel || itr != iter)
		return (false);
	return (true);
};
template <class T, class Alloc>  bool operator!=(const ft::vector<T,Alloc>& lhs,
		const ft::vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
};
template <class T, class Alloc>  bool operator<=(const ft::vector<T,Alloc>& lhs,
		const ft::vector<T,Alloc>& rhs)
{
	typename ft::vector<T, Alloc>::const_iterator	itl = lhs.begin();
	typename ft::vector<T, Alloc>::const_iterator	itr = rhs.begin();
	typename ft::vector<T, Alloc>::const_iterator	itel = lhs.end();
	typename ft::vector<T, Alloc>::const_iterator	iter = rhs.end();

	while (itl != itel && itr != iter)
	{
		if (*itl != *itr)
			return (*itl <= *itr);
		++itl;
		++itr;
	}
	return (lhs.size() <= rhs.size());
};
template <class T, class Alloc>  bool operator>(const ft::vector<T,Alloc>& lhs,
		const ft::vector<T,Alloc>& rhs)
{
	return (!(lhs <= rhs));
};
template <class T, class Alloc>  bool operator>=(const ft::vector<T,Alloc>& lhs,
		const ft::vector<T,Alloc>& rhs)
{
	return (rhs <= lhs);
};
template <class T, class Alloc>  bool operator<(const ft::vector<T,Alloc>& lhs,
		const ft::vector<T,Alloc>& rhs)
{
	return (!(rhs <= lhs));
};
#endif
