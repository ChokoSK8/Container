#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP
# include "containers.h"

template < class T >
class ft::const_iterator
{
	public:
		typedef T				value_type;
		typedef std::ptrdiff_t			difference_type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef T				const_iterator_category;

	protected:
		pointer	p;

	public:
		const_iterator(const pointer x) : p(x) {};
		const_iterator(const ft::const_iterator<T>& mit) : p(mit.p) {};
		~const_iterator() {};
		bool	operator==(const ft::const_iterator<T>& rhs) const {
			return (p == rhs.p);
		};
		bool	operator!=(const ft::const_iterator<T>& rhs) const {
			return (p != rhs.p);
		};
		const pointer	operator&(void) const {
			return (p);
		};
		ft::const_iterator<T>	operator++(void) {
			p++;
			return (*this);
		};
		ft::const_iterator<T>	operator++(int) {
			ft::const_iterator<T>	tmp(*this);
			p++;
			return (tmp);
		};
		ft::const_iterator<T>	operator--(void) {
			p--;
			return (*this);
		};
		ft::const_iterator<T>	operator--(int) {
			ft::const_iterator<T>	tmp(*this);
			p--;
			return (tmp);
		};
		value_type	operator*(void) const {
			return (*p);
		};

		//	SUP
		ft::const_iterator<T>	operator+(int n) const {
			pointer	tmp = p;
			while (n--)
				tmp++;
			return (tmp);
		};
		ft::const_iterator<T>	operator-(int n) const {
			pointer	tmp = p;
			while (n--)
				tmp--;
			return (tmp);
		};
		int	operator+(ft::const_iterator<T> rhs) const {
			int res = p + rhs.get_pointer();
			return (res);
		};
		int	operator-(ft::const_iterator<T> rhs) const {
			int res = p - rhs.get_pointer();
			return (res);
		};
		const pointer	get_pointer(void) const {
			return (p);
		};
};
#endif
