template < class T1, class T2 >
void	displayPair(pair<T1, T2> p)
{
	std::cout << "FIRST: " << p.first  << " | SECOND: " << p.second << std::endl;
}

void	dispAct(std::string	str)
{
	std::cout << "------- " << str << " -------" << std::endl;
}

template < class Container >
void	equalTest(Container x, Container y, int reverse = 1)
{
	disp("equal(x.begin(), x.end(), y.begin(), y.end())",
		equal(x.begin(), x.end(), y.begin()));
	disp("equal(x.begin() + 2, x.end() - 2, y.begin(), y.end())",
		equal(x.begin() + 2, x.end() - 2, y.begin()));
	disp("equal(x.begin() + 2, x.end() - 2, y.begin() + 2, y.end() - 2)",
		equal(x.begin() + 2, x.end() - 2, y.begin() + 2));
	if (reverse)
		return (equalTest(y, x, 0));
}

template < class Container1, class Container2 >
void	equalTest(Container1 x, Container2 y, int reverse = 1)
{
	disp("equal(x.begin(), x.end(), y.begin(), y.end())",
		equal(x.begin(), x.end(), y.begin()));
	disp("equal(x.begin() + 2, x.end() - 2, y.begin(), y.end())",
		equal(x.begin() + 2, x.end() - 2, y.begin()));
	disp("equal(x.begin() + 2, x.end() - 2, y.begin() + 2, y.end() - 2)",
		equal(x.begin() + 2, x.end() - 2, y.begin() + 2));
	if (reverse)
		return (equalTest(y, x, 0));
}

int	equalTester(void)
{
	vector<int>	v1 = makeVec(1, 10);
	vector<int>	v2 = makeVec(1, 5);
	vector<int>	v3 = makeVec(2, 11);

	equalTest(v1, v2);
	equalTest(v1, v3);
	equalTest(v2, v3);
	return (0);
}

template < class T1, class T2 >
void	pairCmpTester(pair<T1, T2>& x, pair<T1, T2>& y, int recur = 1)
{
	disp("PAIR X", 1);
	displayPair(x);
	disp("PAIR Y", 1);
	displayPair(y);
	disp("x == y", x == y);
	disp("x != y", x != y);
	disp("x <= y", x <= y);
	disp("x >= y", x >= y);
	disp("x < y", x < y);
	disp("x > y", x > y);
	if (recur)
		return pairCmpTester(y, x, 0);
}

int	pair&make_pairTester(void)
{
	pair<int, double>	p1;
	pair<std::string, char>	p2("hello", 'B');
	pair<std::string, char>	p3(p2);
	pair<float, float>	p4(21.212121, 42.42);
	pair<float, float>	p5(4, 2);

	dispAct("CONSTRUCTOR TESTS");
	disp("PAIR", 1);
	displayPair(p1);
	disp("PAIR", 2);
	displayPair(p2);
	disp("PAIR", 3);
	displayPair(p3);
	disp("PAIR", 4);
	displayPair(p4);

	dispAct("p1 == p4");
	p1 = p4;
	disp("PAIR", 1);
	displayPair(p1);

	dispAct("make_pair(52.3, \"coucou\") --------");
	displayPair(make_pair(52.3, "coucou"));

	dispAct("COMPARAISON");
	pairCmpTester(p4, p5);
	return (0);
}
