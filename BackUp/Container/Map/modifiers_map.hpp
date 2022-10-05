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

size_type	erase(const key_type& k)
{
	iterator	toDeleteIt = find(k);
	pointer		toDelete;	
	pointer		substitute;
	pointer		child;

	if (toDeleteIt == end())
		return (0);
	toDelete = toDeleteIt.base();
	if (toDelete->hasAlmostOneChild())
	{
		substitute = toDelete->swipValueCase();
		child = substitute->deleteMe();
		if (substitute->getColor() == 'n')
		{
			delete substitute;
			if (child->getColor() == 'd')
				balanceTreeErase(child);
		}
		else
			disp("DELETED NODE WAS RED", 1);
	}
	return (1);
};
#endif
