#ifndef MODIFIERS_MAP_HPP
# define MODIFIERS_MAP_HPP

ft::pair<iterator, bool>	insert(const value_type& val)
{
	nodePtr	newNode = new node<value_type>(val);
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
	iterator	next;

	if (_keyComp(position->first, val.first))
	{
		if (position == end())
			return (insertFrom(position, val));
		++position;
		if (_keyComp(val.first, position->first))
			return (insertFrom(--position, val));
		--position;
	}
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
	nodePtr		toDelete;
	nodePtr		child;
	pair<nodePtr, nodePtr>	pairOfP;
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
		delete toDelete;
	}
	else if (_size > 1)
	{
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
	return (1);
};
#endif
