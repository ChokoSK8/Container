#ifndef MAP_HPP
# define MAP_HPP
# include "../pair.hpp"
# include "../containers.h"
# include "mapNode.hpp"
# include "rbrator.hpp"

# include <sstream>
# include <vector>

template < class Key, class T, class Compare, class Allocator >
class	ft::map
{
	public:
		typedef	Key					key_type;
		typedef T					mapped_type;
		typedef pair<const Key, T>			value_type;
		typedef std::size_t				size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef Compare					key_compare;
		typedef Allocator				allocator_type;
		typedef value_type&				reference;
		typedef const value_type&			const_reference;
		typedef node<key_type, mapped_type>*		pointer;
		typedef const pointer				const_pointer;

		// ITERATOR
		typedef rbrator<pointer>		iterator;
		typedef rbrator<const_pointer>		const_iterator;
	//	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	//	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	protected:
		size_type	_size;
		allocator_type	_c;
		pointer		_root;

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

			pointer	newNode = new node<key_type, mapped_type>(val);

			if (_root)
				positionNode(newNode, _root);
			else
				_root = newNode;
			balanceTree(newNode);

		//	disp("------NEW NODE------", val.first);
		//	print_tree_side();
			// RETURN THE RIGHT THING
		};

		// ITERATOR
		#include "iterator_map.hpp"

	private:
		void	positionNode(pointer newNode, pointer from)
		{
			while (from)
			{
				if (newNode->getKey() < from->getKey())
				{
					if (!from->getLeft())
						return (from->setNewNodeLeft(newNode, 'l'));
					from = from->getLeft();
				}
				else
				{
					if (!from->getRight())
						return (from->setNewNodeRight(newNode, 'r'));
					from = from->getRight();
				}
			}
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
		void	print_tree_side(void)
		{
			iterator	it = begin();
			iterator	ite = end();

			int i = 20;
			while (it != ite && --i > 0)
			{
				disp("KEY", it->getKey());
				disp("SIDE", it->getSide());
				++it;
			}
			disp("KEY", it->getKey());
			disp("SIDE", it->getSide());
		};
		# include "print.hpp"
		
};
#endif
