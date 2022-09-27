#ifndef RBRATOR_HPP
# define RBRATOR_HPP

template < class I >
class	ft::rbrator
{
	public:
		typedef ft::iterator_traits<I>			_traits;
		typedef typename _traits::iterator_category	iterator_category;
		typedef typename _traits::value_type		value_type;
		typedef typename _traits::difference_type	difference_type;
		typedef typename _traits::pointer		pointer;
		typedef typename _traits::reference		reference;

	protected:
		pointer	p;

	public:
		rbrator(void) : p(NULL) {};
		rbrator(pointer x) : p(x) {};
		template < class U > rbrator(const ft::rbrator<U>& mit) {
			p = mit.base();
		};
		template < class U > rbrator&	operator=(const ft::rbrator<U>& mit) {
			p = mit.base();
			return (*this);
		}
		~rbrator() {};
		pointer	base(void) const {
			return (p);
		};
}
#endif
