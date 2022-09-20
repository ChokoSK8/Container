#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP
# include "containers.h"

template < class T > struct ft::is_integral
{
	static bool const	value = false;
};
template <> struct ft::is_integral<int>
{
	static bool const	value = true;
};
template <> struct ft::is_integral<bool>
{
	static bool const	value = true;
};
template <> struct ft::is_integral<char>
{
	static bool const	value = true;
};
template <> struct ft::is_integral<wchar_t>
{
	static bool const	value = true;
};
template <> struct ft::is_integral<short>
{
	static bool const	value = true;
};
template <> struct ft::is_integral<long>
{
	static bool const	value = true;
};
template <> struct ft::is_integral<long long>
{
	static bool const	value = true;
};
#endif
