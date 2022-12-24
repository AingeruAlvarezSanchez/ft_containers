#include "vector.hpp"
# define END	"\033[0;0m"
# define RED	"\e[1;91m"
# define GREEN	"\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE	"\e[1;94m"
# define WHITE	"\e[1;97m"

#include <vector>
int main(void) {
	{
		ft::vector<int>			vec;
		ft::vector<int>::iterator	first;
		ft::vector<int>::iterator	last;

		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << "Content pre insert: " << *it << std::endl;
		first = vec.begin();
		last = vec.end() - 2;
		ft::vector<int>		vec2(first, last);
		std::cout << "--------------------------------" << std::endl;
		for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << "Content post insert: " << *it << std::endl;
	}
	//std::cout << "--------------- ORIGINAL DEBAJO ----------------" << std::endl;
	/*{
		std::vector<int>			vec;
		std::vector<int>::iterator	pos;
		std::vector<int>::iterator	first;
		std::vector<int>::iterator	last;

		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);
		vec.push_back(40);
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << "Content pre insert: " << *it << std::endl;
		pos = vec.begin();
		first = vec.begin();
		last = vec.end() - 1;
		std::cout << "Valor de pos: " << *pos << " Valor de first: " << *first << " Valor de last: " << *last << std::endl;
		vec.insert(pos, pos + 1, pos + 3);
		std::cout << "--------------------------------" << std::endl;
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << "Content post insert: " << *it << std::endl;
	}*/
	/*std::vector<int>			vec;
	std::vector<int>::iterator	pos;
	std::vector<int>::iterator	first;
	std::vector<int>::iterator	last;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	vec.push_back(60);
	vec.push_back(70);
	first = vec.begin() + 1;
	last = vec.end() - 1;
	pos = vec.begin();
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "Content pre insert: " << *it << std::endl;
	vec.insert(pos, first, last);
	std::cout << std::endl << "---------- ORIGINAL -----------" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << "Content post insert: " << *it << std::endl;*/




	//last = vec.end() - 1;
	/*std::vector<int>	myVector;
	myVector.push_back(50);
	//ft::vector<int>::iterator	end = myVector.end();
	//ft::vector<int>::iterator	ins = myVector.begin();
	myVector.push_back(30);
	myVector.push_back(20);
	myVector.push_back(10);
	for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
		std::cout << "Content pre erase: " << *it << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::vector<int>::iterator	it = myVector.begin();
	std::cout << "position pre erase: " << *it << std::endl;
	myVector.erase(it, myVector.end() - 2);
	std::cout << "---------------------------------" << std::endl;
	for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
		std::cout << "Content post erase: " << *it << std::endl;*/
	/*std::cout << WHITE "---------- TESTING VECTOR'S MEMBER FUNCTIONS ----------" END << std::endl;
	{
		std::cout << std::endl << YELLOW "---------- TESTING VECTOR'S CONSTRUCTORS AND DESTRUCTOR ----------" END << std::endl;
		{
			std::cout << "---------- Testing vector's default constructor ----------" << std::endl << std::endl;
			ft::vector<char>	myVector;
			std::cout << GREEN "Vector's capacity after creation: " END << std::endl;
			std::cout << myVector.capacity() << std::endl;
			try {
				std::cout << GREEN "Vector's " END WHITE "myVector.at(0)" END GREEN " after creation: " END << std::endl;
				std::cout << myVector.at(0) << std::endl;
			}
			catch (const std::exception& e) {
				std::cout << "Exception when accessing myVector.at(0): " << e.what() << std::endl << std::endl;
			}
		}
		{
			std::cout << "---------- Testing vector's size and value defined constructor ----------" << std::endl << std::endl;
			ft::vector<std::string>	myVector(5, "someString");
			std::cout << BLUE "Testing Vector's capacity after creation: " END << std::endl;
			std::cout << myVector.capacity() << std::endl;
			std::cout << BLUE "Testing Vector's content after creation: " END << std::endl;
			for (size_t i = 0; i < myVector.size(); i++)
				std::cout << "vector's [" GREEN << i << END "] position after creation is: "WHITE << myVector.at(i) << END << std::endl;
		}
		{
			//TODO the constructor with iterators
		}
		{
			std::cout << "---------- Testing vector's copy constructor ----------" << std::endl << std::endl;
			ft::vector<float>	myVector;
			myVector.push_back(5.5f);
			myVector.push_back(7.5f);
			myVector.push_back(8);
			ft::vector<float>	vectorCopy(myVector);
			std::cout << BLUE "Testing both vectors capacity after creation: " END << std::endl;
			std::cout << "myVector capacity: " << myVector.capacity() << std::endl;
			std::cout << "vectorCopy capacity: " << vectorCopy.capacity() << std::endl;
			std::cout << BLUE "Testing copy vector content after creation: " END << std::endl;
			for (size_t i = 0; i < myVector.size(); i++)
				std::cout << "vector's ["GREEN << i << END"] position after creation is: " WHITE << vectorCopy.at(i) << END << std::endl;
			std::cout << BLUE "Testing both vectors " END << WHITE "max_size()" END << BLUE " after creation: "END << std::endl;
			std::cout << "myVector maxSize(): "WHITE << myVector.max_size() << END << std::endl;
			std::cout << "vectorCopy maxSize(): "WHITE << vectorCopy.max_size() << END << std::endl;
		}
		{
			std::cout << "---------- Testing vector's operator '=' overload ----------" << std::endl << std::endl;
			ft::vector<char>	myVector(5, 'a');
			myVector.at(3) = 'B';
			ft::vector<char>	vectorCopy;
			vectorCopy = myVector;
			std::cout << BLUE "Testing both vectors capacity after creation: " END << std::endl;
			std::cout << "myVector capacity: " << myVector.capacity() << std::endl;
			std::cout << "vectorCopy capacity: " << vectorCopy.capacity() << std::endl;
			std::cout << BLUE "Testing copy vector content after creation: " END << std::endl;
			for (size_t i = 0; i < myVector.size(); i++)
				std::cout << "vector's ["GREEN << i << END"] position after creation is: "WHITE << vectorCopy.at(i) << END << std::endl;
			std::cout << BLUE "Testing both vectors " END << RED "max_size()" END << BLUE " after creation: " END << std::endl;
			std::cout << "myVector maxSize(): " WHITE << myVector.max_size() << END << std::endl;
			std::cout << "vectorCopy maxSize(): " WHITE << vectorCopy.max_size() << END << std::endl;
		}
	}
	{
		std::cout << std::endl << YELLOW "---------- TESTING VECTOR'S ITERATORS ----------" END << std::endl;
		{

		}
	}
	{
		std::cout << std::endl << YELLOW "---------- TESTING VECTOR'S CAPACITY ACCESSORS ----------" END << std::endl;
		{
		}
	}
	{
		std::cout << std::endl << YELLOW "---------- TESTING VECTOR'S ELEMENT ACCESSORS ----------" END << std::endl;
		{

		}
	}
	{
		std::cout << std::endl << YELLOW "---------- TESTING VECTOR'S MODIFIERS ----------" END << std::endl;
		{
			{
				std::cout << "---------- Testing vector's " WHITE << "push_back() " END << "function ----------" << std::endl << std::endl;
				ft::vector<int>	myVector;
				std::cout << GREEN "Vector's capacity after creation: " END << std::endl;
				std::cout << myVector.capacity() << std::endl;
				myVector.push_back(5);
				myVector.push_back(4);
				myVector.push_back(3);
				myVector.push_back(2);
				myVector.push_back(6);
				std::cout << BLUE "Testing vector content after pushing 5 numbers: " END << std::endl;
				for (ft::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++)
					std::cout << "Content: " << *it << std::endl;
				std::cout << BLUE "Testing vector capacity after pushing 5 numbers: " END << std::endl;
				std::cout << "Capacity: " << myVector.capacity() << std::endl;
				std::cout << BLUE "Testing vector size after pushing 5 numbers: " END << std::endl;
				std::cout << "size: " << myVector.size() << std::endl;
			}
		}
	}
	{
		std::cout << std::endl << YELLOW "---------- TESTING VECTOR'S ALLOCATOR ----------" END << std::endl;
		{

		}
	}
	std::cout << std::endl << GREEN "---------- TESTING VECTOR'S NON-MEMBER FUNCTIONS ----------" END << std::endl;
	{
		std::cout << std::endl << YELLOW "---------- TESTING VECTOR'S OPERATOR OVERLOADS ----------" END << std::endl;
		{

		}
	}*/
	return 0;
}
