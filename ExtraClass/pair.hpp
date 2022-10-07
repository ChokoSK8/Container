#ifndef PAIR_HPP
# define PAIR_HPP

template < class T1, class T2 > struct	ft::pair
{
	typedef T1	key_type;
	typedef T2	content_type;

	T1	first;
	T2	second;

	// CONSTRUCTORS
	pair() : first(0), second(0) {};
	pair(const T1& x, const T2& y) : first(x), second(y)  {};
	template < class U1, class U2 > pair(const pair<U1, U2>& p) :
			first(p.first), second(p.second) {};

	// OPERATOR=	
	pair&	operator=(const pair& other) {
		first = other.first;
		second = other.second;
		return (*this);
	};
	template < class U1, class U2 > pair&	operator=(const pair<U1, U2>& other) {
		first = other.first;
		second = other.second;
		return (*this);
	};
};

template < class T1, class T2 >
ft::pair<T1, T2>	ft::make_pair(T1 x, T2 y)
{
	return (ft::pair<T1, T2>(x, y));
};

template < class T1, class T2 >
bool	operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return (lhs.first == rhs.first && lhs.first == rhs.first);
};
template < class T1, class T2 >
bool	operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return (!(lhs.first == rhs.first && lhs.first == rhs.first));
};
template < class T1, class T2 >
bool	operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	if (lhs.first == rhs.first)
		return (lhs.second <= rhs.second);
	return (lhs.first < rhs.first);
};
template < class T1, class T2 >
bool	operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	if (lhs.first == rhs.first)
		return (lhs.second >= rhs.second);
	return (lhs.first > rhs.first);
};
template < class T1, class T2 >
bool	operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	if (lhs.first == rhs.first)
		return (lhs.second < rhs.second);
	return (lhs.first < rhs.first);
};
template < class T1, class T2 >
bool	operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	if (lhs.first == rhs.first)
		return (lhs.second > rhs.second);
	return (lhs.first > rhs.first);
};
#endif
