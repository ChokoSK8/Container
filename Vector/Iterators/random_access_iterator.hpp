#ifdef ITERATOR_HPP
# ifndef RANDOM_ACCESS_ITERATOR_HPP
#  define RANDOM_ACCESS_ITERATOR_HPP
#  include "../../Iterators/iterator.hpp"
#  include "../../containers.h"
#  include "../../Iterators/iterator_traits.hpp"

template < class T >
class	ft::random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
	public:
		typedef ft::iterator_traits<T>			_traits;
		typedef typename _traits::iterator_category	iterator_category;
		typedef typename _traits::value_type		value_type;
		typedef typename _traits::difference_type	difference_type;
		typedef typename _traits::pointer		pointer;
		typedef typename _traits::reference		reference;

	protected:
		pointer	p;

	public:
		random_access_iterator(void) : p(NULL) {};
		random_access_iterator(pointer x) : p(x) {};
		template < class U > random_access_iterator(const ft::random_access_iterator<U>& mit) {
			p = mit.base();
		};
		template < class U > random_access_iterator&	operator=(const ft::random_access_iterator<U>& mit) {
			p = mit.base();
			return (*this);
		}
		~random_access_iterator() {};
		pointer	base(void) const {
			return (p);
		};
		bool	operator==(const ft::random_access_iterator<T>& rhs) const {
			return (p == rhs.base());
		};
		bool	operator!=(const ft::random_access_iterator<T>& rhs) const {
			return (p != rhs.base());
		};
		reference	operator*(void) const {
			return (*p);
		};
		pointer		operator->(void) const {
			return (&(operator*()));
		};
		ft::random_access_iterator<T>&	operator++(void) {
			++p;
			return (*this);
		};
		ft::random_access_iterator<T>	operator++(int) {
			ft::random_access_iterator<T>	tmp(*this);
			++p;
			return (tmp);
		};
		ft::random_access_iterator<T>&	operator--(void) {
			--p;
			return (*this);
		};
		ft::random_access_iterator<T>	operator--(int) {
			ft::random_access_iterator<T>	tmp(*this);
			--p;
			return (tmp);
		};
		ft::random_access_iterator<T>	operator+(difference_type n) const {
			ft::random_access_iterator<T>	tmp(*this);

			while (n--)
				++tmp;
			return (tmp);
		};
		ft::random_access_iterator<T>	operator-(difference_type n) const {
			ft::random_access_iterator<T>	tmp(*this);

			while (n--)
				--tmp;
			return (tmp);
		};
		difference_type	operator-(const ft::random_access_iterator<T>& rhs) const {
			difference_type	res = p - rhs.base();
			return (res);
		};
		ft::random_access_iterator<T>	operator+=(difference_type n) {
			p += n;
			return (*this);
		};
		ft::random_access_iterator<T>	operator-=(difference_type n) {
			p -= n;
			return (*this);
		};
		reference	operator[](int n) {
			return (*(p + n));
		}
};

template <class T> bool	operator==(const ft::random_access_iterator<T>& x, const ft::random_access_iterator<T>& y) {
	return (x.base() == y.base());
};
template <class T> bool	operator!=(const ft::random_access_iterator<T>& x, const ft::random_access_iterator<T>& y) {
	return (x.base() != y.base());
};
template <class T> bool	operator<=(const ft::random_access_iterator<T>& x, const ft::random_access_iterator<T>& y) {
	return (x.base() <= y.base());
};
template <class T> bool	operator>=(const ft::random_access_iterator<T>& x, const ft::random_access_iterator<T>& y) {
	return (x.base() >= y.base());
};
template <class T> bool	operator<(const ft::random_access_iterator<T>& x, const ft::random_access_iterator<T>& y) {
	return (x.base() < y.base());
};
template <class T> bool	operator>(const ft::random_access_iterator<T>& x, const ft::random_access_iterator<T>& y) {
	return (x.base() > y.base());
};

template <class T> ft::random_access_iterator<T>	operator+(typename ft::random_access_iterator<T>::difference_type	n, ft::random_access_iterator<T> rai) {
	return (rai + n);
};
template <class T> ft::random_access_iterator<T>	operator-(typename ft::random_access_iterator<T>::difference_type	n, ft::random_access_iterator<T> rai) {
	return (rai - n);
};

template <class R, class L> bool	operator==(const ft::random_access_iterator<R>& x, const ft::random_access_iterator<L>& y) {
	return (x.base() == y.base());
};
template <class R, class L> bool	operator!=(const ft::random_access_iterator<R>& x, const ft::random_access_iterator<L>& y) {
	return (x.base() != y.base());
};
template <class R, class L> bool	operator<=(const ft::random_access_iterator<R>& x, const ft::random_access_iterator<L>& y) {
	return (x.base() <= y.base());
};
template <class R, class L> bool	operator>=(const ft::random_access_iterator<R>& x, const ft::random_access_iterator<L>& y) {
	return (x.base() >= y.base());
};
template <class R, class L> bool	operator<(const ft::random_access_iterator<R>& x, const ft::random_access_iterator<L>& y) {
	return (x.base() < y.base());
};
template <class R, class L> bool	operator>(const ft::random_access_iterator<R>& x, const ft::random_access_iterator<L>& y) {
	return (x.base() > y.base());
};
# endif
#endif
