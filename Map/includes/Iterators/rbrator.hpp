#ifndef RBRATOR_HPP
# define RBRATOR_HPP
# include "const_rbrator.hpp"

template < class T >
class	ft::rbrator
{
	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef std::ptrdiff_t	difference_type;
		typedef T*	pointer;
		typedef T&	reference;
		typedef T	value_type;
		typedef node<T>*	nodePtr;

	protected:
		nodePtr	p;

	public:
		rbrator(void) : p(NULL) {};
		rbrator(nodePtr x) : p(x) {};
		template < class U > rbrator(const ft::rbrator<U>& mit)
		{
			p = mit.base();
		};
		rbrator&	operator=(const rbrator& mit)
		{
			p = mit.base();
			return (*this);
		}
		~rbrator() {};
		nodePtr	base(void) const
		{
			return (p);
		};
		bool	operator==(const ft::rbrator<T>& rhs) const
		{
			return (p == rhs.base());
		};
		bool	operator!=(const ft::rbrator<T>& rhs) const
		{
			return (p != rhs.base());
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
				p = p->getEnd();
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
			if (p->is_nil() || p == p->getEnd())
				p = p->getPapa();
			else if (p->getLeft() && !p->getLeft()->is_nil())
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
		rbrator	operator++(int)
		{
			rbrator	tmp(*this);

			++(*this);
			return (tmp);
		};
		rbrator	operator--(int)
		{
			rbrator	tmp(*this);

			--(*this);
			return (tmp);
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
	// RELATIONAL_OPERATORS

template < class T >
bool	operator==(const ft::rbrator<T>& lhs, const ft::rbrator<T>& rhs)
{
	return (lhs.base() == rhs.base());
}

template < class T >
bool	operator!=(const ft::rbrator<T>& lhs, const ft::rbrator<T>& rhs)
{
	return (lhs.base() != rhs.base());
}

template < class T >
bool	operator<=(const ft::rbrator<T>& lhs, const ft::rbrator<T>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template < class T >
bool	operator<(const ft::rbrator<T>& lhs, const ft::rbrator<T>& rhs)
{
	return (lhs.base() < rhs.base());
}

template < class T >
bool	operator>=(const ft::rbrator<T>& lhs, const ft::rbrator<T>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template < class T >
bool	operator>(const ft::rbrator<T>& lhs, const ft::rbrator<T>& rhs)
{
	return (lhs.base() > rhs.base());
}

	// RIGHT LEFT

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
