#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <iostream>
#include "pair.hpp"
#include "make_pair.hpp"
#include "Rbt.hpp"

int	main() {
	ft::RedBlackTree<int, std::string>	rbt;
	ft::RedBlackTreeNode<int, std::string>	*node;
	ft::RedBlackTreeNode<int, std::string>	*node2;
	ft::RedBlackTreeNode<int, std::string>	*node4;
	ft::RedBlackTreeNode<int, std::string>	*node5;
	ft::RedBlackTreeNode<int, std::string>	*node6;


	node = rbt.insertNode(1, "string1", rbt.getRoot());
	node2 = rbt.insertNode(2, "string2", rbt.getRoot());
	node4 = rbt.insertNode(4, "string4", rbt.getRoot());
	node5 = rbt.insertNode(5, "string5", rbt.getRoot());
	node6 = rbt.insertNode(6, "string6", rbt.getRoot());

	std::cout << "node " << rbt.findNode(5, rbt.getRoot())->_parent->_value._first << " content: " << rbt.findNode(5, rbt.getRoot())->_parent->_value._second << "\n";

	return 0;
}
