#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator.h"
# include "containers.h"

template < class T >
class	ft::reverse_iterator : ft::iterator<std::random_access_iterator_tag, T>
{
	public:
		typedef T			value_type;
		typedef std::ptrdiff_t		difference_type;
		typedef T*			pointer;
		typedef T&			reference;

	protected:
		pointer	p;

	public:
		reverse_iterator(void) : p(NULL) {};
		reverse_iterator(pointer x) : p(x) {};
		reverse_iterator(const ft::reverse_iterator<T>& mit) : p(mit.p) {};
		reverse_iterator	operator=(const ft::reverse_iterator<T>& mit) {
			p = mit.p;
			return (*this);
		}
		~reverse_iterator() {};
		pointer	base(void) const {
			return (p);
		};
		pointer	operator->(void) const{
			return (&(operator*()));
		};
		bool	operator==(const ft::reverse_iterator<T>& rhs) {
			return (p == rhs.p);
		};
		bool	operator!=(const ft::reverse_iterator<T>& rhs) {
			return (p != rhs.p);
		};
		ft::reverse_iterator<T>	operator++(void) {
			--p;
			return (*this);
		};
		ft::reverse_iterator<T>	operator++(int) {
			ft::reverse_iterator<T>	tmp(*this);
			--p;
			return (tmp);
		};
		ft::reverse_iterator<T>	operator--(void) {
			++p;
			return (*this);
		};
		ft::reverse_iterator<T>	operator--(int) {
			ft::reverse_iterator<T>	tmp(*this);
			++p;
			return (tmp);
		};
		value_type	operator*(void) {
			return (*p);
		};
		ft::reverse_iterator<T>	operator+(difference_type n) {
			ft::reverse_iterator<T>	tmp(*this);

			tmp -= n;
			return (tmp);
		};
		ft::reverse_iterator<T>	operator-(difference_type n) {
			ft::reverse_iterator<T>	tmp(*this);

			tmp += n;
			return (tmp);
		};
		value_type	operator[](int n) {
			return (*(p + n));
		}
};
#endif
