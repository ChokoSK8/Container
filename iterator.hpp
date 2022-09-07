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
		~iterator() {};
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
			disp("HEY", 2);
			p++;
			return (*this);
		};
		ft::iterator<Category>	operator++(value_type) {
			disp("HEY", 3);
			ft::iterator<Category>	tmp(*this);
			p++;
			return (tmp);
		};
		value_type	operator*(void) {
			return (*p);
		};

		//	SUP
		pointer	operator+(int n) {
			pointer	tmp = p;
			disp("P", *p);
			while (n--)
				tmp++;
			disp("TMP", *tmp);
			return (tmp);
		};
		ft::iterator<Category>	operator-(int n) {
			p -= n;
			return (*this);
		};
		int	operator+(ft::iterator<Category> rhs) {
			int res = p + rhs.get_pointer();
			return (res);
		};
		int	operator-(ft::iterator<Category> rhs) {
			int res = p - rhs.get_pointer();
			return (res);
		};
		const pointer	get_pointer(void) const {
			return (p);
		};
};
#endif
