#ifndef CONST_RBRATOR_HPP
# define CONST_RBRATOR_HPP
# include "rbrator.hpp"

template < class T, class Node >
class	ft::const_rbrator
{
	public:
		typedef std::random_access_iterator_tag	iterator_category;
		typedef std::ptrdiff_t	difference_type;
		typedef const T*	pointer;
		typedef const T&	reference;
		typedef const T		value_type;
		typedef Node*	nodePtr;

	protected:
		nodePtr	p;

	public:
		const_rbrator(void) : p(NULL) {};
		const_rbrator(const nodePtr x) : p(x) {};
		template < class U > const_rbrator(const ft::const_rbrator<U, Node>& mit)
		{
			p = mit.base();
		};
		template < class U > const_rbrator&	operator=(const ft::const_rbrator<U, Node>& mit)
		{
			p = mit.base();
			return (*this);
		}
		~const_rbrator() {};
		nodePtr	base(void) const
		{
			return (p);
		};
		bool	operator==(const ft::const_rbrator<T, Node>& rhs) const
		{
			return (p == rhs.base());
		};
		bool	operator!=(const ft::const_rbrator<T, Node>& rhs) const
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
		const_rbrator&	operator--(void)
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
		const_rbrator	operator++(int)
		{
			const_rbrator	tmp(*this);

			++(*this);
			return (tmp);
		};
		const_rbrator	operator--(int)
		{
			const_rbrator	tmp(*this);

			--(*this);
			return (tmp);
		};
		difference_type	operator-(const ft::const_rbrator<T, Node>& rhs) const
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

template < class T, class Node >
bool	operator==(const ft::const_rbrator<T, Node>& lhs, const ft::const_rbrator<T, Node>& rhs)
{
	return (lhs.base() == rhs.base());
}

template < class T, class Node >
bool	operator!=(const ft::const_rbrator<T, Node>& lhs, const ft::const_rbrator<T, Node>& rhs)
{
	return (lhs.base() != rhs.base());
}

template < class T, class Node >
bool	operator<=(const ft::const_rbrator<T, Node>& lhs, const ft::const_rbrator<T, Node>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template < class T, class Node >
bool	operator<(const ft::const_rbrator<T, Node>& lhs, const ft::const_rbrator<T, Node>& rhs)
{
	return (lhs.base() < rhs.base());
}

template < class T, class Node >
bool	operator>=(const ft::const_rbrator<T, Node>& lhs, const ft::const_rbrator<T, Node>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template < class T, class Node >
bool	operator>(const ft::const_rbrator<T, Node>& lhs, const ft::const_rbrator<T, Node>& rhs)
{
	return (lhs.base() > rhs.base());
}

	// RIGHT LEFT

template < class R, class L, class Node >
bool	operator==(const ft::const_rbrator<L, Node>& lhs, const ft::const_rbrator<R, Node>& rhs)
{
	return (lhs.base() == rhs.base());
}

template < class R, class L, class Node >
bool	operator!=(const ft::const_rbrator<L, Node>& lhs, const ft::const_rbrator<R, Node>& rhs)
{
	return (lhs.base() != rhs.base());
}

template < class R, class L, class Node >
bool	operator<=(const ft::const_rbrator<L, Node>& lhs, const ft::const_rbrator<R, Node>& rhs)
{
	return (lhs.base() <= rhs.base());
}

template < class R, class L, class Node >
bool	operator<(const ft::const_rbrator<L, Node>& lhs, const ft::const_rbrator<R, Node>& rhs)
{
	return (lhs.base() < rhs.base());
}

template < class R, class L, class Node >
bool	operator>=(const ft::const_rbrator<L, Node>& lhs, const ft::const_rbrator<R, Node>& rhs)
{
	return (lhs.base() >= rhs.base());
}

template < class R, class L, class Node >
bool	operator>(const ft::const_rbrator<L, Node>& lhs, const ft::const_rbrator<R, Node>& rhs)
{
	return (lhs.base() > rhs.base());
}
#endif
