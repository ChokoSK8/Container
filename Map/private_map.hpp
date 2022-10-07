#ifndef PRIVATE_MAP_HPP
# define PRIVATE_MAP_HPP

ft::pair<iterator, bool>	positionNode(nodePtr newNode, nodePtr from)
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

void	balanceTree(nodePtr _node_)
{
	disp("ROOT", _root->getKey());
	while (_node_->execBalancing())
		_node_ = _node_->getGrandPa();

	nodePtr	papa = _node_->getPapa();

	if (papa && papa->is_root())
		_root = papa;
	if (_node_->is_root())
		_root = _node_;
	disp("NEWROOT", _root->getKey());
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

// FREE
void	freeNodes(nodePtr from)
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

// COUNTER
public:
	nodePtr	getRoot(void)
	{
		return (_root);
	};

	void	countHeight(nodePtr from, int height)
	{
		if (from == NULL)
			from = getRoot();
		if (!from->is_nil() && from->getColor() == 'n')
			++height;
		if (from->getColor() == 'd')
			disp("COLOR IS D", from->getKey());
		if (from->getLeft())
			countHeight(from->getLeft(), height);
		if (from->getRight())
			countHeight(from->getRight(), height);
		if (from->is_nil())
			disp("HEIGHT", height);
	};
	void	countElements(void)
	{
		iterator	it = begin();
		iterator	ite = end();
		int	i = 0;

		while (it != ite)
		{
			++it;
			++i;
		}
		disp("NUMBER OF ELEMENTS", i);
	};
#endif
