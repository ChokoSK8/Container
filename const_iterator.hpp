#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP
# include "containers.h"

template < class Category >
class ft::const_iterator
{
	public:
		typedef typename Category::value_type	value_type;
		typedef std::ptrdiff_t			difference_type;
		typedef value_type*			pointer;
		typedef value_type&			reference;
		typedef Category			const_iterator_category;

	protected:
		pointer	p;

	public:
		const_iterator(const pointer x) : p(x) {};
		const_iterator(const ft::const_iterator<Category>& mit) : p(mit.p) {};
		~const_iterator() {};
		bool	operator==(const ft::const_iterator<Category>& rhs) const {
			return (p == rhs.p);
		};
		bool	operator!=(const ft::const_iterator<Category>& rhs) const {
			return (p != rhs.p);
		};
		const pointer	operator&(void) const {
			return (p);
		};
		ft::const_iterator<Category>	operator++(void) {
			p++;
			return (*this);
		};
		ft::const_iterator<Category>	operator++(value_type) {
			ft::const_iterator<Category>	tmp(*this);
			p++;
			return (tmp);
		};
		value_type	operator*(void) const {
			return (*p);
		};

		//	SUP
		ft::const_iterator<Category>	operator+(int n) const {
			pointer	tmp = p;
			while (n--)
				tmp++;
			return (tmp);
		};
		ft::const_iterator<Category>	operator-(int n) const {
			pointer	tmp = p;
			while (n--)
				tmp--;
			return (tmp);
		};
		int	operator+(ft::const_iterator<Category> rhs) const {
			int res = p + rhs.get_pointer();
			return (res);
		};
		int	operator-(ft::const_iterator<Category> rhs) const {
			int res = p - rhs.get_pointer();
			return (res);
		};
		const pointer	get_pointer(void) const {
			return (p);
		};
};
#endif
