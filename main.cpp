# include "container.h"
# include "stack.hpp"
# include <stack>
typedef std::list<int> container_type;
#define t_stack_ ft::stack<int, container_type>


int		main(void)
{
	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_stack_		stck(ctnr);

	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << "size: " << stck.size() << std::endl;

	stck.push(1);
	stck.push(2);
	stck.push(3);
	stck.push(4);
	stck.push(5);
	stck.push(6);

	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck.empty() << std::endl;

	return (0);
}

/*int	main()
{
	container_type	myStk;

	std::cout << myStk.empty() << std::endl;
	myStk.push(2);
	std::cout << myStk.empty() << std::endl;
	std::cout << "TOP myStk: " << myStk.top() << std::endl;

	t_stack_	myStk2(myStk);
	ft::stack<int>	myStk3(myStk2);

	std::cout << "TOP myStk2: " << myStk2.top() << std::endl;
	std::cout << "TOP myStk3: " << myStk3.top() << std::endl;
	myStk.pop();
	std::cout << "EMPTY mystk: " << myStk.empty() << std::endl;
	std::cout << "EMPTY mystk2: " << myStk2.empty() << std::endl;
	std::cout << "myStk == myStk2: ";
	if (myStk == myStk2)
		std::cout << "equal";
	else
		std::cout << "inequal";
	std::cout << std::endl;
	std::cout << "myStk2 == myStk3: ";
	if (myStk2 == myStk3)
		std::cout << "equal";
	else
		std::cout << "inequal";
	std::cout << std::endl;

	return (0);
}*/
