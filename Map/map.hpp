#ifndef MAP_HPP
# define MAP_HPP
# include "../pair.hpp"
# include "../containers.h"
# include "mapNode.hpp"

template < class Key, class T, class Compare, class Allocator >
class	ft::map
{
	public:
		typedef	Key					key_type;
		typedef T					mapped_type;
		typedef ft::pair<const Key, T>			value_type;
		typedef std::size_t				size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef Compare					key_compare;
		typedef Allocator				allocator_type;
		typedef value_type&				reference;
		typedef const value_type&			const_reference;
		typedef typename Allocator::pointer		pointer;
		typedef typename Allocator::const_pointer	const_pointer;

		// ITERATOR
	//	typedef ft::random_access_iterator<pointer>		iterator;
	//	typedef ft::random_access_iterator<const_pointer>	const_iterator;
	//	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	//	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	protected:
		size_type			_size;
		allocator_type			_c;
		node<key_type, mapped_type>*	_root;

	public:
		explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
		{
			_c.allocate(0);
			_size = 0;
			_root = NULL;
			(void)comp;
			(void)alloc;
		};
		template < class InputItr >
		map(InputItr first, InputItr last, const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
		{
			size_type	length = ft::distance(first, last);

			_c.allocate(length);
			_size = length;
			(void)comp;
			(void)alloc;
		//	while (first != last)
		//	{
		//		_c.const
		//	}
		};

		// MODIFIERS
	//	ft::pair<iterator, bool>	insert(const value_type& val)
		void	insert(const value_type& val)
		{
			// check if key already exist

			node<key_type, mapped_type>*	newNode =
					new node<key_type, mapped_type>(val);

			if (_root)
				positionNode(newNode, _root);
			else
				_root = newNode;
			balanceTree(newNode);

			disp("------NEW NODE-------", 1);
			displayNode(*newNode);
			// RETURN THE RIGHT THING
		};

	private:
		void	displayNode(node<key_type, mapped_type>& _node_, int config = 1)
		{
			disp("key", _node_.getKey());
			disp("content", _node_.getContent());
			disp("left", _node_.getLeft());
			disp("right", _node_.getRight());
			disp("papa", _node_.getPapa());
			disp("side", _node_.getSide());
			disp("color", _node_.getColor());
			disp("addr", &_node_);
			if (config && _node_.getPapa())
			{
				disp("-------PAPA-----", 1);
				displayNode(*(_node_.getPapa()), 0);
			}
			if (config && _node_.getSibling())
			{
				disp("--------SIBLING-----", 1);
				displayNode(*(_node_.getSibling()), 0);
			}
		}
		void	positionNode(node<key_type, mapped_type>* newNode,
				node<key_type, mapped_type>* from)
		{
			if (newNode->getKey() < from->getKey())
			{
				if (from->getLeft())
					return (positionNode(newNode, from->getLeft()));
				from->setNewNodeLeft(newNode, 'l');
			}
			else
			{
				if (from->getRight())
					return (positionNode(newNode, from->getRight()));
				from->setNewNodeRight(newNode, 'r');
			}
		};
		void	balanceTree(node<key_type, mapped_type>* _node_)
		{
			if (_node_->execBalancing())
				return (balanceTree(_node_->getGrandPa()));
		};
		
};
#endif
