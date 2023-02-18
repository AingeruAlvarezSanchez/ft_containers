#ifndef BST_HPP
#define BST_HPP
#include "pair.hpp"

#define BLACK	0
#define RED		1

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

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<RedBlackTreeNode<Key, T> > >
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

		~BinarySearchTree() {
			this->clearTree(this->_root);
		}

		/* Create a default red black tree node */
		RedBlackNode*	createNode(const key_type& key, const value_type& val) {
			RedBlackNode	*newNode = this->_alloc.allocate(1);
			this->_alloc.construct(newNode, RedBlackNode(ft::make_pair(key, val)));
			return newNode;
		}

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

		/* Clear the Tree */
		RedBlackNode*	clearTree(RedBlackNode* root) {
			if (root == NULL) {
				return NULL;
			}
			clearTree(root->_right);
			clearTree(root->_left);
			this->_alloc.destroy(root);
			this->_alloc.deallocate(root, 1);
			root = NULL;
			return root;
		}

		/* Getters */
		RedBlackNode*	getRoot() const {
			return this->_root;
		}
	};
}

#endif //BST_HPP
