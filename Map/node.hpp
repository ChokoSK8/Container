#ifndef NODE_HPP
# define NODE_HPP
# include "../containers.h"

template < class T >
class	ft::node
{
	public:
		typedef T				value_type;
		typedef typename T::key_type		key_type;
		typedef typename T::content_type	content_type;

	protected:
		value_type	_val;
		key_type	_key;
		content_type	_content;
		node*		_left;
		node*		_right;
		node*		_papa;
		char		_color;
		char		_side;

	public:
		node(void) : _key(0), _content(0), _left(NULL), _right(NULL), _papa(NULL),
				_color('s'), _side('s') {};
		node(const value_type& val) : _val(val), _key(val.first)
		{
			_content = val.second;
			_left = new node;
			_right = new node;
			_papa = NULL;
			_color = 'r';
			_side = 'c';
		};
		template < class U > node(const node<U>& mit) : _val(mit.getVal()), _key(mit.getKey())
		{
			_content = mit.getVal().second;
			_left = mit.getLeft();
			_right = mit.getRight();
			_papa = mit.getPapa();
			_color = mit.getColor();
			_side = mit.getSide();
		};
		~node(void)
		{
			if (_papa)
			{
				if (_side == 'r')
					_papa->setRight(NULL);
				if (_side == 'l')
					_papa->setLeft(NULL);
			}
			if (_right && _right->is_nil())
				delete _right;
			if (_left && _left->is_nil())
				delete _left;
		}

