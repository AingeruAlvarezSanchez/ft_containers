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

	for (unsigned long i = 0; i < vec2.size(); i++)
		std::cout << "MY Content: " << vec2.at(i) << "\n";
	std::cout << "MY capacity: " << vec2.capacity() << "\n";
	std::cout << "MY size: " << vec2.size() << "\n";

	std::cout << "-------- Separator --------\n";

	for (unsigned long i = 0; i < vec.size(); i++)
		std::cout << "Content: " << vec.at(i) << "\n";
	std::cout << "Capacity: " << vec.capacity() << "\n";
	std::cout << "Size: " << vec.size() << "\n";

	std::cout << "-------- Separator --------\n";

	std::cout << "Main function\n";
	return 0;
}
