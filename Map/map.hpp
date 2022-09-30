#ifndef MAP_HPP
# define MAP_HPP
# include "../pair.hpp"
# include "../containers.h"
# include "node.hpp"
# include "rbrator.hpp"

# include <sstream>
# include <vector>

template < class Key, class T, class Compare, class Allocator >
class	ft::map
{
	public:
		typedef	Key			key_type;
		typedef T			mapped_type;
		typedef pair<const Key, T>	value_type;
		typedef std::size_t		size_type;
		typedef std::ptrdiff_t		difference_type;
		typedef Compare			key_compare;
		typedef Allocator		allocator_type;
		typedef value_type&		reference;
		typedef const value_type&	const_reference;
		typedef node<value_type>*	pointer;
		typedef const node<value_type>*	const_pointer;

		// ITERATOR
		typedef rbrator<pointer>		iterator;
		typedef rbrator<const_pointer>		const_iterator;
	//	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	//	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	protected:
		size_type	_size;
		allocator_type	_c;
		pointer		_root;
		key_compare	_keyComp;

	public:
		explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
		{
		//	_c.allocate(0);
			_size = 0;
			_root = NULL;
			(void)comp;
			(void)alloc;
		};
		map(const map& x)
		{
			_c = x.get_allocator();
			insert(x.begin(), x.end());
		};
//		template < class InputItr >
//		map(InputItr first, InputItr last, const key_compare& comp = key_compare(),
//				const allocator_type& alloc = allocator_type())
//		{
//			size_type	length = ft::distance(first, last);
//
//			_c.allocate(length);
//			_size = length;
//			(void)comp;
//			(void)alloc;
//			while (first != last)
//			{
//				_c.const
//			}
//		};
		~map(void)
		{
			freeNodes(_root);
		};

		// ITERATOR
		#include "iterator_map.hpp"

		// CAPACITY

		// ELEMENT_ACCES
		# include "element_access_map.hpp"

		// MODIFIERS
		#include "modifiers_map.hpp"

		// OPERATIONS
		#include "operations_map.hpp"

		// ALLOCATOR
		allocator_type	get_allocator(void) const
		{
			return (_c);
		};

	/*---------------TO DELETE-------------*/

		// GETTER
		pointer	getRoot(void)
		{
			return (_root);
		};

	/*---------------END TO DELETE-------------*/

	private:
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
		# include "print.hpp"
		
};
#endif
