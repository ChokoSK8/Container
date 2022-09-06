#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include "containers.h"

template < class Category >
class ft::iterator
{
	public:
		typedef typename Category::value_type	value_type;
		typedef std::ptrdiff_t			difference_type;
		typedef value_type*			pointer;
		typedef value_type&			reference;
		typedef Category			iterator_category;

	protected:
		pointer	p;

	public:
		iterator(pointer x) : p(x) {};
		iterator(const ft::iterator<Category>& mit) : p(mit.p) {};
		~iterator() {delete p;};
		bool	operator==(const ft::iterator<Category>& rhs) {
			return (p == rhs.p);
		};
		bool	operator!=(const ft::iterator<Category>& rhs) {
			return (p != rhs.p);
		};
		reference	operator&(void) {
			return (&p);
		};
		ft::iterator<Category>	operator++(void) {
			p++;
			return (*this);
		};
		ft::iterator<Category>	operator++(const ft::iterator<Category>& lhs) {
			ft::iterator<Category>	tmp(lhs);
			lhs.p++;
			return (tmp);
		};
};
#endif
