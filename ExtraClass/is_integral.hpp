#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template < class T > struct is_integral
	{
		static bool const	value = false;
	};
	template <> struct is_integral<int>
	{
		static bool const	value = true;
	};
	template <> struct is_integral<bool>
	{
		static bool const	value = true;
	};
	template <> struct is_integral<char>
	{
		static bool const	value = true;
	};
	template <> struct is_integral<wchar_t>
	{
		static bool const	value = true;
	};
	template <> struct is_integral<short>
	{
		static bool const	value = true;
	};
	template <> struct is_integral<long>
	{
		static bool const	value = true;
	};
	template <> struct is_integral<long long>
	{
		static bool const	value = true;
	};
}
#endif