		// FCTS
		bool	is_nil(void)
		{
			return (_left == NULL && _right == NULL);
		};
		bool	is_root(void)
		{
			return (!_papa);
		};
		void	setKey(const key_type& key)
		{
			_key = key;
		}
		void	setContent(const content_type& content)
		{
			_content = content;
		}
		void	setColor(const char& c)
		{
			_color = c;
		};
		void	setRight(node* _node_)
		{
			_right = _node_;
		};
		void	setLeft(node* _node_)
		{
			_left = _node_;
		};
		void	setPapa(node* _node_)
		{
			_papa = _node_;
		};
		void	setSide(const char& side)
		{
			_side = side;
		}
		int	setRootColor(void)
		{
			_color = 'n';
			return (0);
		};
	//	void	setNewNode(node* newNode, char side, void (*setter)(node*))
	//	{
	//		newNode->setSide(side);
	//		setter(newNode);
	//		newNode->setPapa(this);
	//	};
		void	setNewNodeRight(node* newNode, char side)
		{
			newNode->setSide(side);
			delete _right;
			setRight(newNode);
			newNode->setPapa(this);
		};
		void	setNewNodeLeft(node* newNode, char side)
		{
			newNode->setSide(side);
			delete _left;
			setLeft(newNode);
			newNode->setPapa(this);
		};
		value_type	getVal(void) const
		{
			return (_val);
		};
		node*	getRight(void) const
		{
			return (_right);
		};
		node*	getLeft(void) const
		{
			return (_left);
		};
		node*	getPapa(void) const
		{
			return (_papa);
		};
		node*	getGrandPa(void) const
		{
			return (_papa->getPapa());
		};
		char	getSide(void) const
		{
			return (_side);
		};
		char	getColor(void) const
		{
			return (_color);
		};
		content_type&	getContent(void)
		{
			return (_content);
		};
		key_type	getKey(void) const
		{
			return (_key);
		};
		node*	getUncle(void)
		{
			if (_papa->getSide() == 'r')
				return (getGrandPa()->getLeft());
			return (getGrandPa()->getRight());
		};
		node*	getSibling(void)
		{
			if (!_papa)
				return (NULL);
			if (_side == 'r')
				return (_papa->getLeft());
			return (_papa->getRight());
		};
		node*	getRedChild(void)
		{
			if (getLeft()->getColor() == 'r')
				return (getLeft());
			return (getRight());
		};
		int	execBalancing(void)
		{
			if (is_root())
				return (setRootColor());
			if (_papa->getColor() == 'n')
				return (0);
			if (isUncleRed())
				return (pushBlackness());
			if (_papa->getSide() == 'r')
			{
				if (_side == 'r')
					return (RRcase());
				return (RLcase());
			}
			if (_side == 'r')
				return (LRcase());
			return (LLcase());
		};
		int	execBalancingDelete(void)
		{
			node*	sibling = getSibling();

			if (!(sibling->getColor() == 'r'))
			{
				if (sibling->hasRedChild())
					return (siblingBlackChildRedCase());
				else
					return (siblingBlackNoRedCase());
			}
			if (sibling->getSide() == 'l')
				return (siblingRedLeftCase());
			return (siblingRedRightCase());
		};
		int	pushBlackness(void)
		{
			getGrandPa()->setColor('r');
			getUncle()->setColor('n');
			_papa->setColor('n');
			return (1);
		};
		int	RRcase(void)
		{
		//	disp("RRcase", 1);
			rotLeft(getPapa(), getGrandPa());
			swapColor(getPapa(), getSibling());
			return (0);
		};
		int	LLcase(void)
		{
		//	disp("LLcase", 1);
			rotRight(getPapa(), getGrandPa());
			swapColor(getPapa(), getSibling());
			return (0);
		};
		int	LRcase(void)
		{
		//	disp("LRcase for", getKey());
			rotLeft(this, getPapa());
			return (_left->LLcase());
		};
		int	RLcase(void)
		{
		//	disp("RLcase for", getKey());
			rotRight(this, getPapa());
			return (_right->RRcase());
		};
		int	RRcaseDelete(void)
		{
			disp("RR CASE DELETE", 1);

			char	colorPa;
			bool	allBlacks = isAllBlacks();

			rotLeft(getPapa(), getGrandPa());
			if (allBlacks)
			{
				disp("ALL BLACK", 1);
				setColor('n');
				getSibling()->setColor('n');
				getPapa()->setColor('n');
			}
			else
			{
				colorPa = getPapa()->getColor();
				swapColor(this, getPapa());
				if (!getSibling()->is_nil())
					getSibling()->setColor(colorPa);
			}
			return (0);
		}
		int	LLcaseDelete(void)
		{
			disp("LL CASE DELETE", 1);

			char	colorPa;
			bool	allBlacks = isAllBlacks();

			rotRight(getPapa(), getGrandPa());
			if (allBlacks)
			{
				disp("ALL BLACK", 1);
				setColor('n');
				getSibling()->setColor('n');
				getPapa()->setColor('n');
			}
			else
			{
				colorPa = getPapa()->getColor();
				swapColor(this, getPapa());
				if (!getSibling()->is_nil())
					getSibling()->setColor(colorPa);
			}
			return (0);
		}
		int	RLcaseDelete(void)
		{
			disp("RL CASE DELETE", 1);
			rotRight(this, getPapa());
			return (_right->RRcaseDelete());
		}
		int	LRcaseDelete(void)
		{
			disp("LR CASE DELETE", 1);
			rotLeft(this, getPapa());
			return (_left->LLcaseDelete());
		}
		int	siblingBlackChildRedCase(void)
		{
			node*	sibling	= getSibling();
			node*	redChild = sibling->getRedChild();

			if (sibling->getSide() == 'r')
			{
				if (redChild->getSide() == 'r')
					return (redChild->RRcaseDelete());
				return (redChild->RLcaseDelete());
			}
			if (redChild->getSide() == 'r')
				return (redChild->LRcaseDelete());
			return (redChild->LLcaseDelete());
		};
		int	siblingBlackNoRedCase(void)
		{
			disp("SIBLING BLACK NO RED CASE", 1);
			node*	papa = getPapa();

			getSibling()->setColor('r');
			if (papa->getColor() == 'r')
			{
				papa->setColor('b');
				return (0);
			}
			else
			{
				papa->setColor('d');
				return (1);
			}
		};
		int	siblingRedLeftCase(void)
		{
			disp("SIBLING RED LEFT CASE", 1);
			node*	papa = getPapa();
			node*	sibling = getSibling();

			rotRight(sibling, papa);
			swapColor(sibling, papa);
			swapColor(getSibling(), papa);
			return (0);
		};
		int	siblingRedRightCase(void)
		{
			disp("SIBLING RED RIGHT CASE", 1);
			node*	papa = getPapa();
			node*	sibling = getSibling();

			rotLeft(sibling, papa);
			swapColor(sibling, papa);
			swapColor(getSibling(), papa);
			return (0);
		};
		void	rotRight(node* x, node* y)
		{
			node*	rightX = x->getRight();
			node*	papaY = y->getPapa();
			char	sideY = y->getSide();

			x->setRight(y);
			y->setSide('r');
			y->setLeft(rightX);
			if (!rightX->is_nil())
			{
				rightX->setPapa(y);
				rightX->setSide('l');
			}
			y->setPapa(x);
			if (papaY)
			{
				x->setPapa(papaY);
				if (sideY == 'r')
				{
					papaY->setRight(x);
					x->setSide('r');
				}
				else
				{
					papaY->setLeft(x);
					x->setSide('l');
				}
			}
			else
			{
				x->_papa = NULL;
				x->setSide('c');
			}
		};
		void	rotLeft(node* x, node* y)
		{
			node*	leftX = x->getLeft();
			node*	papaY = y->getPapa();
			char	sideY = y->getSide();

			x->setLeft(y);
			y->setSide('l');
			y->setRight(leftX);
			if (!leftX->is_nil())
			{
				leftX->setPapa(y);
				leftX->setSide('r');
			}
			y->setPapa(x);
			if (papaY)
			{
				x->setPapa(papaY);
				if (sideY == 'r')
				{
					papaY->setRight(x);
					x->setSide('r');
				}
				else
				{
					papaY->setLeft(x);
					x->setSide('l');
				}
			}
			else
			{
				x->setPapa(NULL);
				x->setSide('c');
			}
		};
		void	swapColor(node* x, node* y)
		{
			char	tmp = x->getColor();

			x->setColor(y->getColor());
			y->setColor(tmp);
		};
		bool	isSiblingBlack(void)
		{
			return (!(getSibling()->getColor() == 'r'));
		};
		bool	isUncleRed(void)
		{
			node*	uncle = getUncle();

			if (uncle->is_nil() || uncle->getColor() == 'n')
				return (false);
			return (true);
		};
		bool	hasRedChild(void)
		{
			return (getRight()->getColor() == 'r'
					|| getLeft()->getColor() == 'r');
		};
		bool	isAllBlacks(void)
		{
			return (getPapa()->getColor() == 'n'
					&& getGrandPa()->getColor() == 'n');
		};
		node*	swipValueCase(void)
		{
			node*	substitute;

			if (hasTwoChild())
				substitute = findLargestFrom(getLeft());
			else
				substitute = findOnlyChild();
			swapPair(substitute);
			return (substitute);
		};
		node*	findOnlyChild(void)
		{
			if (getLeft()->is_nil())
				return (getRight());
			return (getLeft());
		};
		node*	findLargestFrom(node* from)
		{
			node*	toFind = from;

			while (!toFind->getRight()->is_nil())
				toFind = toFind->getRight();
			return (toFind);
		}
		bool	hasAlmostOneChild(void)
		{
			return (!getRight()->is_nil() || !getLeft()->is_nil());
		}
		bool	hasTwoChild(void)
		{
			return (!getRight()->is_nil() && !getLeft()->is_nil());
		}
		void	swapPair(node* x)
		{
			content_type	contentTmp = _content;
			key_type	keyTmp = _key;

			_content = x->getContent();
			_key = x->getKey();
			x->setContent(contentTmp);
			x->setKey(keyTmp);
		}
		node*	deleteMe(void)
		{
			node*	child;
			node*	newPapa = getPapa();

			if (hasAlmostOneChild())
			{
				child = findOnlyChild();
				if (child->getSide() == 'r')
					setRight(NULL);
				else
					setLeft(NULL);
				if (_side == 'r')
				{
					newPapa->setRight(child);
					child->setSide('r');
				}
				else
				{
					newPapa->setLeft(child);
					child->setSide('l');
				}
				if (child->getColor() == 'r')
					child->setColor('n');
				else
					child->setColor('d');
			}
			else
			{
				if (_side == 'r')
				{
					newPapa->setRight(new node);
					child = newPapa->getRight();
					child->setSide('r');
				}
				else
				{
					newPapa->setLeft(new node);
					child = newPapa->getLeft();
					child->setSide('l');
				}
				child->setColor('d');
			}
			child->setPapa(newPapa);
			setPapa(NULL);
			return (child);
		}
};
#endif
