#ifndef ITERATOR_HPP
# define ITERATOR_HPP

template < class T >
class ft::iterator
{
	public:
		typedef T			value_type;
		typedef std::ptrdiff_t		difference_type;
		typedef T*			pointer;
		typedef T&			reference;
		typedef T			iterator_category;

	protected:
		pointer	p;

	public:
		iterator(void) : p(NULL) {};
		iterator(pointer x) : p(x) {};
		iterator(const ft::iterator<T>& mit) : p(mit.p) {};
		~iterator() {};
		pointer	base(void) const {
			return (p);
		};
		bool	operator==(const ft::iterator<T>& rhs) {
			return (p == rhs.p);
		};
		bool	operator!=(const ft::iterator<T>& rhs) {
			return (p != rhs.p);
		};
		ft::iterator<T>	operator++(void) {
			p++;
			return (*this);
		};
		ft::iterator<T>	operator++(int) {
			ft::iterator<T>	tmp(*this);
			p++;
			return (tmp);
		};
		ft::iterator<T>	operator--(void) {
			p--;
			return (*this);
		};
		ft::iterator<T>	operator--(int) {
			ft::iterator<T>	tmp(*this);
			p--;
			return (tmp);
		};
		value_type	operator*(void) {
			return (*p);
		};

		//	SUP
		ft::iterator<T>	operator+(int n) {
			pointer	tmp = p;
			while (n--)
				tmp++;
			return (tmp);
		};
		ft::iterator<T>	operator-(int n) {
			pointer	tmp = p;
			while (n--)
				tmp--;
			return (tmp);
		};
		int	operator+(ft::iterator<T> rhs) {
			int res = p + rhs.get_pointer();
			return (res);
		};
		int	operator-(ft::iterator<T> rhs) {
			int res = p - rhs.get_pointer();
			return (res);
		};
		const pointer	get_pointer(void) const {
			return (p);
		};
};
#endif
