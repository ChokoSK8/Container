# include "../tester.h"

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

	displayVec(v1);
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
	v1.insert(v1.begin(), v1.begin() + 2, v1.end() - 5);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v2.insert(v2.begin() + 6, v1.begin() + 2, v1.end() - 5);
	disp("CAPACITY", v2.capacity());
	displayVec(v2);

	return (0);
}

int	eraseTester(void)
{
	vector<int>		v1 = makeVec(1, 9);

	disp("CAPACITY", v1.capacity());
	displayVec(v1);
	v1.erase(v1.begin(), v1.begin() + 2);
	disp("CAPACITY", v1.capacity());
	displayVec(v1);
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
