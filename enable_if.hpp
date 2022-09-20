#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

template < bool B, class T = bool > struct	ft::enable_if {};
template <class T> struct	ft::enable_if<true, T>
{
	typedef T	type;
};
#endif
