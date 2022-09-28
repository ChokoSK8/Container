#ifndef RBRATOR_HPP
# define RBRATOR_HPP

template < class T >
class	ft::rbrator
{
	public:
		typedef ft::iterator_traits<T>			_traits;
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
		template < class U > rbrator(const ft::rbrator<U>& mit)
		{
			p = mit.base();
		};
		template < class U > rbrator&	operator=(const ft::rbrator<U>& mit)
		{
			p = mit.base();
			return (*this);
		}
		~rbrator() {};
		pointer	base(void) const
		{
			return (p);
		};
		reference	operator*(void) const
		{
			return (*p);
		};
		pointer		operator->(void) const
		{
			return (&(operator*()));
		};
		rbrator&	operator++(void)
		{
			if (p->getRight())
			{
				p = p->getRight();
				while (p->getLeft())
					p = p->getLeft();
			}
			else if (p->getPapa())
			{
				p = p->getPapa();
				while (p->getSide() != 'l')
					p = p->getPapa();
			}
			return (*this);
		}
};
#endif
