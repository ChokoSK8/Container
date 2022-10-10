#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP

iterator	begin(void)
{
	nodePtr	toFind = _root;

	if (toFind->is_nil())
		return (iterator(toFind));
	while (!toFind->getLeft()->is_nil())
		toFind = toFind->getLeft();
	return (iterator(toFind));
}

const_iterator	begin(void) const
{
	nodePtr	toFind = _root;

	if (toFind->is_nil())
		return (const_iterator(toFind));
	while (!toFind->getLeft()->is_nil())
		toFind = toFind->getLeft();
	return (const_iterator(toFind));
}

iterator	end(void)
{
	nodePtr	toFind = _root;

	if (toFind->is_nil())
		return (iterator(toFind));
	while (toFind->getRight())
		toFind = toFind->getRight();
	return (iterator(toFind));
}

const_iterator	end(void) const
{
	nodePtr	toFind = _root;

	if (toFind->is_nil())
		return (const_iterator(toFind));
	while (toFind->getRight())
		toFind = toFind->getRight();
	return (const_iterator(toFind));
}

reverse_iterator	rbegin(void)
{
	return (reverse_iterator(end()));
};

const_reverse_iterator	rbegin(void) const
{
	return (const_reverse_iterator(end()));
};

reverse_iterator	rend(void)
{
	return (reverse_iterator(begin()));
};

const_reverse_iterator	rend(void) const
{
	return (const_reverse_iterator(begin()));
};
#endif
