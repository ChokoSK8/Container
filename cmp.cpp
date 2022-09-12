# include <iostream>
# include <string>
# include <vector>
# include <memory>
# include <limits>

using namespace std;

template < typename T >
void	disp(std::string str, T val)
{
	std::cout << str << ": " << val << std::endl;
}

template < typename T >
void	displayVec(vector<T> vec)
{
	vector<int>::iterator	it = vec.begin();
	vector<int>::iterator	ite = vec.end();

	disp("SIZE", vec.size());
	while (it != ite)
	{
		std::cout << " - " << *it << std::endl;
		it++;
	}
}

int	main()
{
	vector<int>	vec2;

	vec2.push_back(11);
	vec2.push_back(12);
	vec2.push_back(13);
	vec2.push_back(14);
	vec2.push_back(15);
	vec2.push_back(16);
	vec2.push_back(17);
	vec2.push_back(18);

/*	std::cout << vec1.size() << std::endl;

	//	PUSH_BACK
	std::cout << "\n\t-----PUSH_BACK TESTS-----\n" << std::endl;

	vec1.push_back(10);
	vec1.push_back(11);
	vec1.push_back(12);
	vec1.push_back(13);
	vec1.push_back(14);
	vec1.push_back(15);
	vec1.push_back(16);
	vec1.push_back(17);
	vec1.push_back(18);
	vec1.push_back(19);
	std::cout << vec1.size() << std::endl;

	std::cout << "VEC1: " << std::endl;
	displayVec(vec1);

	//	ASSIGN
	std::cout << "\n\n\t-----ASSIGN TESTS-----\n" << std::endl;

	vector<int>	vec2;
	vector<int>::iterator	it1 = vec1.begin();

	vec2.assign(10, 55);
	std::cout << "VEC2: " << std::endl;
	displayVec(vec2);

//	vec2.assign(it1 + 2, it1 + 50);

//	vec2.assign(it1 + 1, it1 + 9);
	std::cout << "VEC2: " << std::endl;
	displayVec(vec2);*/

	//	ERASE
	std::cout << "\n\n\t-----ERASE TESTS-----\n" << std::endl;

//	vector<int>::iterator	it2 = vec2.begin();
//	vector<int>::iterator	erP = it2 - 2;
//	vector<int>::iterator	ret = vec2.erase(it2 - 2);

	std::cout << "VEC2: " << std::endl;
	displayVec(vec2);

	vec2.erase(vec2.begin() + 6, vec2.begin() + 4);
	std::cout << "VEC2: " << std::endl;
	displayVec(vec2);
	disp("FIRST:", *(vec2.begin() - 4));

	disp("END TESTS", 1);
	return (0);
}
