#include <vector>
#include "vector.hpp"
#include <iostream>

int	main() {
	std::vector<int>	vec(1, 50);
	ft::vector<int>	myVec(1,50);
	ft::vector<int>	vec2;

	vec2 = myVec;

	vec.push_back(51);
	vec.push_back(52);
	vec.push_back(53);

	vec2.push_back(51);
	vec2.push_back(52);
	vec2.push_back(53);

	//std::cout << "Result of pointer: " << *vec.erase(vec.begin(), vec.end()) << "\n";
	std::cout << "Result of pointer: " << *vec2.erase(vec2.begin(), vec2.end()) << "\n";
	std::vector<int>::iterator	it = vec.begin();
	ft::vector<int>::iterator	it2 = vec2.begin();

	std::cout << "-------- Separator --------\n";
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
	return 0;
}
