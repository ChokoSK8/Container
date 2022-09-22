#ifdef ITERATOR_HPP
# ifndef REVERSE_ITERATOR_HPP
#  define REVERSE_ITERATOR_HPP
#  include "iterator.hpp"
#  include "iterator.h"
#  include "containers.h"
#  include "iterator_traits.hpp"
#  include "random_access_iterator.hpp" 

template < class I >
class	ft::reverse_iterator : public ft::iterator<
		typename iterator_traits<I>::iterator_category,
		typename iterator_traits<I>::value_type,
		typename iterator_traits<I>::difference_type,
		typename iterator_traits<I>::pointer,
		typename iterator_traits<I>::reference>
{
	public:
		typedef ft::iterator_traits<I>			_traits;
		typedef typename _traits::iterator_category	iterator_category;
		typedef typename _traits::value_type		value_type;
		typedef typename _traits::difference_type	difference_type;
		typedef typename _traits::pointer		pointer;
		typedef typename _traits::reference		reference;

	protected:
		I	p;

	public:
		reverse_iterator(void) : p(NULL) {};
		reverse_iterator(I x) : p(x) {};
		template < class U > reverse_iterator(const ft::reverse_iterator<U>& mit) :
			p(mit.base()) {};
		~reverse_iterator() {};
		pointer	base(void) const {
			return (p.base());
		};
		reference	operator*(void) const {
			I	tmp = p;
			--tmp;
			return (*tmp);
		};
		ft::reverse_iterator<I>	operator+(difference_type n) const {
			ft::reverse_iterator<I>	tmp(*this);

			while (n--)
				++tmp;
			return (tmp);
		};
		ft::reverse_iterator<I>&	operator++(void) {
			--p;
			return (*this);
		};
		ft::reverse_iterator<I>	operator++(int) {
			ft::reverse_iterator<I>	tmp(*this);
			--p;
			return (tmp);
		};
		ft::reverse_iterator<I>&	operator+=(difference_type n) {
			p -= n;
			return (*this);
		};
		ft::reverse_iterator<I>	operator-(difference_type n) const {
			ft::reverse_iterator<I>	tmp(*this);

			tmp -= n;
			return (tmp);
		};
		ft::reverse_iterator<I>	operator--(void) {
			++p;
			return (*this);
		};
		ft::reverse_iterator<I>	operator--(int) {
			ft::reverse_iterator<I>	tmp(*this);
			++p;
			return (tmp);
		};
		ft::reverse_iterator<I>&	operator-=(difference_type n) {
			p += n;
			return (*this);
		};
		pointer	operator->(void) const {
			return (&(operator*()));
		};
		reference	operator[](difference_type n) {
			return (p[-n - 1]);
		}
		difference_type	operator-(const ft::reverse_iterator<I>& rhs) const {
			difference_type	res = rhs.base() - base();
			return (res);
		};
};

	// RELATIONAL OPERAIORS
template <class I> bool	operator==(const ft::reverse_iterator<I>& x,
		const ft::reverse_iterator<I>& y) {
	return (*(x.base()) == *(y.base()));
};
template <class I> bool	operator!=(const ft::reverse_iterator<I>& x,
		const ft::reverse_iterator<I>& y) {
	return (*(x.base()) != *(y.base()));
};
template <class I> bool	operator<=(const ft::reverse_iterator<I>& x,
		const ft::reverse_iterator<I>& y) {
	return (*(x.base()) >= *(y.base()));
};
template <class I> bool	operator>=(const ft::reverse_iterator<I>& x,
		const ft::reverse_iterator<I>& y) {
	return (*(x.base()) <= *(y.base()));
};
template <class I> bool	operator<(const ft::reverse_iterator<I>& x,
		const ft::reverse_iterator<I>& y) {
	return (*(x.base()) > *(y.base()));
};
template <class I> bool	operator>(const ft::reverse_iterator<I>& x,
		const ft::reverse_iterator<I>& y) {
	return (*(x.base()) < *(y.base()));
};
//-------LEFI-RIGHI---------
template <class R, class L> bool	operator==(const ft::reverse_iterator<R>& x,
		const ft::reverse_iterator<L>& y) {
	return (x.base() == y.base());
};
template <class R, class L> bool	operator!=(const ft::reverse_iterator<R>& x,
		const ft::reverse_iterator<L>& y) {
	return (*(x.base()) != *(y.base()));
};
template <class R, class L> bool	operator<=(const ft::reverse_iterator<R>& x,
		const ft::reverse_iterator<L>& y) {
	return (*(x.base()) >= *(y.base()));
};
template <class R, class L> bool	operator>=(const ft::reverse_iterator<R>& x,
		const ft::reverse_iterator<L>& y) {
	return (*(x.base()) <= *(y.base()));
};
template <class R, class L> bool	operator<(const ft::reverse_iterator<R>& x,
		const ft::reverse_iterator<L>& y) {
	return (*(x.base()) > *(y.base()));
};
template <class R, class L> bool	operator>(const ft::reverse_iterator<R>& x,
		const ft::reverse_iterator<L>& y) {
	return (*(x.base()) < *(y.base()));
};

	// OPERAIOR +
template <class I> ft::reverse_iterator<I> operator+(typename
		ft::reverse_iterator<I>::difference_type n,
		const ft::reverse_iterator<I>& rev_it) {
	ft::reverse_iterator<I>	tmp(rev_it);

	tmp += n;
	return (tmp);
};

	// OPERAIOR -
template <class I> ft::reverse_iterator<I> operator-(typename
		ft::reverse_iterator<I>::difference_type n,
		const ft::reverse_iterator<I>& rev_it) {
	ft::reverse_iterator<I>	tmp(rev_it);

	tmp -= n;
	return (tmp);
};
# endif
#endif
