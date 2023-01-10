# define END	"\033[0;0m"
# define RED	"\e[1;91m"
# define GREEN	"\e[1;92m"
# define YELLOW "\e[1;93m"
# define BLUE	"\e[1;94m"
# define WHITE	"\e[1;97m"

//TODO preprocessor indentation
#include <iostream>
#include <vector>
#include "vector.hpp"

int main(void) {
#ifndef STL
	{
		std::cout << "VECTOR TESTS" << std::endl;
		{
			std::cout << "DEFAULT CONSTRUCTION" << std::endl;
			ft::vector<char>	myVec;
			std::cout << "Vector's size     -> " << myVec.size() << std::endl;
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
		}
		{
			std::cout << "FILL CONSTRUCTION" << std::endl;
			ft::vector<char>	myVec(5, 'A');
			std::cout << "Vector's size     -> " << myVec.size() << std::endl;
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
		}
		{
			std::cout << "RANGE CONSTRUCTION" << std::endl;
			ft::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			ft::vector<char>::iterator	begin = myVec.begin() + 2;
			ft::vector<char>::iterator	end = myVec.end() - 1;
			std::cout << "Vector's size     -> " << myVec.size() << std::endl;
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::cout << "--------------------------" << std::endl;
			ft::vector<char>	range(begin, end);
			std::cout << "Range vector's size     -> " << range.size() << std::endl;
			std::cout << "Range vector's capacity -> " << range.size() << std::endl;
			std::cout << "Range vector's content: " << std::endl;
			for (long unsigned int i = 0; i < range.size(); i++)
				std::cout << "pos [" << i << "]: " << range.at(i) << std::endl;
		}
		{
			std::cout << "COPY CONSTRUCTION" << std::endl;
			ft::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's size     -> " << myVec.size() << std::endl;
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::cout << "--------------------------" << std::endl;
			ft::vector<char>	copy(myVec);
			std::cout << "Copy vector's size     -> " << copy.size() << std::endl;
			std::cout << "Copy vector's capacity -> " << copy.size() << std::endl;
			std::cout << "Copy vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << copy.at(i) << std::endl;
		}
		{
			std::cout << "VECTOR OPERATOR= OVERLOAD" << std::endl;
			ft::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's size     -> " << myVec.size() << std::endl;
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::cout << "--------------------------" << std::endl;
			ft::vector<char>	copy = myVec;
			std::cout << "Copy vector's size     -> " << copy.size() << std::endl;
			std::cout << "Copy vector's capacity -> " << copy.size() << std::endl;
			std::cout << "Copy vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << copy.at(i) << std::endl;
		}
		{
			std::cout << "VECTOR BEGIN FUNCTION" << std::endl;
			ft::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Content of the first pos of the vector: " << *myVec.begin() << std::endl;
		}
		{
			std::cout << "VECTOR END FUNCTION" << std::endl;
			ft::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Content of the last iterable pos of the vector: " << *(--myVec.end()) << std::endl;
		}
		{
			std::cout << "VECTOR RBEGIN FUNCTION" << std::endl;
			ft::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Content of the first value pointed by rbegin: " << *myVec.rbegin() << std::endl;
		}
		{
			std::cout << "VECTOR REND FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Content of the fist iterable value pointed by rend: " << *(--myVec.rend()) << std::endl;
		}
		{
			std::cout << "VECTOR SIZE FUNCTION" << std::endl;
			std::vector<char>	myVec(5, 'A');
			std::cout << "Vector's size -> " << myVec.size() << std::endl;
		}
		{
			std::cout << "VECTOR MAX_SIZE FUNCTION" << std::endl;
			std::vector<char>		myVecChar(1, 'A');
			std::vector<short>		myVecShort(1, 'A');
			std::vector<int>		myVecInt(1, 'A');
			std::vector<long long>	myVecLL(1, 'A');
			std::cout << "Char vector's max_size -> " << myVecChar.max_size() << std::endl;
			std::cout << "Short vector's max_size -> " << myVecShort.max_size() << std::endl;
			std::cout << "Int vector's max_size -> " << myVecInt.max_size() << std::endl;
			std::cout << "Long long vector's max_size -> " << myVecLL.max_size() << std::endl;
		}
		{
			std::cout << "VECTOR RESIZE FUNCTION" << std::endl;
			std::vector<char>	myVec(5, 'A');
			myVec.resize(2, 'B');
			std::cout << "Vector's size after resizing to erase elements -> " << myVec.size() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (long unsigned int i = 0; i < myVec.size(); i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::cout << "-----------------------" << std::endl;
			myVec.resize(5, 'B');
			std::cout << "Vector's size after resizing to add elements -> " << myVec.size() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (long unsigned int i = 0; i < myVec.size(); i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
		}
		{
			std::cout << "VECTOR CAPACITY FUNCTION" << std::endl;
			std::vector<char>	myVec(2, 'A');
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
			std::cout << "Vector's capacity exponential growth: " << std::endl;
			for (int i = 0; i < 10; i++)
			{
				if (myVec.size() + 1 > myVec.capacity())
					std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
				myVec.push_back('A');
			}
		}
		{
			std::cout << "VECTOR EMPTY FUNCTION" << std::endl;
			std::vector<char>	myVec;
			std::cout << "Vector's empty function on an empty vector -> " << myVec.empty() << std::endl;
			myVec.push_back(1);
			std::cout << "Vector's empty function on filled vector   -> " << myVec.empty() << std::endl;
		}
		{
			std::cout << "VECTOR RESERVE FUNCTION" << std::endl;
			std::vector<char>	myVec;
			std::cout << "Vector's capacity before reserve -> " << myVec.capacity() << std::endl;
			myVec.reserve(3);
			std::cout << "Vector's capacity after reserve  -> " << myVec.capacity() << std::endl;
		}
		{
			std::cout << "VECTOR OPERATOR[] OVERLOAD" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's 4th position content -> " << myVec.at(3) << std::endl;
		}
		{
			std::cout << "VECTOR FRONT FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's front position content -> " << myVec.front() << std::endl;
		}
		{
			std::cout << "VECTOR BACK FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's back position content -> " << myVec.back() << std::endl;
		}
		{
			std::cout << "VECTOR DATA FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's first element before advancing the pointer -> " << myVec.at(0) << std::endl;
			++(*myVec.data());
			std::cout << "Vector's first element after advancing the pointer  -> " << myVec.at(0) << std::endl;
		}
		{
			std::cout << "VECTOR ASSIGN FUNCTIONS" << std::endl;
			{
				std::cout << "VECTOR ITERATOR ASSIGN FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's size     -> " << myVec.size() << std::endl;
				std::cout << "Vector's content: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				std::vector<char>::iterator	begin = myVec.begin();
				std::vector<char>::iterator	end = myVec.end();
				std::vector<char>	assignVec(3, 'A');
				std::cout << "Assign vector's size before assign -> " << assignVec.size() << std::endl;
				std::cout << "Assign vector's content before assign: " << std::endl;
				for (int i = 0; i < 3; i++)
					std::cout << "pos [" << i << "]: " << assignVec.at(i) << std::endl;
				assignVec.assign(begin, end);
				std::cout << "Assign vector's size after assign -> " << assignVec.size() << std::endl;
				std::cout << "assign vector's content after assign: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << assignVec.at(i) << std::endl;
			}
			{
				std::cout << "VECTOR FILL ASSIGN FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's size before assign -> " << myVec.size() << std::endl;
				std::cout << "Vector's content: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				myVec.assign(2, 'B');
				std::cout << "Vector's size after assign -> " << myVec.size() << std::endl;
				std::cout << "Vector's content: " << std::endl;
				for (int i = 0; i < 2; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			}
		}
		{
			std::cout << "VECTOR PUSH_BACK FUNCTION" << std::endl;
			std::vector<char>	myVec;
			std::cout << "Vector's size before push_back -> " << myVec.size() << std::endl;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's size after a 5 loop push_back -> " << myVec.size() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
		}
		{
			std::cout << "VECTOR POP_BACK FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's size before pop_back -> " << myVec.size() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			myVec.pop_back();
			std::cout << "Vector's size after pop_back -> " << myVec.size() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 4; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
		}
		{
			std::cout << "VECTOR INSERT FUNCTIONS" << std::endl;
			{
				std::cout << "VECTOR POS AND IT INSERT FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's content before insert: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				myVec.insert(myVec.begin() + 1, 'Z');
				std::cout << "Vector's content after insert: " << std::endl;
				for (int i = 0; i < 6; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			}
			{
				std::cout << "VECTOR POS, IT AND COUNT INSERT FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's content before insert: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				myVec.insert(myVec.begin() + 1, 3, 'Z');
				std::cout << "Vector's content after insert: " << std::endl;
				for (long unsigned int i = 0; i < myVec.size(); i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			}
			{
				std::cout << "VECTOR ITERATOR RANGE INSERT FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(48 + i);
				std::cout << "Vector's content: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				std::vector<char>::iterator	begin = myVec.begin();
				std::vector<char>::iterator	end = myVec.end() - 3;
				std::vector<char>	insertVec;
				for (int i = 0; i < 5; i++)
					insertVec.push_back(97 + i);
				std::cout << "Insert vector's before content: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << insertVec.at(i) << std::endl;
				insertVec.insert(insertVec.begin() + 2, begin, end);
				std::cout << "Insert vector's after content: " << std::endl;
				for (long unsigned int i = 0; i < insertVec.size(); i++)
					std::cout << "pos [" << i << "]: " << insertVec.at(i) << std::endl;
			}
		}
		{
			std::cout << "VECTOR ERASE FUNCTION" << std::endl;
			{
				std::cout << "VECTOR POS ERASE FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's content before erase: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				myVec.erase(myVec.begin() + 2);
				std::cout << "Vector's content after erase: " << std::endl;
				for (long unsigned int i = 0; i < myVec.size(); i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			}
			{
				std::cout << "VECTOR RANGE ERASE FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's content before erase: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				std::cout << "Vector's content after erase: " << std::endl;
				myVec.erase(myVec.begin() + 1, myVec.end() - 2);
				for (long unsigned int i = 0; i < myVec.size(); i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			}
		}
		{
			std::cout << "VECTOR SWAP FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's content before swap: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::vector<char>	swapVec;
			for (int i = 0; i < 5; i++)
				swapVec.push_back(48 + i);
			std::cout << "Swap vector's content before swap: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << swapVec.at(i) << std::endl;
			std::vector<char>::iterator	myVecIt = myVec.begin();
			std::vector<char>::iterator	swapVecIt = swapVec.begin();
			std::cout << "Vector's begin iterator content before swap -> " << *myVecIt << std::endl;
			std::cout << "Swap vector's begin iterator content before swap -> " << *swapVecIt << std::endl;
			std::cout << "------------------------------" << std::endl;
			myVec.swap(swapVec);
			std::cout << "Vector's content after swap: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::cout << "Swap vector's content after swap: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << swapVec.at(i) << std::endl;
			std::cout << "Vector's begin iterator content after swap -> " << *myVecIt << std::endl;
			std::cout << "Swap vector's begin iterator content after swap -> " << *swapVecIt << std::endl;
		}
		{
			std::cout << "VECTOR CLEAR FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 3; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's size before clear -> " << myVec.size() << std::endl;
			myVec.clear();
			std::cout << "Vector's size after clear  -> " << myVec.size() << std::endl;
		}
	}
#else
	{
		std::cout << "VECTOR TESTS" << std::endl;
		{
			std::cout << "DEFAULT CONSTRUCTION" << std::endl;
			std::vector<char>	myVec;
			std::cout << "Vector's size     -> " << myVec.size() << std::endl;
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
		}
		{
			std::cout << "FILL CONSTRUCTION" << std::endl;
			std::vector<char>	myVec(5, 'A');
			std::cout << "Vector's size     -> " << myVec.size() << std::endl;
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
		}
		{
			std::cout << "RANGE CONSTRUCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::vector<char>::iterator	begin = myVec.begin() + 2;
			std::vector<char>::iterator	end = myVec.end() - 1;
			std::cout << "Vector's size     -> " << myVec.size() << std::endl;
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::cout << "--------------------------" << std::endl;
			std::vector<char>	range(begin, end);
			std::cout << "Range vector's size     -> " << range.size() << std::endl;
			std::cout << "Range vector's capacity -> " << range.size() << std::endl;
			std::cout << "Range vector's content: " << std::endl;
			for (long unsigned int i = 0; i < range.size(); i++)
				std::cout << "pos [" << i << "]: " << range.at(i) << std::endl;
		}
		{
			std::cout << "COPY CONSTRUCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's size     -> " << myVec.size() << std::endl;
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::cout << "--------------------------" << std::endl;
			std::vector<char>	copy(myVec);
			std::cout << "Copy vector's size     -> " << copy.size() << std::endl;
			std::cout << "Copy vector's capacity -> " << copy.size() << std::endl;
			std::cout << "Copy vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << copy.at(i) << std::endl;
		}
		{
			std::cout << "VECTOR OPERATOR= OVERLOAD" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's size     -> " << myVec.size() << std::endl;
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::cout << "--------------------------" << std::endl;
			std::vector<char>	copy = myVec;
			std::cout << "Copy vector's size     -> " << copy.size() << std::endl;
			std::cout << "Copy vector's capacity -> " << copy.size() << std::endl;
			std::cout << "Copy vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << copy.at(i) << std::endl;
		}
		{
			std::cout << "VECTOR BEGIN FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Content of the first pos of the vector: " << *myVec.begin() << std::endl;
		}
		{
			std::cout << "VECTOR END FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Content of the last iterable pos of the vector: " << *(--myVec.end()) << std::endl;
		}
		{
			std::cout << "VECTOR RBEGIN FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Content of the first value pointed by rbegin: " << *myVec.rbegin() << std::endl;
		}
		{
			std::cout << "VECTOR REND FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Content of the fist iterable value pointed by rend: " << *(--myVec.rend()) << std::endl;
		}
		/*{
			//TODO should create tests for constant iterators ??
		}*/
		{
			std::cout << "VECTOR SIZE FUNCTION" << std::endl;
			std::vector<char>	myVec(5, 'A');
			std::cout << "Vector's size -> " << myVec.size() << std::endl;
		}
		{
			std::cout << "VECTOR MAX_SIZE FUNCTION" << std::endl;
			std::vector<char>		myVecChar(1, 'A');
			std::vector<short>		myVecShort(1, 'A');
			std::vector<int>		myVecInt(1, 'A');
			std::vector<long long>	myVecLL(1, 'A');
			std::cout << "Char vector's max_size -> " << myVecChar.max_size() << std::endl;
			std::cout << "Short vector's max_size -> " << myVecShort.max_size() << std::endl;
			std::cout << "Int vector's max_size -> " << myVecInt.max_size() << std::endl;
			std::cout << "Long long vector's max_size -> " << myVecLL.max_size() << std::endl;
		}
		{
			std::cout << "VECTOR RESIZE FUNCTION" << std::endl;
			std::vector<char>	myVec(5, 'A');
			myVec.resize(2, 'B');
			std::cout << "Vector's size after resizing to erase elements -> " << myVec.size() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (long unsigned int i = 0; i < myVec.size(); i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::cout << "-----------------------" << std::endl;
			myVec.resize(5, 'B');
			std::cout << "Vector's size after resizing to add elements -> " << myVec.size() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (long unsigned int i = 0; i < myVec.size(); i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
		}
		{
			std::cout << "VECTOR CAPACITY FUNCTION" << std::endl;
			std::vector<char>	myVec(2, 'A');
			std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
			std::cout << "Vector's capacity exponential growth: " << std::endl;
			for (int i = 0; i < 10; i++)
			{
				if (myVec.size() + 1 > myVec.capacity())
					std::cout << "Vector's capacity -> " << myVec.capacity() << std::endl;
				myVec.push_back('A');
			}
		}
		{
			std::cout << "VECTOR EMPTY FUNCTION" << std::endl;
			std::vector<char>	myVec;
			std::cout << "Vector's empty function on an empty vector -> " << myVec.empty() << std::endl;
			myVec.push_back(1);
			std::cout << "Vector's empty function on filled vector   -> " << myVec.empty() << std::endl;
		}
		{
			std::cout << "VECTOR RESERVE FUNCTION" << std::endl;
			std::vector<char>	myVec;
			std::cout << "Vector's capacity before reserve -> " << myVec.capacity() << std::endl;
			myVec.reserve(3);
			std::cout << "Vector's capacity after reserve  -> " << myVec.capacity() << std::endl;
		}
		{
			std::cout << "VECTOR OPERATOR[] OVERLOAD" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's 4th position content -> " << myVec.at(3) << std::endl;
		}
		{
			std::cout << "VECTOR FRONT FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's front position content -> " << myVec.front() << std::endl;
		}
		{
			std::cout << "VECTOR BACK FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's back position content -> " << myVec.back() << std::endl;
		}
		{
			std::cout << "VECTOR DATA FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's first element before advancing the pointer -> " << myVec.at(0) << std::endl;
			++(*myVec.data());
			std::cout << "Vector's first element after advancing the pointer  -> " << myVec.at(0) << std::endl;
		}
		{
			std::cout << "VECTOR ASSIGN FUNCTIONS" << std::endl;
			{
				std::cout << "VECTOR ITERATOR ASSIGN FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's size     -> " << myVec.size() << std::endl;
				std::cout << "Vector's content: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				std::vector<char>::iterator	begin = myVec.begin();
				std::vector<char>::iterator	end = myVec.end();
				std::vector<char>	assignVec(3, 'A');
				std::cout << "Assign vector's size before assign -> " << assignVec.size() << std::endl;
				std::cout << "Assign vector's content before assign: " << std::endl;
				for (int i = 0; i < 3; i++)
					std::cout << "pos [" << i << "]: " << assignVec.at(i) << std::endl;
				assignVec.assign(begin, end);
				std::cout << "Assign vector's size after assign -> " << assignVec.size() << std::endl;
				std::cout << "assign vector's content after assign: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << assignVec.at(i) << std::endl;
			}
			{
				std::cout << "VECTOR FILL ASSIGN FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's size before assign -> " << myVec.size() << std::endl;
				std::cout << "Vector's content: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				myVec.assign(2, 'B');
				std::cout << "Vector's size after assign -> " << myVec.size() << std::endl;
				std::cout << "Vector's content: " << std::endl;
				for (int i = 0; i < 2; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			}
		}
		{
			std::cout << "VECTOR PUSH_BACK FUNCTION" << std::endl;
			std::vector<char>	myVec;
			std::cout << "Vector's size before push_back -> " << myVec.size() << std::endl;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's size after a 5 loop push_back -> " << myVec.size() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
		}
		{
			std::cout << "VECTOR POP_BACK FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's size before pop_back -> " << myVec.size() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			myVec.pop_back();
			std::cout << "Vector's size after pop_back -> " << myVec.size() << std::endl;
			std::cout << "Vector's content: " << std::endl;
			for (int i = 0; i < 4; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
		}
		{
			std::cout << "VECTOR INSERT FUNCTIONS" << std::endl;
			{
				std::cout << "VECTOR POS AND IT INSERT FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's content before insert: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				myVec.insert(myVec.begin() + 1, 'Z');
				std::cout << "Vector's content after insert: " << std::endl;
				for (int i = 0; i < 6; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			}
			{
				std::cout << "VECTOR POS, IT AND COUNT INSERT FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's content before insert: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				myVec.insert(myVec.begin() + 1, 3, 'Z');
				std::cout << "Vector's content after insert: " << std::endl;
				for (long unsigned int i = 0; i < myVec.size(); i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			}
			{
				std::cout << "VECTOR ITERATOR RANGE INSERT FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(48 + i);
				std::cout << "Vector's content: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				std::vector<char>::iterator	begin = myVec.begin();
				std::vector<char>::iterator	end = myVec.end() - 3;
				std::vector<char>	insertVec;
				for (int i = 0; i < 5; i++)
					insertVec.push_back(97 + i);
				std::cout << "Insert vector's before content: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << insertVec.at(i) << std::endl;
				insertVec.insert(insertVec.begin() + 2, begin, end);
				std::cout << "Insert vector's after content: " << std::endl;
				for (long unsigned int i = 0; i < insertVec.size(); i++)
					std::cout << "pos [" << i << "]: " << insertVec.at(i) << std::endl;
			}
		}
		{
			std::cout << "VECTOR ERASE FUNCTION" << std::endl;
			{
				std::cout << "VECTOR POS ERASE FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's content before erase: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				myVec.erase(myVec.begin() + 2);
				std::cout << "Vector's content after erase: " << std::endl;
				for (long unsigned int i = 0; i < myVec.size(); i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			}
			{
				std::cout << "VECTOR RANGE ERASE FUNCTION" << std::endl;
				std::vector<char>	myVec;
				for (int i = 0; i < 5; i++)
					myVec.push_back(97 + i);
				std::cout << "Vector's content before erase: " << std::endl;
				for (int i = 0; i < 5; i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
				std::cout << "Vector's content after erase: " << std::endl;
				myVec.erase(myVec.begin() + 1, myVec.end() - 2);
				for (long unsigned int i = 0; i < myVec.size(); i++)
					std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			}
		}
		{
			std::cout << "VECTOR SWAP FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 5; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's content before swap: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::vector<char>	swapVec;
			for (int i = 0; i < 5; i++)
				swapVec.push_back(48 + i);
			std::cout << "Swap vector's content before swap: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << swapVec.at(i) << std::endl;
			std::vector<char>::iterator	myVecIt = myVec.begin();
			std::vector<char>::iterator	swapVecIt = swapVec.begin();
			std::cout << "Vector's begin iterator content before swap -> " << *myVecIt << std::endl;
			std::cout << "Swap vector's begin iterator content before swap -> " << *swapVecIt << std::endl;
			std::cout << "------------------------------" << std::endl;
			myVec.swap(swapVec);
			std::cout << "Vector's content after swap: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << myVec.at(i) << std::endl;
			std::cout << "Swap vector's content after swap: " << std::endl;
			for (int i = 0; i < 5; i++)
				std::cout << "pos [" << i << "]: " << swapVec.at(i) << std::endl;
			std::cout << "Vector's begin iterator content after swap -> " << *myVecIt << std::endl;
			std::cout << "Swap vector's begin iterator content after swap -> " << *swapVecIt << std::endl;
		}
		{
			std::cout << "VECTOR CLEAR FUNCTION" << std::endl;
			std::vector<char>	myVec;
			for (int i = 0; i < 3; i++)
				myVec.push_back(97 + i);
			std::cout << "Vector's size before clear -> " << myVec.size() << std::endl;
			myVec.clear();
			std::cout << "Vector's size after clear  -> " << myVec.size() << std::endl;
		}
	}
#endif
	return 0;
}
