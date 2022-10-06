#ifndef OPERATIONS_MAP_HPP
# define OPERATIONS_MAP_HPP

iterator	find(const key_type& k)
{
	pointer	toFind = _root;

	while (toFind && !toFind->is_nil())
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

	while (toFind && !toFind->is_nil())
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

size_type	count(const key_type& k) const
{
	if (find(k) != end())
		return (1);
	return (0);
}

iterator	lower_bound(const key_type& k)
{
	pointer	lowerBnd = _root;
	pointer	favourite = NULL;

	while (!lowerBnd->is_nil())
	{
		if (k <= lowerBnd->getKey())
		{
			favourite = lowerBnd;
			lowerBnd = lowerBnd->getLeft();
		}
		else 
		{
			lowerBnd = lowerBnd->getRight();
		}
	}
	if (favourite)
		return (iterator(favourite));
	return (end());
}

const_iterator	lower_bound(const key_type& k) const
{
	pointer	lowerBnd = _root;
	pointer	favourite = NULL;

	while (!lowerBnd->is_nil())
	{
		if (k <= lowerBnd->getKey())
		{
			favourite = lowerBnd;
			lowerBnd = lowerBnd->getLeft();
		}
		else 
		{
			lowerBnd = lowerBnd->getRight();
		}
	}
	if (favourite)
		return (const_iterator(favourite));
	return (end());
}

iterator	upper_bound(const key_type& k)
{
	pointer	upperBnd = _root;
	pointer	favourite = NULL;

	while (!upperBnd->is_nil())
	{
		if (k < upperBnd->getKey())
		{
			favourite = upperBnd;
			upperBnd = upperBnd->getLeft();
		}
		else 
		{
			upperBnd = upperBnd->getRight();
		}
	}
	if (favourite)
		return (iterator(favourite));
	return (end());
}

const_iterator	upper_bound(const key_type& k) const
{
	pointer	upperBnd = _root;
	pointer	favourite = NULL;

	while (!upperBnd->is_nil())
	{
		if (k < upperBnd->getKey())
		{
			favourite = upperBnd;
			upperBnd = upperBnd->getLeft();
		}
		else 
		{
			upperBnd = upperBnd->getRight();
		}
	}
	if (favourite)
		return (const_iterator(favourite));
	return (end());
}

pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
{
	return (make_pair(lower_bound(k), upper_bound(k)));
};
#endif
