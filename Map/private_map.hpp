#ifndef PRIVATE_MAP_HPP
# define PRIVATE_MAP_HPP

ft::pair<iterator, bool>	positionNode(pointer newNode, pointer from)
{
	bool	loop = true;

	while (loop)
	{
		if (newNode->getKey() < from->getKey())
		{
			if (from->getLeft()->is_nil())
			{
				from->setNewNodeLeft(newNode, 'l');
				return (make_pair(iterator(newNode), true));
			}
			from = from->getLeft();
		}
		else if (newNode->getKey() > from->getKey())
		{
			if (from->getRight()->is_nil())
			{
				from->setNewNodeRight(newNode, 'r');
				return (make_pair(iterator(newNode), true));
			}
			from = from->getRight();
		}
		else
			loop = false;
	}
	return (make_pair(iterator(from), false));
};

void	balanceTree(pointer _node_)
{
	while (_node_->execBalancing())
		_node_ = _node_->getGrandPa();

	pointer	papa = _node_->getPapa();

	if (papa && papa->is_root())
		_root = papa;
	if (_node_->is_root())
		_root = _node_;
};

void	balanceTreeErase(pointer curr)
{
	print();
	disp("CURR", 1);
	disp("COLOR", curr->getColor());
	disp("PAPA", curr->getPapa());
	while (curr->execBalancingDelete())
		curr = curr->getPapa();
};

// FREE
void	freeNodes(pointer from)
{
	if (from->getLeft() && !from->getLeft()->is_nil())
		freeNodes(from->getLeft());
	if (from->getRight() && !from->getRight()->is_nil())
		freeNodes(from->getRight());
	delete from;
};

// PRINT
void	print_tree_side(void)
{
	iterator	it = begin();
	iterator	ite = end();

	int i = 5;
	while (it != ite && --i > 0)
	{
		disp("KEY", it->getKey());
		disp("SIDE", it->getSide());
		disp("RIGHT", it->getRight());
		disp("LEFT", it->getLeft());
		++it;
	}
	disp("END PRINT TREE", 1);
};
#endif
