#ifndef PAIR_HPP
# define PAIR_HPP

template < class T1, class T2 > struct	ft::pair
{
	typedef T1	key_type;
	typedef T2	content_type;

	key_type	first;
	content_type	second;

	// CONSTRUCTORS
	pair() : first(), second() {};
	pair(const T1& x, const T2& y) : first(x), second(y)  {};
	template < class U1, class U2 > pair(const pair<U1, U2>& p) :
			first(p.first), second(p.second) {};
	~pair() {};

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
	return (lhs.first == rhs.first && lhs.second == rhs.second);
};
template < class T1, class T2 >
bool	operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs)
{
	return (!(lhs.first == rhs.first && lhs.second == rhs.second));
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
