#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include "containers.h"

template < class Category, class T, class Distance, class Pointer,
		class Reference >
class ft::iterator
{
	public:
		typedef T		value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;

	protected:
		T*	p;

	public:
		iterator(T* x) : p(x) {};
		iterator(const ft::iterator<Category, T, Distance, Pointer, Reference>& mit) : p(mit.p) {};
		~iterator() {delete p;};
		bool	operator==(const ft::iterator<Category, T, Distance, Pointer, Reference>& rhs) {
			return (p == rhs.p);
		};
		bool	operator!=(const ft::iterator<Category, T, Distance, Pointer, Reference>& rhs) {
			return (p != rhs.p);
		};
		T	operator&(void) {
			return (&p);
		};
		ft::iterator<Category, T, Distance, Pointer, Reference>	operator++(void) {
			p++;
			return (*this);
		};
		ft::iterator<Category, T, Distance, Pointer, Reference>	operator++(const ft::iterator<Category, T, Distance, Pointer, Reference>& lhs) {
			ft::iterator<Category, T, Distance, Pointer, Reference>	tmp(lhs);
			lhs.p++;
			return (tmp);
		};
	//	T	operator++(void) {
	//		return (*p);
	//	};
	//	ft::iterator<Category, T, Distance, Pointer, Reference>	operator=(const ft::iterator<Category, T, Distance, Pointer, Reference>& lhs) {
	//		return (p);
	//	};
};
#endif
