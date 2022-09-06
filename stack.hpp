#ifndef STACK_HPP
# define STACK_HPP
# include "containers.h"

template<class T, class Container>
class	ft::stack
{
	public:
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;
		typedef Container	container_type;

	protected:
		Container	_c;

	public:
		explicit stack(const Container& ctnr = Container()) {
			_c = ctnr;
		};
		~stack(void) {};

	// ELEMENT ACCESS
		T	top() {
			return (_c.back());
		};

	// CAPACITY
		bool	empty(void) const {
			return (_c.size() == 0);
		};
		size_t	size() const {
			return (_c.size());
		};
	
	// MODIFIERS
		void	push(const T& value) {
			_c.push_back(value);
		};
		void	pop(void) {
			_c.pop_back();
		};

		friend bool	operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs._c == rhs._c);
		};

		friend bool	operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs._c != rhs._c);
		};

		friend bool	operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs._c <= rhs._c);
		};

		friend bool	operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs._c >= rhs._c);
		};

		friend bool	operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs._c < rhs._c);
		};

		friend bool	operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
			return (lhs._c > rhs._c);
		};
};

#endif
