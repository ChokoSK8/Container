#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP

iterator	begin(void)
{
	pointer	toFind = _root;

	while (toFind->getLeft())
		toFind = toFind->getLeft();
	return (iterator(toFind));
}

const_iterator	begin(void) const
{
	pointer	toFind = _root;

	while (toFind->getLeft())
		toFind = toFind->getLeft();
	return (const_iterator(toFind));
}
#endif
