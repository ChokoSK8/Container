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
	int	ret;
	pointer	papa = curr->getPapa();
	pointer	grandPa = curr->getGrandPa();

	disp("CURR", curr->getKey());
	disp("IS NIL", curr->is_nil());
	disp("PRINT IN PRIVATE", 2);
	print();
	while ((ret = curr->execBalancingDelete()))
	{
		papa = curr->getPapa();
		grandPa = curr->getGrandPa();
		if (grandPa)
			disp("GRAND PA", grandPa->getKey());
		if (papa)
			disp("PAPA", papa->getKey());
		if (grandPa && grandPa->is_root())
			_root = grandPa;
		if (papa && papa->is_root())
			_root = papa;
		disp("PRINT IN PRIVATE", 1);
		print();
		if (ret != 2)
			curr = papa;
		disp("CURR", curr->getKey());
	}
	papa = curr->getPapa();
	grandPa = curr->getGrandPa();
	if (grandPa)
		disp("GRAND PA", grandPa->getKey());
	if (papa)
		disp("PAPA", papa->getKey());
	if (grandPa && grandPa->is_root())
		_root = grandPa;
	if (papa && papa->is_root())
		_root = papa;
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

// COUNTER
public:
	pointer	getRoot(void)
	{
		return (_root);
	};

	void	countHeight(pointer from, int height)
	{
		if (from == NULL)
			from = getRoot();
		if (!from->is_nil() && from->getColor() == 'n')
			++height;
		if (from->getColor() == 'd')
			disp("COLOR IS D", from->getKey());
		if (from->getPapa() && from->getPapa()->getColor() == 'r' && from->getColor() == 'r')
			disp("-------DOUBLE RED------", 1);
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
