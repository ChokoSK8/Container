#ifndef MODIFIERS_MAP_HPP
# define MODIFIERS_MAP_HPP

ft::pair<iterator, bool>	insert(const value_type& val)
{
	nodePtr	newNode = new node<value_type>(val, _end);
	ft::pair<iterator, bool>	ret;
	bool	changeEndPapaCond = false;

	if (_root->is_nil() || _keyComp(_max->getKey(), val.first))
		changeEndPapaCond = true;
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
	if (changeEndPapaCond)
		changeEndPapa(newNode);
	return (ft::make_pair(iterator(newNode), true));
};

iterator	insert(iterator position, const value_type& val)
{
	iterator	next;

	if (position == _end)
	{
		if (_size)
		{
			--position;
			if ( _keyComp(position->first, val.first))
				return (insertFrom(position, val));
		}
		return (insert(val).first);
	}
	if (_keyComp(position->first, val.first))
	{
		if (position == end())
			return (insertFrom(--position, val));
		++position;
		if (_keyComp(val.first, position->first))
			return (insertFrom(--position, val));
		--position;
	}
	return (insert(val).first);
};

template < class InputIterator >
void	insert(InputIterator first, InputIterator last)
{
	while (first != last)
	{
		insert(*first);
		++first;
	}
};

void	erase(iterator position)
{
	erase(position->first);
};

size_type	erase(const key_type& k)
{
	iterator	toDeleteIt = find(k);
	nodePtr		toDelete;
	nodePtr		child;
	pair<nodePtr, nodePtr>	pairOfP;
	char	colorSub;
	bool	changeEndPapaCond = false;

	if (k == _max->getKey())
		changeEndPapaCond = true;
	if (toDeleteIt == end())
		return (0);
	toDelete = toDeleteIt.base();
	if (toDelete->hasAlmostOneChild())
	{
		pairOfP = toDelete->swipValueCase();
		if (_root == toDelete)
			_root = pairOfP.first;
		if (pairOfP.first->getKey() == _max->getKey())
			_end->setPapa(pairOfP.first);
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
	if (_size && changeEndPapaCond)
		changeEndPapaDelete();
	return (1);
};

void	erase(iterator first, iterator last)
{
	key_type	nextKey;

	while (_size && first != last)
	{
		++first;
		nextKey = first->first;
		--first;
		erase(first);
		first = find(nextKey);
	}
};

void	swap(map& x)
{
	size_type	sizeTmp = _size;
	allocator_type	cTmp = _c;
	nodePtr		rootTmp = _root;
	key_compare	keyCompTmp = _keyComp;
	nodePtr		maxTmp = _max;
	nodePtr		endTmp = _end;

	_size = x.size();
	_c = x.get_allocator();
	_root = x._root;
	_keyComp = x._keyComp;
	_max = x._max;
	_end = x._end;
	x._size = sizeTmp;
	x._c = cTmp;
	x._root = rootTmp;
	x._keyComp = keyCompTmp;
	x._max = maxTmp;
	x._end = endTmp;
};

void	clear(void)
{
	freeNodes(_root);
	_size = 0;
	_root = new node<value_type>;
};
#endif
