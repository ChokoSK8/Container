#ifndef RBRATOR_HPP
# define RBRATOR_HPP

template < class T >
class	ft::rbrator
{
	public:
		typedef T*	pointer;
		typedef T&	reference;
		typedef T	value_type;
		typedef node<T>*	node_type;

	protected:
		node_type	p;

	public:
		rbrator(void) : p(NULL) {};
		rbrator(node_type x) : p(x) {};
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
		node_type	base(void) const
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
		rbrator&	operator++(void)
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
		}

	private:
		bool	isEnd(void)
		{
			node_type	tmp = p;

			while (tmp->getSide() == 'r')
			{
				tmp = tmp->getPapa();
			}
			if (tmp->getSide() == 'c')
				return (true);
			return (false);
		}
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
