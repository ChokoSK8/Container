#ifndef REVERSE_RBRATOR_HPP
# define REVERSE_RBRATOR_HPP
# include "../../../Iterators/iterator_traits.hpp"
# include "../../../Iterators/iterator.hpp"

template < class I >
class	ft::reverse_rbrator : public ft::iterator<
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
		reverse_rbrator(void) : p(NULL) {};
		reverse_rbrator(I x) : p(x) {};
		template < class U > reverse_rbrator(const ft::reverse_rbrator<U>& mit) :
			p(mit.base()) {};
		~reverse_rbrator() {};
		I	base(void) const
		{
			return (p);
		};
		reference	operator*(void) const
		{
			I	tmp = p;

			--tmp;
			return (*tmp);
		};
		ft::reverse_rbrator<I>	operator+(difference_type n) const
		{
			ft::reverse_rbrator<I>	tmp(*this);

			while (n--)
				++tmp;
			return (tmp);
		};
		ft::reverse_rbrator<I>&	operator++(void)
		{
			--p;
			return (*this);
		};
		ft::reverse_rbrator<I>	operator++(int)
		{
			ft::reverse_rbrator<I>	tmp(*this);
			--p;
			return (tmp);
		};
		ft::reverse_rbrator<I>	operator--(void)
		{
			++p;
			return (*this);
		};
		ft::reverse_rbrator<I>	operator--(int)
		{
			ft::reverse_rbrator<I>	tmp(*this);
			++p;
			return (tmp);
		};
		ft::reverse_rbrator<I>	operator-(difference_type n) const
		{
			ft::reverse_rbrator<I>	tmp(*this);

			tmp -= n;
			return (tmp);
		};
		pointer	operator->(void) const
		{
			reverse_rbrator	tmp(p);

			++tmp;
			return (&(*(tmp.base())));
		};
		reference	operator[](difference_type n)
		{
			return (p[-n - 1]);
		}
		difference_type	operator-(const ft::reverse_rbrator<I>& rhs) const
		{
			difference_type	res = rhs.base() - base();
			return (res);
		};
};

	// RELATIONAL OPERATORS

template <class I> bool	operator==(const ft::reverse_rbrator<I>& x,
		const ft::reverse_rbrator<I>& y)
{
	return (x.base() == y.base());
};
template <class I> bool	operator!=(const ft::reverse_rbrator<I>& x,
		const ft::reverse_rbrator<I>& y)
{
	return (x.base() != y.base());
};

	// RIGHT LEFT

template <class R, class L> bool	operator==(const ft::reverse_rbrator<R>& x,
		const ft::reverse_rbrator<L>& y)
{
	return (x.base() == y.base());
};
template <class R, class L> bool	operator!=(const ft::reverse_rbrator<R>& x,
		const ft::reverse_rbrator<L>& y)
{
	return (x.base() != y.base());
};

	// OPERATOR +
template <class I> ft::reverse_rbrator<I> operator+(typename
		ft::reverse_rbrator<I>::difference_type n,
		const ft::reverse_rbrator<I>& rev_it)
{
	ft::reverse_rbrator<I>	tmp(rev_it);

	tmp += n;
	return (tmp);
};

	// OPERATOR -
template <class I> ft::reverse_rbrator<I> operator-(typename
		ft::reverse_rbrator<I>::difference_type n,
		const ft::reverse_rbrator<I>& rev_it)
{
	ft::reverse_rbrator<I>	tmp(rev_it);

	tmp -= n;
	return (tmp);
};
#endif
