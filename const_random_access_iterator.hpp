#ifndef CONST_RANDOM_ACCESS_ITERATOR_HPP
# define CONST_RANDOM_ACCESS_ITERATOR_HPP
# include "containers.h"

template < class T >
class	ft::const_random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
	public:
		typedef random_access_iterator_tag	iterator_category;
		typedef T				value_type;
		typedef std::ptrdiff_t			difference_type;
		typedef T*				pointer;
		typedef T&				reference;

	protected:
		pointer	p;

	public:
		const_random_access_iterator(void) : p(NULL) {};
		const_random_access_iterator(pointer x) : p(x) {};
		const_random_access_iterator(const ft::const_random_access_iterator<T>& mit) : p(mit.p) {};
		const_random_access_iterator	operator=(const ft::const_random_access_iterator<T>& mit) {
			p = mit.p;
			return (*this);
		}
		~const_random_access_iterator() {};
		pointer	base(void) const {
			return (p);
		};
		bool	operator==(const ft::const_random_access_iterator<T>& rhs) {
			return (p == rhs.p);
		};
		bool	operator!=(const ft::const_random_access_iterator<T>& rhs) {
			return (p != rhs.p);
		};
		value_type	operator*(void) {
			return (*p);
		};
		pointer		operator->(void) const {
			return (&(operator*()));
		};
		ft::const_random_access_iterator<T>	operator++(void) {
			++p;
			return (*this);
		};
		ft::const_random_access_iterator<T>	operator++(int) {
			ft::const_random_access_iterator<T>	tmp(*this);
			++p;
			return (tmp);
		};
		ft::const_random_access_iterator<T>	operator--(void) {
			--p;
			return (*this);
		};
		ft::const_random_access_iterator<T>	operator--(int) {
			ft::const_random_access_iterator<T>	tmp(*this);
			--p;
			return (tmp);
		};
		ft::const_random_access_iterator<T>	operator+(difference_type n) {
			pointer	tmp = p;

			p += n;
			return (tmp);
		};
		ft::const_random_access_iterator<T>	operator-(difference_type n) {
			pointer	tmp = p;

			p -= n;
			return (tmp);
		};
		difference_type	operator-(ft::const_random_access_iterator<T> rhs) {
			difference_type	res = p - rhs.base();
			return (res);
		};
		bool	operator<(const ft::const_random_access_iterator<T>& rhs) const {
			return (p < rhs.base());
		};
		bool	operator>(const ft::const_random_access_iterator<T>& rhs) const {
			return (p > rhs.base());
		};
		bool	operator<=(const ft::const_random_access_iterator<T>& rhs) const {
			return (p <= rhs.base());
		};
		bool	operator>=(const ft::const_random_access_iterator<T>& rhs) const {
			return (p >= rhs.base());
		};
		ft::const_random_access_iterator<T>	operator+=(difference_type n) {
			p += n;
			return (*this);
		};
		ft::const_random_access_iterator<T>	operator-=(difference_type n) {
			p -= n;
			return (*this);
		};
		reference	operator[](int n) {
			return (*(p + n));
		}
};
#endif
