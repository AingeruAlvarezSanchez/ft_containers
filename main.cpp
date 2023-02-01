#include <vector>
#include "vector.hpp"
#include <iostream>

int	main() {
	std::vector<int>	vec(1, 42);
	ft::vector<int>	myVec(1,42);
	ft::vector<int>	vec2;

	vec2 = myVec;

	std::cout << "begin pre: " << *vec.begin() << "\n";
	vec.assign(1, 55);
	std::cout << "begin post: " << *vec.begin() << "\n";
	vec.push_back(32);
	vec.push_back(22);
	vec.push_back(12);
	std::cout << "CHECKER FOR BEGIN: " << *vec.begin() << "\n";
	std::cout << "CHECKER FOR END: " << *vec.end() << "\n"; //TODO after the 3rd push_back end is same as begin??

	std::cout << "MY begin pre: " << *vec2.begin() << "\n";
	vec2.assign(1, 55);
	std::cout << "MY begin post: " << *vec2.begin() << "\n";
	vec2.push_back(32);
	vec2.push_back(22);
	vec2.push_back(12);
	std::cout << "MY CHECKER FOR BEGIN: " << *vec2.begin() << "\n";
	std::cout << "MY CHECKER FOR END: " << *(vec2.end()) << "\n";

	std::vector<int>::iterator	it = vec.begin();
	ft::vector<int>::iterator	it2 = vec2.begin();

	//std::cout << "position after erase at: " << *vec2.erase(vec2.begin() + 1) << "\n";
	std::cout << "position after erase at: " << *vec.erase(vec.begin() + 1) << "\n";
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

	std::cout << "-------- Separator --------\n";

	std::cout << "Main function\n";
	return 0;
}
