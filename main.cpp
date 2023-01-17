#include <vector>
#include "vector.hpp"
#include <iostream>

int	main() {
	std::vector<int>	vec(8, 4);
	ft::vector<int>	myVec(8,4);
	std::cout << "STL: " << vec.capacity() << "\n";
	std::cout << "MINE: " << myVec.capacity() << "\n";
	std::cout << "Main function\n";
	return 0;
}
