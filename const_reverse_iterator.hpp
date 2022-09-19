#ifndef CONST_REVERSE_ITERATOR_HPP
# define CONST_REVERSE_ITERATOR_HPP
# include "iterator.h"
# include "containers.h"

template < class T >
class	ft::const_reverse_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
	public:
		typedef T			value_type;
		typedef std::ptrdiff_t		difference_type;
		typedef T*			pointer;
		typedef T&			reference;

	protected:
		pointer	p;

	public:
		const_reverse_iterator(void) : p(NULL) {};
		const_reverse_iterator(pointer x) : p(x) {};
		const_reverse_iterator(const ft::const_reverse_iterator<T>& mit) : p(mit.p) {};
		const_reverse_iterator	operator=(const ft::const_reverse_iterator<T>& mit) {
			p = mit.p;
			return (*this);
		}
		~const_reverse_iterator() {};
		pointer	base(void) const {
			return (p);
		};
		pointer	operator->(void) const{
			return (&(operator*()));
		};
		bool	operator==(const ft::const_reverse_iterator<T>& rhs) {
			return (p == rhs.p);
		};
		bool	operator!=(const ft::const_reverse_iterator<T>& rhs) {
			return (p != rhs.p);
		};
		ft::const_reverse_iterator<T>	operator++(void) {
			--p;
			return (*this);
		};
		ft::const_reverse_iterator<T>	operator++(int) {
			ft::const_reverse_iterator<T>	tmp(*this);
			--p;
			return (tmp);
		};
		ft::const_reverse_iterator<T>	operator--(void) {
			++p;
			return (*this);
		};
		ft::const_reverse_iterator<T>	operator--(int) {
			ft::const_reverse_iterator<T>	tmp(*this);
			++p;
			return (tmp);
		};
		value_type	operator*(void) {
			return (*p);
		};
		ft::const_reverse_iterator<T>	operator+(difference_type n) {
			ft::const_reverse_iterator<T>	tmp(*this);

			tmp -= n;
			return (tmp);
		};
		ft::const_reverse_iterator<T>	operator-(difference_type n) {
			ft::const_reverse_iterator<T>	tmp(*this);

			tmp += n;
			return (tmp);
		};
		value_type	operator[](int n) {
			return (*(p + n));
		}
};
#endif
