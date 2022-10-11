#ifndef RBRATOR_HPP
# define RBRATOR_HPP

template < class T >
class	ft::const_rbrator
{
	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef std::ptrdiff_t	difference_type;
		typedef T*	pointer;
		typedef T&	reference;
		typedef T	value_type;
		typedef const node<T>*	nodePtr;

	protected:
		nodePtr	p;

	public:
		const_rbrator(void) : p(NULL) {};
		const_rbrator(nodePtr x) : p(x) {};
		template < class U > const_rbrator(const ft::const_rbrator<U>& mit)
		{
			p = mit.base();
		};
		template < class U > const_rbrator&	operator=(const ft::const_rbrator<U>& mit)
		{
			p = mit.base();
			return (*this);
		}
		~const_rbrator() {};
		nodePtr	base(void) const
		{
			return (p);
		};
		reference	operator*(void) const
		{
			return (p->getVal());
		};
		pointer	operator->(void) const
		{
			return (&(operator*()));
		};
		const_rbrator&	operator++(void)
		{
			if (!p->getRight()->is_nil())
			{
				p = p->getRight();
				while (!p->getLeft()->is_nil())
					p = p->getLeft();
			}
			else if (isEnd())
			{
				p = p->getRight();
			}
			else if (p->getPapa())
			{
				while (p->getSide() != 'l')
					p = p->getPapa();
				p = p->getPapa();
			}
			return (*this);
		};
		const_rbrator&	operator--(void)
		{
			if (p->getLeft() && !p->getLeft()->is_nil())
			{
				p = p->getLeft();
				while (!p->getRight()->is_nil())
					p = p->getRight();
			}
			else if (isBeg())
			{
				p = p->getLeft();
			}
			else if (p->getPapa())
			{
				while (p->getSide() != 'r')
					p = p->getPapa();
				p = p->getPapa();
			}
			return (*this);
		};
		difference_type	operator-(const ft::rbrator<T>& rhs) const
		{
			difference_type	res = p - rhs.base();
			return (res);
		};
		
	private:
		bool	isBeg(void)
		{
			nodePtr	tmp = p;

			while (tmp->getSide() == 'l')
			{
				tmp = tmp->getPapa();
			}
			if (tmp->getSide() == 'c')
				return (true);
			return (false);
		};
		bool	isEnd(void)
		{
			nodePtr	tmp = p;

			while (tmp->getSide() == 'r')
			{
				tmp = tmp->getPapa();
			}
			if (tmp->getSide() == 'c')
				return (true);
			return (false);
		};
};

template < class R, class L >
bool	operator==(const ft::rbrator<L>& lhs, const ft::rbrator<R>& rhs)
{
	return (lhs.base() == rhs.base());
}
template < class R, class L >
bool	operator!=(const ft::rbrator<L>& lhs, const ft::rbrator<R>& rhs)
{
	return (lhs.base() != rhs.base());
}
template < class R, class L >
bool	operator<=(const ft::rbrator<L>& lhs, const ft::rbrator<R>& rhs)
{
	return (lhs.base() <= rhs.base());
}
template < class R, class L >
bool	operator<(const ft::rbrator<L>& lhs, const ft::rbrator<R>& rhs)
{
	return (lhs.base() < rhs.base());
}
template < class R, class L >
bool	operator>=(const ft::rbrator<L>& lhs, const ft::rbrator<R>& rhs)
{
	return (lhs.base() >= rhs.base());
}
template < class R, class L >
bool	operator>(const ft::rbrator<L>& lhs, const ft::rbrator<R>& rhs)
{
	return (lhs.base() > rhs.base());
}
#endif
