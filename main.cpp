#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <iostream>

int	main() {
	/*std::stack<int>	stack;
	ft::stack<int>	stack3;
	ft::stack<int>	stack2;

	stack.push(5);
	stack.push(4);
	stack2.push(5);
	stack2.push(4);
	stack.pop();
	stack2.pop();
	//std::cout << "equal compare: " << (stack2 == stack3) << "\n";
	std::cout << "MY equal compare: " << (stack2 == stack3) << "\n";
	std::cout << "OR TOP: " << stack.top() << "\n";
	std::cout << "MY TOP: " << stack2.top() << "\n";

	std::cout << "OR SIZE: " << stack.size() << "\n";
	std::cout << "MY SIZE: " << stack2.size() << "\n";*/
	std::vector<int>	vec3(1, 50);
	std::vector<int>	vec;
	ft::vector<int>	myVec(1,50);
	ft::vector<int>	vec2;

	vec = vec3;
	vec2 = myVec;

	vec.push_back(51);
	vec.push_back(52);
	vec.push_back(53);
	vec3.push_back(51);
	vec3.push_back(52);
	vec3.push_back(53);

	vec2.push_back(51);
	vec2.push_back(52);
	vec2.push_back(53);
	myVec.push_back(51);
	myVec.push_back(52);
	myVec.push_back(53);

	std::vector<int>::iterator	it = vec.begin();
	ft::vector<int>::iterator	it2 = vec2.begin();

	std::cout << "erase result: " << *vec.erase(vec.begin() + 1, vec.end()) << "\n";
	std::cout << "MY erase result: " << *vec2.erase(vec2.begin() + 1, vec2.end()) << "\n";
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
