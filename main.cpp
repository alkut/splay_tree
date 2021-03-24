#include <iostream>
#include "check_bst.hpp"

int main()
{
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i<m; ++i)
	{
		if (!check(n))
		{
			std::cout << "something go wrong!\n";
			return -1;
		}
	}
	std::cout << "everything is fine\n";
	return 0;
}