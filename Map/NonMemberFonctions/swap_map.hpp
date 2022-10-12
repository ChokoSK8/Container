#ifndef SWAP_MAP_HPP
# define SWAP_MAP_HPP


template <class Key, class T, class Compare, class Alloc> 
void	swap(ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y)
{
	x.swap(y);
};
#endif
