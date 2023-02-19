#ifndef BST_HPP
#define BST_HPP
#include "pair.hpp"

#define BLACK	0
#define RED		1

#include <cstdlib>
namespace ft {
	template <class Key, class T>
	struct RedBlackTreeNode {
	public:
		typedef ft::pair<Key, T>		value_type;
		typedef RedBlackTreeNode		RbtNode;
	public:
		value_type	_value;
		bool		_color;
		RbtNode*	_parent;
		RbtNode*	_left;
		RbtNode*	_right;
	public:
		explicit RedBlackTreeNode(const value_type& val)
		: _value(ft::make_pair(val._first, val._second)), _color(RED), _parent(NULL), _left(NULL), _right(NULL) {}

		~RedBlackTreeNode() {}
	};

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<RedBlackTreeNode<Key, T> > > //TODO Ican change it so it takes any BST type
	class BinarySearchTree {
	public:
		typedef Key								key_type;
		typedef T								value_type;
		typedef Compare							key_compare;
		typedef ft::RedBlackTreeNode<Key, T>	RedBlackNode;
	private:
		Alloc			_alloc;
		key_compare		_comp;
		RedBlackNode*	_root;
	public:
		/* Constructors */
		BinarySearchTree()
		: _root(0) {}

		/* Destructor */
		~BinarySearchTree() {
			this->clearTree(this->_root);
		}

		/* Creates a value_initialized red black tree node */
		RedBlackNode*	createNode(const key_type& key, const value_type& val) {
			RedBlackNode	*newNode = this->_alloc.allocate(1);
			this->_alloc.construct(newNode, RedBlackNode(ft::make_pair(key, val)));
			return newNode;
		}

		/* finds a node inside the tree in an iterative way */
		RedBlackNode*	findNode(const key_type& key, RedBlackNode* root) {
			while (root != NULL && root->_value._first != key) {
				if (this->_comp(key, root->_value._first)) {
					root = root->_left;
				} else {
					root = root->_right;
				}
			}
			return root;
		}

		/* Inserts a node in the tree using tail
		 * recursion for stack frames optimization */
		RedBlackNode*	insertNode(const key_type& key, const value_type& val, RedBlackNode* TreeNode) {
			if (this->_root == NULL) {
				this->_root = createNode(key, val);
				return this->_root;
			}
			if (this->_comp(TreeNode->_value._first, key)) {
				if (TreeNode->_right == NULL) {
					TreeNode->_right = createNode(key, val);
					TreeNode->_right->_parent = TreeNode;
				} else {
					return insertNode(key, val, TreeNode->_right);
				}
			}
			else if (TreeNode->_value._first > key) {
				if (TreeNode->_left == NULL) {
					TreeNode->_left = createNode(key, val);
					TreeNode->_left->_parent = TreeNode;
				} else {
					return insertNode(key, val, TreeNode->_left);
				}
			}
			return TreeNode;
		}

		/* Finds the largest key node inside
		 * the left side of the actual node */
		RedBlackNode*	findLeftSideLargest(RedBlackNode* TreeNode) {
			if (TreeNode->_left != NULL)
				TreeNode = TreeNode->_left;
			while (TreeNode->_right != NULL) {
				TreeNode = TreeNode->_right;
			}
			return TreeNode;
		}

		RedBlackNode*	eraseChildlessNode(RedBlackNode*& node) {
			if (node->_parent->_left == node) {
				node->_parent->_left = NULL;
			} else {
				node->_parent->_right = NULL;
			}
			this->deleteNodeMemory(node);
			return node;
		}

		RedBlackNode*	eraseNoLeftSideNode(RedBlackNode*& node) {
			node->_right->_parent = node->_parent;
			if (node->_parent->_left == node) {
				node->_parent->_left = node->_right;
			} else {
				node->_parent->_right = node->_right;
			}
			this->deleteNodeMemory(node);
			return node;
		}

		RedBlackNode*	eraseWithLeftSideNode(RedBlackNode*& node) {
			RedBlackNode* leftLargest = findLeftSideLargest(node);
			if (node->_left == leftLargest) {
				if (node->_right != NULL) {
					leftLargest->_right = node->_right;
					node->_right->_parent = leftLargest;
				}
				leftLargest->_parent = node->_parent;
				if (node->_parent->_left == node) {
					node->_parent->_left = leftLargest;
				} else {
					node->_parent->_right = leftLargest;
				}
				this->deleteNodeMemory(node); //TODO change to before the return
			}
			return leftLargest;
		}

		RedBlackNode*	eraseNode(const key_type& key, RedBlackNode* root) {
			if (root == NULL) {
				return root;
			}
			if (this->_comp(key, root->_value._first)) {
				return eraseNode(key, root->_left);
			}
			if (key > root->_value._first) {
				return eraseNode(key, root->_right);
			}
			if (root == this->_root) {
				this->_root = clearTree(this->_root);
				return this->_root;
			}
			if (root->_left == NULL && root->_right == NULL) { //CASE 1, NODE TO REMOVE HAS NO CHILD
				return root;
				return eraseChildlessNode(root);
			} else if (root->_left != NULL) { //CASE 2, NODE TO REMOVE HAS LEFT CHILD //divide into 2 separate functions
				return eraseWithLeftSideNode(root);
			} else { //CASE 3, NODE TO REMOVE HAS NO LEFT CHILD
				return eraseNoLeftSideNode(root);
			}
			//TODO check std::map for returning right value
			return NULL;
		}

		/* Destroys a node and deallocates it */
		RedBlackNode*	deleteNodeMemory(RedBlackNode*& root) {
			this->_alloc.destroy(root);
			this->_alloc.deallocate(root, 1);
			root = NULL;
			return root;
		}

		/* Clears the Tree and deallocates memory,
		 * memory consumption is O(n) due to inability
		 * to use tail recursion. */
		RedBlackNode*	clearTree(RedBlackNode* root) {
			if (root == NULL) {
				return NULL;
			}
			clearTree(root->_right);
			clearTree(root->_left);
			this->deleteNodeMemory(root);
			return root;
		}

		/* Getters */
		RedBlackNode*	getRoot() const {
			return this->_root;
		}




		//TODO UTIL TO PRINT THE TREE
		void print2DUtil(RedBlackNode* root, int space) {
			if (root == NULL) {
				return ;
			}
			space += 2;
			print2DUtil(root->_right, space);
			std::cout << "\n";
			for (int i = 2; i < space; i++)
				std::cout << " ";
			std::cout << root->_value._first << "\n";
			print2DUtil(root->_left, space);
		}
	};
}

#endif //BST_HPP
