#ifndef MODIFIERS_MAP_HPP
# define MODIFIERS_MAP_HPP

ft::pair<iterator, bool>	insert(const value_type& val)
{
	pointer	newNode = new node<value_type>(val);
	ft::pair<iterator, bool>	ret;

	if (!_root->is_nil())
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
		delete _root;
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
	pointer		child;
	pair<pointer, pointer>	pairOfP;
	char	colorSub;

	if (toDeleteIt == end())
		return (0);
	toDelete = toDeleteIt.base();
	if (toDelete->hasAlmostOneChild())
	{
		pairOfP = toDelete->swipValueCase();
		if (_root == toDelete)
			_root = pairOfP.first;
		colorSub = pairOfP.second->getColor();
		child = pairOfP.second->deleteMe();
		if (colorSub == 'n')
		{
			if (child->getColor() == 'd')
				balanceTreeErase(child);
		}
		else
			disp("DELETED NODE WAS RED", 1);
		delete toDelete;
	}
	else if (_size > 1)
	{
		disp("DELETE LEAF", 1);
		child = toDelete->deleteLeaf();
		if (toDelete->getColor() == 'n')
			balanceTreeErase(child);
		delete toDelete;
	}
	else
	{
		delete toDelete;
		_root = new node<value_type>;
	}
	--_size;
	disp("SIZE", _size);
	return (1);
};
#endif
