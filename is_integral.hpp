#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP
# include "containers.h"

template < class T, T v > struct	integral_constant
{
	static T	value = v;
	typedef value_type	T;
	typedef type		integral_constant;
	operator value_type() const { return value; };
	value_type	operator()() const { return value; };
};

template < typename T > struct ft::is_integral : public integral_constant<bool, false>;
template < typename T > struct ft::is_integral : public integral_constant<bool, false>;
#endif
