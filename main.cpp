#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <iostream>
#include "pair.hpp"
#include "make_pair.hpp"
#include "Bst.hpp"

int	main() {
	ft::BinarySearchTree<int, std::string> rbt;
	ft::RedBlackTreeNode<int, std::string> *node;
	ft::RedBlackTreeNode<int, std::string> *node2;
	ft::RedBlackTreeNode<int, std::string> *node4;
	ft::RedBlackTreeNode<int, std::string> *node5;
	ft::RedBlackTreeNode<int, std::string> *node6;


	node4 = rbt.insertNode(4, "string4", rbt.getRoot());
	node = rbt.insertNode(1, "string1", rbt.getRoot())->_parent;
	node2 = rbt.insertNode(2, "string2", rbt.getRoot());
	node5 = rbt.insertNode(5, "string5", rbt.getRoot());
	node6 = rbt.insertNode(6, "string6", rbt.getRoot());

	if (rbt.findNode(4, rbt.getRoot()) != NULL) {
		std::cout << "node: " << rbt.findNode(4, rbt.getRoot())->_value._first << " content: " << rbt.findNode(4, rbt.getRoot())->_value._second << "\n";
	}

	return 0;
}