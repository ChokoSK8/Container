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
		~map(void) {};

		// MODIFIERS
		ft::pair<iterator, bool>	insert(const value_type& val)
		{
			pointer	newNode = new node<key_type, mapped_type>(val);
			ft::pair<iterator, bool>	ret;

			if (_root)
			{
				ret = positionNode(newNode, _root);
				if (!ret.second)
					return (ret);
			}
			else
			{
				_root = newNode;
			}
			balanceTree(newNode);
			return (make_pair(iterator(newNode), true));
		};

		// ITERATOR
		#include "iterator_map.hpp"

		// OPERATIONS
		#include "operations_map.hpp"

	/*---------------TO DELETE-------------*/

		// GETTER
		pointer	getRoot(void)
		{
			return (_root);
		};

		// PRINT
		void	printDownFrom(pointer from)
		{
			if (!from->getLeft()->is_nil())
				return (printDownFrom(from->getLeft()));
			if (!from->getRight()->is_nil())
				return (printDownFrom(from->getRight()));
			disp("KEY", from->getKey());
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
