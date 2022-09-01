#ifndef STACK_HPP
# define STACK_HPP
# include "container.h"

template<typename T, typename Container>
class	ft::stack : public Container
{
	protected:
		Container	_c;

	public:
		stack(void) {};
		~stack(void) {};
		stack&	operator=(const stack& other) {
			_c = other.c;
		};

	// ELEMENT ACCESS
		T	top() {
			return (_c.at(_c.size() - 1));
		};

	// CAPACITY
		bool	empty(void) const {
			return (_c.size() == 0);
		};
		size_t	size() {
			return (_c.size());
		};
	
	// MODIFIERS
		void	push(const T& value) {
			_c.push_back(value);
		};
		void	pop(void) {
			_c.pop_back();
		};
};

template<class T, class Container>
bool	operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs){
	return (lhs._c == rhs._c);
};

#endif
