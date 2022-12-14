#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft 
{
	template < bool B, class T = bool > struct	enable_if {};
	template <class T> struct	enable_if<true, T>
	{
		typedef T	type;
	};
}
#endif
