#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <iostream>
#include "pair.hpp"
#include "make_pair.hpp"
#include "Bst.hpp"

#include <cstdlib>
int	main() {
	ft::BinarySearchTree<int, std::string> rbt;
	ft::RedBlackTreeNode<int, std::string> *node1;
	ft::RedBlackTreeNode<int, std::string> *node2;
	ft::RedBlackTreeNode<int, std::string> *node3;
	ft::RedBlackTreeNode<int, std::string> *node4;
	ft::RedBlackTreeNode<int, std::string> *node5;
	ft::RedBlackTreeNode<int, std::string> *node6;
	ft::RedBlackTreeNode<int, std::string> *node7;
	ft::RedBlackTreeNode<int, std::string> *node0;
	ft::RedBlackTreeNode<int, std::string> *node9;

	/*node9 = rbt.insertNode(9, "string9", rbt.getRoot());
	node5 = rbt.insertNode(5, "string5", rbt.getRoot());
	node7 = rbt.insertNode(7, "string7", rbt.getRoot());
	node3 = rbt.insertNode(3, "string3", rbt.getRoot());
	node1 = rbt.insertNode(1, "string1", rbt.getRoot());
	node2 = rbt.insertNode(2, "string2", rbt.getRoot());
	node4 = rbt.insertNode(4, "string4", rbt.getRoot());
	node6 = rbt.insertNode(6, "string6", rbt.getRoot());
	node0 = rbt.insertNode(0, "string0", rbt.getRoot());*/

	srand(time(NULL));
	for (int i = 0; i < 10000; i++) {
		int key = rand() % 100;
		rbt.insertNode(key, "string", rbt.getRoot());
	}

	std::cout << "PRE ERASE\n";
	std::cout << "------------------ Right side of the tree --------------------\n";
	rbt.print2DUtil(rbt.getRoot(), 0);
	std::cout << "\n------------------ Left side of the tree ---------------------\n\n";
	for (int i = 0; i < 10000; i++) {
		int key = rand() % 100;
		rbt.eraseNode(key, rbt.getRoot());
	}
	//rbt.eraseNode(5, rbt.getRoot());
	std::cout << "POST ERASE\n";
	std::cout << "------------------ Right side of the tree --------------------\n";
	rbt.print2DUtil(rbt.getRoot(), 0);
	std::cout << "\n------------------ Left side of the tree ---------------------\n\n";

	return 0;
}
