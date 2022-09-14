#ifndef ITERATOR_VEC_HPP
# define ITERATOR_VEC_HPP

iterator	begin(void) {
	return (iterator(_first));
};

const_iterator	begin(void) const {
	return (const_iterator(_first));
};

iterator	end(void) {
	return (iterator(_first + _size));
};

const_iterator	end(void) const {
	return (const_iterator(_first + _size));
};
#endif
