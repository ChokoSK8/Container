#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

class ft::bidirectional_iterator : public ft::input_iterator
{
	public:
		ft::bidirectional_iterator<T>	operator--(void) {
			--p;
			return (*this);
		};
		ft::bidirectional_iterator<T>	operator--(int) {
			ft::bidirectional_iterator<T>	tmp(*this);
			--p;
			return (tmp);
		};
};
#endif
