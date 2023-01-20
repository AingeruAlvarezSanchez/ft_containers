#include <vector>
#include "vector.hpp"
#include <iostream>

int	main() {
	std::vector<int>	vec(5, 1);
	ft::vector<int>	myVec(5,1);
	ft::vector<int>	vec2;
	vec2 = myVec;
	vec2.push_back(54);
	vec.push_back(54);
	vec2.reserve(17);
	vec.reserve(17);
	vec2.push_back(42);
	vec.push_back(42);
	std::vector<int>::iterator	it = vec.end();
	ft::vector<int>::iterator	it2 = vec2.end();

	std::cout << "Iterator: " << *it2 << std::endl;
	for (; it2 != vec2.begin(); it2--)
		std::cout << "MY Content: " << *it2 << "\n";
	std::cout << "MY capacity: " << vec2.capacity() << "\n";
	std::cout << "MY size: " << vec2.size() << "\n";

	std::cout << "-------- Separator --------\n";

	std::cout << "Iterator: " << *it << std::endl;
	for (; it != vec.begin(); it--)
		std::cout << "Content: " << *it << "\n";
	std::cout << "Capacity: " << vec.capacity() << "\n";
	std::cout << "Size: " << vec.size() << "\n";

	std::cout << "-------- Separator --------\n";

	std::cout << "Main function\n";
	return 0;
}
