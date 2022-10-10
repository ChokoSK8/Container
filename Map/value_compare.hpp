#ifdef MAP_HPP
# ifndef VALUE_COMPARE_HPP
#  define VALUE_COMPARE_HPP

template < class Key, class T, class Compare, class Alloc >
class map<Key, T, Compare, Alloc>::value_compare
{
	private:
		friend class map;
	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {};
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator()(const value_type& x, const value_type& y) const
		{
			return (comp(x.first, y.first));
		};
};
# endif
#endif
