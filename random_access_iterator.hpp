#ifdef ITERATOR_HPP
# ifndef RANDOM_ACCESS_ITERATOR_HPP
#  define RANDOM_ACCESS_ITERATOR_HPP
#  include "iterator.hpp"
#  include "iterator.h"
#  include "containers.h"

template < class T >
class	ft::random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
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
		random_access_iterator(void) : p(NULL) {};
		explicit random_access_iterator(pointer x) : p(x) {};
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
		bool	operator==(const ft::random_access_iterator<T>& rhs) {
			return (p == rhs.p);
		};
		bool	operator!=(const ft::random_access_iterator<T>& rhs) {
			return (p != rhs.p);
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
		ft::random_access_iterator<T>	operator+(difference_type n) {
			random_access_iterator<T>	tmp(*this);

			while (n--)
				++tmp;
			return (tmp);
		};
		ft::random_access_iterator<T>	operator-(difference_type n) const {
			random_access_iterator<T>	tmp(*this);

			while (n--)
				--tmp;
			return (tmp);
		};
		difference_type	operator-(ft::random_access_iterator<T> rhs) const {
			difference_type	res = p - rhs.base();
			return (res);
		};

		// COMPARAISON
		bool	operator<(const ft::random_access_iterator<T>& rhs) const {
			return (p < rhs.base());
		};
		bool	operator>(const ft::random_access_iterator<T>& rhs) const {
			return (p > rhs.base());
		};
		bool	operator<=(const ft::random_access_iterator<T>& rhs) const {
			return (p <= rhs.base());
		};
		bool	operator>=(const ft::random_access_iterator<T>& rhs) const {
			return (p >= rhs.base());
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
# endif
#endif
