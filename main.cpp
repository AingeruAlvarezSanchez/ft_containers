#include <vector>
#include "vector.hpp"
#include <iostream>

int	main() {
	std::vector<int>	vec(1, 42);
	ft::vector<int>	myVec(1,42);

	ft::vector<int>	vec2;
	vec2 = myVec;
	vec2.resize(5, 'A');
	vec.resize(5, 'A');
	std::vector<int>::iterator	it = vec.begin();
	ft::vector<int>::iterator	it2 = vec2.begin();

	std::cout << "Iterator: " << *it2 << std::endl;
	for (; it2 != vec2.end(); it2++)
		std::cout << "MY Content: " << *it2 << "\n";
	std::cout << "MY capacity: " << vec2.capacity() << "\n";
	std::cout << "MY size: " << vec2.size() << "\n";

	std::cout << "-------- Separator --------\n";

	std::cout << "Iterator: " << *it << std::endl;
	for (; it != vec.end(); it++)
		std::cout << "Content: " << *it << "\n";
	std::cout << "Capacity: " << vec.capacity() << "\n";
	std::cout << "Size: " << vec.size() << "\n";

	std::cout << "-------- Separator --------\n";

	std::cout << "Main function\n";
	return 0;
}
