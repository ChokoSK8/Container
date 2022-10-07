#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP

iterator	begin(void)
{
	pointer	toFind = _root;

	if (toFind->is_nil())
		return (iterator(toFind));
	while (!toFind->getLeft()->is_nil())
		toFind = toFind->getLeft();
	return (iterator(toFind));
}

const_iterator	begin(void) const
{
	pointer	toFind = _root;

	if (toFind->is_nil())
		return (const_iterator(toFind));
	while (!toFind->getLeft()->is_nil())
		toFind = toFind->getLeft();
	return (const_iterator(toFind));
}

iterator	end(void)
{
	pointer	toFind = _root;

	if (toFind->is_nil())
		return (iterator(toFind));
	while (toFind->getRight())
		toFind = toFind->getRight();
	return (iterator(toFind));
}

const_iterator	end(void) const
{
	pointer	toFind = _root;

	if (toFind->is_nil())
		return (const_iterator(toFind));
	while (toFind->getRight())
		toFind = toFind->getRight();
	return (const_iterator(toFind));
}
#endif
