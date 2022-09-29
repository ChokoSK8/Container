#ifndef OPERATIONS_MAP_HPP
# define OPERATIONS_MAP_HPP

iterator	find(const key_type& k)
{
	pointer	toFind = _root;

	while (toFind)
	{
		if (k < toFind->getKey())
			toFind = toFind->getLeft();
		else if (k > toFind->getKey())
			toFind = toFind->getRight();
		else
			return (iterator(toFind));
	}
	return (end());
}

const_iterator	find(const key_type& k) const
{
	pointer	toFind = _root;

	while (toFind)
	{
		if (k < toFind->getKey())
			toFind = toFind->getLeft();
		else if (k > toFind->getKey())
			toFind = toFind->getRight();
		else
			return (iterator(toFind));
	}
	return (end());
}
#endif
