# include <iostream>
# include <vector>
# include <memory>

using namespace std;

template < typename T >
void	disp(std::string str, T val)
{
	std::cout << str << ": " << val << std::endl;
}

template < typename type >
struct myAlloc : allocator<type> {
	typedef typename allocator<type>::size_type	size_type;
	typedef typename allocator<void>::const_pointer	const_pointer;
	typedef typename allocator<type>::pointer	pointer;
	pointer *	allocate(size_type size, const_pointer hint=0) {
		cout << "HEY" << endl;
		std::cout << "Allocation request size => " << size << std::endl;
		return new type[size];
	}
};

void	displayVec(std::vector<int> vec)
{
	std::vector<int>::iterator	it = vec.begin();
	std::vector<int>::iterator	ite = vec.end();

	std::cout << "BEGIN ADDR DISPLAY:" << &it << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

int	main()
{
	std::vector<int>	v3;
	std::vector<int>	v1;

	v1.push_back(10);
	v1.push_back(11);
	v1.push_back(12);
	v1.push_back(13);
	v1.push_back(14);
	v1.push_back(15);
	v1.push_back(16);
	v1.push_back(17);
	v1.push_back(18);
	v1.push_back(19);

	v3.push_back(30);
	v3.push_back(31);
	v3.push_back(32);
	v3.push_back(33);
	v3.push_back(34);
	v3.push_back(35);
	v3.push_back(36);
	v3.push_back(37);
	v3.push_back(38);
	v3.push_back(39);

	std::cout << "VEC3: " << std::endl;
	displayVec(v3);

	vector<int>::iterator	it3 = v3.begin();
	vector<int>::iterator	it1 = v1.begin();
	vector<int>::iterator	er = it3 + 5;
	vector<int>::iterator	ere = it3 + 3;
	
	v3.erase(er, ere);
	std::cout << "VEC3: " << std::endl;
	displayVec(v3);

	return (0);
}
