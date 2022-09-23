	// UTILS

template < class T1, class T2 >
void	displayPair(pair<T1, T2> p)
{
	std::cout << "FIRST: " << p.first  << " | SECOND: " << p.second << std::endl;
}

void	dispAct(std::string	str)
{
	std::cout << "------- " << str << " -------" << std::endl;
}

	// CAPACITY

int	max_sizeTester(void)
{
	vector<int>		v1 = makeVec(1, 5);
	vector<int>		v2;
	vector<std::string>	v3;
	vector<double>		v4;
	vector<float>		v5;

	disp("MAX_SIZE 1", v1.max_size());
	disp("MAX_SIZE 2", v2.max_size());
	disp("MAX_SIZE 3", v3.max_size());
	disp("MAX_SIZE 4", v4.max_size());
	disp("MAX_SIZE 5", v5.max_size());
	return (0);
}

int	resizeTester(void)
{
	vector<int>	v1 = makeVec(1, 142);

	v1.resize(100);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.resize(120);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.resize(18, 5555);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	return (0);
}

int	emptyTester(void)
{
	vector<int>	v1 = makeVec(1, 1);

	disp("EMPTY", v1.empty());
	v1.clear();
	disp("EMPTY", v1.empty());
	v1.resize(0, 55);
	disp("EMPTY", v1.empty());
	return (0);
}

int	reserveTester(void)
{
	vector<int>		v1;

	v1.reserve(5);
	disp("CAPACITY", v1.capacity());
	v1.push_back(1);
	disp("CAPACITY", v1.capacity());
	v1.push_back(2);
	disp("CAPACITY", v1.capacity());
	v1.push_back(3);
	disp("CAPACITY", v1.capacity());
	v1.push_back(4);
	disp("CAPACITY", v1.capacity());
	v1.push_back(5);
	disp("CAPACITY", v1.capacity());
	v1.push_back(6);
	disp("CAPACITY", v1.capacity());
	v1.push_back(7);
	disp("CAPACITY", v1.capacity());
	v1.push_back(8);
	disp("CAPACITY", v1.capacity());
	v1.reserve(9);
	disp("CAPACITY", v1.capacity());
	return (0);
}


	// ELEMENT ACCESS

int	operatorHookTester(void)
{
	vector<int>	v1 = makeVec(1, 5);
	vector<int>	v2 = makeVec(20, 13);

	disp("v1[5]", v1[5]);
	disp("v1[4]", v1[4]);
	disp("v1[2]", v1[2]);
	disp("v1[0]", v1[0]);
	disp("v2[5]", v2[5]);
	disp("v2[12]", v2[12]);

	return (0);
}

int	atTester(void)
{
	vector<int>	v1 = makeVec(1, 5);
	vector<int>	v2 = makeVec(20, 13);

//	disp("v1[5]", v1.at(5));
	disp("v1[0]", v1.at(0));
//	disp("v1[50]", v1.at(50));
	disp("v1[1]", v1.at(1));
	disp("v2[5]", v2.at(5));
//	disp("v2[-10]", v2.at(-10));
//	disp("v2[13]", v2.at(13));

	return (0);
}

int	frontTester(void)
{
	vector<int>	v1 = makeVec(1, 5);
	vector<int>	v2 = makeVec(0, 0);

	disp("FRONT V1", v1.front());
//	disp("ADDR BEGIN 2", v2.begin().base());
//	disp("FRONT V2", v2.front());
	return (0);
}

int	backTester(void)
{
	vector<int>	v1 = makeVec(1, 5);
	vector<int>	v2 = makeVec(0, 0);

	disp("BACK V1", v1.back());
//	disp("ADDR BEGIN 2", v2.begin().base());
//	disp("BACK V2", v2.back());
	return (0);
}


	// MODIFIERS

int	assignTester(void)
{
	vector<std::string>		v1;
	vector<std::string>		v2;

	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.assign(10, "hello");
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v2.assign(20, "byebye");
	disp("CAPACITY", v2.capacity());
	displayVec(v2);
	disp("CAPACITY BEFORE", v1.capacity());
	v1.assign(v2.begin(), v2.begin() + 3);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);

	return (0);
}

int	push_backTester(void)
{
	vector<int>		v1;

	displayVec(v1);
	v1.push_back(1);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(2);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(3);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(4);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(5);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(6);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.push_back(7);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	for (int i = 89 ; i < 200 ; i++)
		v1.push_back(i);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	
	return (0);
}

int	insertTester(void)
{
	vector<int>		v1 = makeVec(1, 10);
	vector<int>		v2 = makeVec(2, 15);

	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.insert(v1.begin() + 3, 1, 10);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.insert(v1.end(), 5, 9);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.insert(v1.begin(), 5, 11);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.insert(v1.begin(), v1.begin() + 2, v1.begin() + 5);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v2.insert(v2.begin() + 6, v1.begin() + 2, v1.begin() + 5);
	disp("CAPACITY", v2.capacity());
	displayVec(v2);

	return (0);
}

int	eraseTester(void)
{
	vector<int>		v1 = makeVec(1, 9);

	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	disp("RETURN", *(v1.erase(v1.begin(), v1.begin() + 2)));
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	disp("RETURN", *(v1.erase(v1.begin())));
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	return (0);
}

int	pop_backTester(void)
{
	vector<int>	v1 = makeVec(1, 9);

	while (v1.size())
	{
		v1.pop_back();
		disp("CAPACITY", v1.capacity());
		displayVec(v1);
	}
	return (0);
}

int	swapTester(void)
{
	vector<int>	v1 = makeVec(1, 20);
	vector<int>	v2 = makeVec(55, 6);

	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	disp("CAPACITY", v2.capacity());
	displayVec(v2);
	disp("------------SWAP----------", 1);
	v1.swap(v2);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	disp("CAPACITY", v2.capacity());
	displayVec(v2);

	return (0);
}

int	clearTester(void)
{
	vector<int>	v1 = makeVec(1, 50);

	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	disp("-----------CLEAR----------", 1);
	v1.clear();
	disp("CAPACITY", v1.capacity());
	displayVec(v1);

	return (0);
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

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "How to use: ./container <fct to test>"<< std::endl;
		return (1);
	}

	std::map<std::string, PtrFct>		fcts;
	PtrFct					fct;
	std::map<std::string, PtrFct>::iterator	it;
	std::map<std::string, PtrFct>::iterator	ite;
	std::string				str = av[1];

	fcts["assign"] = &assignTester;
	fcts["insert"] = &insertTester;
	fcts["erase"] = &eraseTester;
	fcts["reserve"] = &reserveTester;
	fcts["push_back"] = &push_backTester;
	fcts["pop_back"] = &pop_backTester;
	fcts["swap"] = &swapTester;
	fcts["clear"] = &clearTester;
	fcts["operator[]"] = &operatorHookTester;
	fcts["at"] = &atTester;
	fcts["front"] = &frontTester;
	fcts["back"] = &backTester;
	fcts["max_size"] = &max_sizeTester;
	fcts["resize"] = &resizeTester;
	fcts["empty"] = &emptyTester;
	fcts["equal"] = &equalTester;
	fcts["pair"] = &pair&make_pairTester;
	for (it = fcts.begin(), ite = fcts.end(); it != ite; it++)
	{
		if (!str.compare(it->first))
		{
			fct = it->second;
			return (fct ());
		}
	}
	disp("FCT NOT FOUND", 1);
	return (1);
}
