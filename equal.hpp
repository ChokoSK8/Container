#ifndef EQUAL_HPP
# define EQUAL_HPP

template < class Iterator1, class Iterator2 >
bool	ft::equal(Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2)
{
	while (first2 != last2)
	{
		if (*first1 != *first2)
			return (false);
		++first1;
		++first2;
		if (first1 == last1)
			return (true);
	}
	return (false);
};
template < class Iterator >
bool	ft::equal(Iterator first1, Iterator last1, Iterator first2, Iterator last2)
{
	while (first2 != last2)
	{
		if (*first1 != *first2)
			return (false);
		++first1;
		++first2;
		if (first1 == last1)
			return (true);
	}
	return (false);
};
#endif
