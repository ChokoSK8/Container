#ifndef NODE_HPP
# define NODE_HPP
# include "../containers.h"

template < class Key, class T >
class	ft::node
{
	public:
		typedef pair<const Key, T>	value_type;
		typedef Key			key_type;
		typedef T			content_type;

	protected:
//		value_type	_val;
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
		node(const value_type& val)
		{
//			_val = val;
			_key = val.first;
			_content = val.second;
			_left = new node;
			_right = new node;
			_papa = NULL;
			_color = 'r';
			_side = 'c';
		};
		node(const node<key_type, content_type>& mit)
		{
//			_val = mit.getVal();
			_key = mit.getKey();
			_content = mit.getContent();
			_left = mit.getLeft();
			_right = mit.getRight();
			_papa = mit.getPapa();
			_color = mit.getColor();
			_side = mit.getSide();
		};

		// FCTS
		bool	is_nil(void)
		{
			return (_color == 's');
		};
		bool	is_root(void)
		{
			return (!_papa);
		};
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
		int	setNewNodeRight(node* newNode, char side)
		{
			newNode->setSide(side);
			delete _right;
			setRight(newNode);
			newNode->setPapa(this);
			newNode->setRight(new node);
			newNode->setLeft(new node);
			return (1);
		};
		int	setNewNodeLeft(node* newNode, char side)
		{
			newNode->setSide(side);
			delete _left;
			setLeft(newNode);
			newNode->setPapa(this);
			newNode->setRight(new node);
			newNode->setLeft(new node);
			return (1);
		};
//		value_type	getVal(void) const
//		{
//			return (_val);
//		};
		node*	getRight(void)
		{
			return (_right);
		};
		node*	getLeft(void)
		{
			return (_left);
		};
		node*	getPapa(void)
		{
			return (_papa);
		};
		node*	getGrandPa(void)
		{
			return (_papa->getPapa());
		};
		char	getSide(void)
		{
			return (_side);
		};
		char	getColor(void)
		{
			return (_color);
		};
		content_type	getContent(void) const
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
		bool	isUncleRed(void)
		{
			node*	uncle = getUncle();

			if (uncle->is_nil() || uncle->getColor() == 'n')
				return (false);
			return (true);
		};
};
#endif