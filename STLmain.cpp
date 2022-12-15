#include <iostream>
#include <vector>
# define END	"\033[0;0m"
# define RED	"\e[1;91m"
# define GREEN	"\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE	"\e[1;94m"
# define WHITE	"\e[1;97m"


int main(void) {
	std::cout << WHITE"---------- TESTING VECTOR'S MEMBER FUNCTIONS ----------"END << std::endl;
	{
		std::cout << std::endl << YELLOW"---------- TESTING VECTOR'S CONSTRUCTORS AND DESTRUCTOR ----------"END << std::endl;
		{
			std::cout << "---------- Testing vector's default constructor ----------" << std::endl << std::endl;
			std::vector<char>	myVector;
			std::cout << GREEN"Vector's capacity after creation: "END << std::endl;
			std::cout << myVector.capacity() << std::endl;
			try {
				std::cout << GREEN"Vector's "END WHITE"myVector.at(0)"END GREEN" after creation: "END << std::endl;
				std::cout << myVector.at(0) << std::endl;
			}
			catch (const std::exception& e){
				std::cout << "Exception when accessing myVector.at(0): " << e.what() << std::endl << std::endl;
			}
		}
		{
			std::cout << "---------- Testing vector's size and value defined constructor ----------" << std::endl << std::endl;
			std::vector<std::string>	myVector(5, "someString");
			std::cout << BLUE"Testing Vector's capacity after creation: "END << std::endl;
			std::cout << myVector.capacity() << std::endl;
			std::cout << BLUE"Testing Vector's content after creation: "END << std::endl;
			for (size_t i = 0; i < myVector.size(); i++)
				std::cout << "vector's ["GREEN << i << END"] position after creation is: "WHITE << myVector.at(i) << END << std::endl;
		}
		{
			//TODO the constructor with iterators
		}
		{
			std::cout << "---------- Testing vector's copy constructor ----------" << std::endl << std::endl;
			std::vector<float>	myVector(5, 5.5f);
			std::vector<float>	vectorCopy(myVector);
			std::cout << BLUE"Testing both vectors capacity after creation: "END << std::endl;
			std::cout << "myVector capacity: " << myVector.capacity() << std::endl;
			std::cout << "vectorCopy capacity: " << vectorCopy.capacity() << std::endl;
			std::cout << BLUE"Testing copy vector content after creation: "END << std::endl;
			for (size_t i = 0; i < myVector.size(); i++)
				std::cout << "vector's ["GREEN << i << END"] position after creation is: "WHITE << vectorCopy.at(i) << END << std::endl;
			std::cout << BLUE"Testing both vectors "END << RED"max_size()"END << BLUE" after creation: "END << std::endl;
			std::cout << "myVector maxSize(): "WHITE << myVector.max_size() << END << std::endl;
			std::cout << "vectorCopy maxSize(): "WHITE << vectorCopy.max_size() << END << std::endl;
		}
		{
			std::cout << "---------- Testing vector's operator '=' overload ----------" << std::endl << std::endl;
			std::vector<char>	myVector(5, 'a');
			std::vector<char>	vectorCopy;
			vectorCopy = myVector;
			std::cout << BLUE"Testing both vectors capacity after creation: "END << std::endl;
			std::cout << "myVector capacity: " << myVector.capacity() << std::endl;
			std::cout << "vectorCopy capacity: " << vectorCopy.capacity() << std::endl;
			std::cout << BLUE"Testing copy vector content after creation: "END << std::endl;
			for (size_t i = 0; i < myVector.size(); i++)
				std::cout << "vector's ["GREEN << i << END"] position after creation is: "WHITE << vectorCopy.at(i) << END << std::endl;
			std::cout << BLUE"Testing both vectors "END << RED"max_size()"END << BLUE" after creation: "END << std::endl;
			std::cout << "myVector maxSize(): "WHITE << myVector.max_size() << END << std::endl;
			std::cout << "vectorCopy maxSize(): "WHITE << vectorCopy.max_size() << END << std::endl;
		}
	}
	{
		std::cout << std::endl << YELLOW"---------- TESTING VECTOR'S ITERATORS ----------"END << std::endl;
		{

		}
	}
	{
		std::cout << std::endl << YELLOW"---------- TESTING VECTOR'S CAPACITY ACCESSORS ----------"END << std::endl;
		{

		}
	}
	{
		std::cout << std::endl << YELLOW"---------- TESTING VECTOR'S ELEMENT ACCESSORS ----------"END << std::endl;
		{

		}
	}
	{
		std::cout << std::endl << YELLOW"---------- TESTING VECTOR'S MODIFIERS ----------"END << std::endl;
		{

		}
	}
	{
		std::cout << std::endl << YELLOW"---------- TESTING VECTOR'S ALLOCATOR ----------"END << std::endl;
		{

		}
	}
	std::cout << std::endl << GREEN"---------- TESTING VECTOR'S NON-MEMBER FUNCTIONS ----------"END << std::endl;
	{
		std::cout << std::endl << YELLOW"---------- TESTING VECTOR'S OPERATOR OVERLOADS ----------"END << std::endl;
		{

		}
	}
	return 0;
}
