#ifndef INPUT_ITERATOR_HPP
# define INPUT_ITERATOR_HPP
# include "iterator.h"

template < class Iterator>
class	ft::input_iterator : public ft::iterator <Iterator> 
{
	protected:
		pointer	p;

	public:
		input_iterator(void) : p(NULL) {};
		input_iterator(pointer x) : p(x) {};
		input_iterator(const ft::input_iterator<T>& mit) : p(mit.p) {};
		input_iterator	operator=(const ft::input_iterator<T>& mit) {
			p = mit.p;
			return (*this);
		}
		~input_iterator() {};
		pointer	base(void) const {
			return (p);
		};
		bool	operator==(const ft::input_iterator<T>& rhs) {
			return (p == rhs.p);
		};
		bool	operator!=(const ft::input_iterator<T>& rhs) {
			return (p != rhs.p);
		};
		value_type	operator*(void) {
			return (*p);
		};
		pointer		operator->(void) const {
			return (&(operator*()));
		};
		ft::input_iterator<T>	operator++(void) {
			++p;
			return (*this);
		};
		ft::input_iterator<T>	operator++(int) {
			ft::input_iterator<T>	tmp(*this);
			++p;
			return (tmp);
		};
};
#endif
