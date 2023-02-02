#include <vector>
#include "vector.hpp"
#include <iostream>

int	main() {
	std::vector<std::string>	vec(1, "str");
	ft::vector<std::string>	myVec(1,"str");
	ft::vector<std::string>	vec2;

	vec2 = myVec;

	vec.push_back("str2");
	vec.push_back("str3");
	vec.push_back("str4");

	vec2.push_back("str2");
	vec2.push_back("str3");
	vec2.push_back("str4");

	std::vector<std::string>::iterator	it = vec.begin();
	ft::vector<std::string>::iterator	it2 = vec2.begin();

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
