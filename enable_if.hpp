#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

template < bool B > struct	ft::enable_if {};
template <> struct	ft::enable_if<true>
{
	typedef void	type;
};
#endif
