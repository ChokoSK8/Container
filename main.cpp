# include "container.h"
# include "Stack.hpp"

int	main()
{
	ft::stack<int>	myStk;

	std::cout << myStk.empty() << std::endl;
	myStk.push(2);
	std::cout << myStk.empty() << std::endl;
	std::cout << "TOP myStk: " << myStk.top() << std::endl;
	ft::stack<int>	myStk2 = myStk;
	std::cout << "TOP myStk2: " << myStk2.top() << std::endl;
	myStk.pop();
	std::cout << "EMPTY mystk: " << myStk.empty() << std::endl;
	std::cout << "EMPTY mystk2: " << myStk2.empty() << std::endl;
	std::cout << "myStk == myStk2: ";
	if (myStk == myStk2)
		std::cout << "equal";
	else
		std::cout << "inequal";
	std::cout << std::endl;

	return (0);
}
