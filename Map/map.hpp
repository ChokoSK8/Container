#ifndef MAP_HPP
# define MAP_HPP
# include "../ExtraClass/pair.hpp"
# include "../containers.h"
# include "Node/node.hpp"
# include "Iterators/rbrator.hpp"
# include "Iterators/const_rbrator.hpp"
# include "Iterators/reverse_rbrator.hpp"

# include <sstream>
# include <vector>

template < class Key, class T, class Compare, class Allocator >
class	ft::map
{
	public:
		typedef	Key			key_type;
		typedef T			mapped_type;
		typedef pair<const Key, T>	value_type;
		typedef Compare			key_compare;
		typedef std::size_t		size_type;
		typedef std::ptrdiff_t		difference_type;
		typedef Allocator		allocator_type;
		typedef value_type&		reference;
		typedef const value_type&	const_reference;
		typedef value_type*		pointer;
		typedef const value_type*	const_pointer;
		typedef node<value_type>*	nodePtr;
		typedef node<const value_type>*	const_nodePtr;

		// ITERATOR
		typedef rbrator<value_type, node<value_type> >		iterator;
		typedef rbrator<const value_type, node<value_type> >	const_iterator;
		typedef ft::reverse_rbrator<iterator>			reverse_iterator;
		typedef ft::reverse_rbrator<const_iterator>		const_reverse_iterator;

	protected:
		size_type	_size;
		allocator_type	_c;
		nodePtr		_root;
		key_compare	_keyComp;

	public:
		explicit map(const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
		{
			_c = alloc;
			_size = 0;
			_root = new node<value_type>;
			_keyComp = comp;
		};
		map(const map& x)
		{
			_c = x.get_allocator();
			_keyComp = x.key_comp();
			_size = 0;
			_root = new node<value_type>;
			const_iterator	it = x.begin();
			const_iterator	ite = x.end();

			while (it != ite)
			{
				insert(make_pair(it->first, it->second));
				++it;
			}
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
		#include "MemberFonctions/iterator_map.hpp"

		// CAPACITY
		#include "MemberFonctions/capacity_map.hpp"

		// ELEMENT_ACCES
		# include "MemberFonctions/element_access_map.hpp"

		// MODIFIERS
		#include "MemberFonctions/modifiers_map.hpp"

		// OBSERVERS
	//	#include "MemberFonctions/observers_map.hpp"

		// OPERATIONS
		#include "MemberFonctions/operations_map.hpp"

		// ALLOCATOR
		allocator_type	get_allocator(void) const
		{
			return (_c);
		};

		// VALUE_COMPARE
	//	#include "value_compare.hpp"

	private:
		# include "MemberFonctions/private_map.hpp"
		# include "print.hpp"
		
};
#endif
