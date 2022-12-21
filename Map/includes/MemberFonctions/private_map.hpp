#ifndef PRIVATE_MAP_HPP
# define PRIVATE_MAP_HPP

ft::pair<iterator, bool>	positionNode(nodePtr newNode, nodePtr from)
{
	bool	loop = true;

	while (loop)
	{
		if (_keyComp(newNode->getKey(), from->getKey()))
		{
			if (from->getLeft()->is_nil())
			{
				from->setNewNodeLeft(newNode, 'l');
				return (ft::make_pair(iterator(newNode), true));
			}
			from = from->getLeft();
		}
		else if (_keyComp(from->getKey(), newNode->getKey()))
		{
			if (from->getRight()->is_nil())
			{
				from->setNewNodeRight(newNode, 'r');
				return (ft::make_pair(iterator(newNode), true));
			}
			from = from->getRight();
		}
		else
			loop = false;
	}
	return (ft::make_pair(iterator(from), false));
};

iterator	insertFrom(iterator from, const value_type& val)
{
	nodePtr	newNode = new node<value_type>(val, _end);
	ft::pair<iterator, bool>	ret;
	bool	changeEndPapaCond = false;

	if (_root->is_nil() || _keyComp(_max->getKey(), val.first))
		changeEndPapaCond = true;
	if (!_root->is_nil())
	{
		ret = positionNode(newNode, from.base());
		if (!ret.second)
		{
			delete newNode;
			return (ret.first);
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
	return (iterator(newNode));
};

void	balanceTree(nodePtr _node_)
{
	while (_node_->execBalancing())
		_node_ = _node_->getGrandPa();

	nodePtr	papa = _node_->getPapa();

	if (papa && papa->is_root())
		_root = papa;
	if (_node_->is_root())
		_root = _node_;
};

void	balanceTreeErase(nodePtr curr)
{
	int	ret;
	nodePtr	papa;
	nodePtr	grandPa;

	while ((ret = curr->execBalancingDelete()))
	{
		papa = curr->getPapa();
		grandPa = curr->getGrandPa();
		if (grandPa && grandPa->is_root())
			_root = grandPa;
		if (papa && papa->is_root())
			_root = papa;
		if (ret != 2)
			curr = papa;
	}
	papa = curr->getPapa();
	grandPa = curr->getGrandPa();
	if (grandPa && grandPa->is_root())
		_root = grandPa;
	if (papa && papa->is_root())
		_root = papa;
};

void	changeEndPapa(nodePtr newNode)
{
	_max = newNode;
	_end->setPapa(newNode);
};

void	changeEndPapaDelete(void)
{
	nodePtr	newMaxNode = _root;

	while (!newMaxNode->getRight()->is_nil())
		newMaxNode = newMaxNode->getRight();
	_end->setPapa(newMaxNode);
	_max = newMaxNode;
};

// FREE
void	freeNodes(nodePtr from)
{
	if (from->getLeft() && !from->getLeft()->is_nil())
		freeNodes(from->getLeft());
	if (from->getRight() && !from->getRight()->is_nil())
		freeNodes(from->getRight());
	delete from;
};
#endif
