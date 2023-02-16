#ifndef RBTNODE_HPP
#define RBTNODE_HPP
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
	};

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<RedBlackTreeNode<Key, T> > >
	class RedBlackTree {
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
		RedBlackTree() : _root(0) {}

		/* Create a default red black tree node */
		RedBlackNode*	createNode(const key_type& key, const value_type& val) {
			RedBlackNode	*RedBlackNode = this->_alloc.allocate(1);
			RedBlackNode->_parent = NULL;
			RedBlackNode->_left = NULL;
			RedBlackNode->_right = NULL;
			RedBlackNode->_value = ft::make_pair(key, val);
			RedBlackNode->_color = RED;
			return RedBlackNode;
		}

		RedBlackNode*	findNode(const key_type& key, RedBlackNode* TreeNode) {
			while (TreeNode != NULL && TreeNode->_value._first != key) {
				if (TreeNode->_value._first == key) {
					return TreeNode;
				}
				else if (this->_comp(key, TreeNode->_value._first)) {
					TreeNode = TreeNode->_left;
				}
				else
					TreeNode = TreeNode->_right;
			}
			return TreeNode;
		}

		RedBlackNode*	insertNode(const key_type& key, const value_type& val, RedBlackNode* TreeNode) {
			if (this->_root == NULL) {
				return this->_root = createNode(key, val);
			}
			if (this->_comp(TreeNode->_value._first, key)) {
				if (TreeNode->_right == NULL) {
					TreeNode->_right = createNode(key, val);
					TreeNode->_right->_parent = TreeNode;
				}
				else
					return TreeNode->_right = insertNode(key, val, TreeNode->_right);
			}
			else if (TreeNode->_value._first > key) {
				if (TreeNode->_left == NULL) {
					TreeNode->_left = createNode(key, val);
					TreeNode->_left->_parent = TreeNode;
				}
				else
					return TreeNode->_left = insertNode(key, val, TreeNode->_left);
			}
			return TreeNode;
		}

		/* Getters */
		RedBlackNode*	getRoot() const {
			return this->_root;
		}
	};
}

#endif //RBTNODE_HPP
