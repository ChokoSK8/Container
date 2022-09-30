#ifndef MODIFIERS_MAP_HPP
# define MODIFIERS_MAP_HPP

ft::pair<iterator, bool>	insert(const value_type& val)
{
	pointer	newNode = new node<value_type>(val);
	ft::pair<iterator, bool>	ret;

	if (_root)
	{
		ret = positionNode(newNode, _root);
		if (!ret.second)
		{
			delete newNode;
			return (ret);
		}
	}
	else
	{
		_root = newNode;
	}
	balanceTree(newNode);
	++_size;
	return (make_pair(iterator(newNode), true));
};

iterator	insert(iterator position, const value_type& val)
{
	(void)position;
	return (insert(val).first);
};

//template < class InputIterator >
void	insert(iterator first, iterator last)
{
	while (first != last)
	{
		insert(first->getVal());
		++first;
	}
};
#endif
