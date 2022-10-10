#include "vector.hpp"
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>

using namespace NAMESPACE;

vector<int>	makeVec(int start, int range);
void	displayVec(vector<int> vec);
void	displayVec(vector<std::string> vec);
int	assignVecTester(void);
int	insertVecTester(void);
int	eraseVecTester(void);
int	reserveVecTester(void);
int	push_backVecTester(void);
int	swapVecTester(void);
int	clearVecTester(void);
int	pop_backVecTester(void);
int	operatorHookVecTester(void);
int	atVecTester(void);
int	max_sizeVecTester(void);
int	resizeVecTester(void);
int	emptyVecTester(void);
int	frontVecTester(void);
int	backVecTester(void);
