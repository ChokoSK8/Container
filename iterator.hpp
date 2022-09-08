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
		pointer	operator&(void) {
			return (p);
		};
		ft::iterator<Category>	operator++(void) {
			p++;
			return (*this);
		};
		ft::iterator<Category>	operator++(value_type) {
			ft::iterator<Category>	tmp(*this);
			p++;
			return (tmp);
		};
		value_type	operator*(void) {
			return (*p);
		};

		//	SUP
		ft::iterator<Category>	operator+(int n) {
			pointer	tmp = p;
			while (n--)
				tmp++;
			return (tmp);
		};
		ft::iterator<Category>	operator-(int n) {
			pointer	tmp = p;
			while (n--)
				tmp--;
			return (tmp);
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
