#ifndef RBRATOR_HPP
# define RBRATOR_HPP

template < class T >
class	ft::rbrator
{
	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef std::ptrdiff_t	difference_type;
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
		};
		rbrator&	operator--(void)
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
		ft::rbrator<T>	operator+(difference_type n) const {
			ft::rbrator<T>	tmp(*this);

			while (n--)
				++tmp;
			return (tmp);
		};
		ft::rbrator<T>	operator-(difference_type n) const {
			ft::rbrator<T>	tmp(*this);

			while (n--)
				--tmp;
			return (tmp);
		};
		
	private:
		bool	isBeg(void)
		{
			node_type	tmp = p;

			while (tmp->getSide() == 'l')
			{
				tmp = tmp->getPapa();
			}
			if (tmp->getSide() == 'c')
				return (true);
			return (false);
		}
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
