// file: binarytree.h

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include <queue>
#include <stack>

template <class Type>
class BinaryTree {
private:
	struct Node {
		Node *left, *right;
		Type data;

		Node () : left(NULL), right (NULL) {}
		Node (Type item, Node *l = NULL, Node *r = NULL) : data(item), left(l), right(r) {}
		~Node () {}
	};

	struct stNode {
		Node *t;
		int   popTimes;
		stNode (Node *n = NULL) : t(n), popTimes(0) {}
	}; // for non-recursive traverse

	Node *root;

public:
	BinaryTree() : root(NULL) {}
	BinaryTree(const Type & value) {root->data = value;}
	~BinaryTree(){clear();}

	Type getRoot() const {return root->data;}
	Type getLeft() const {return root->left->data;}
	Type getRight() const {return root->right->data;}

	void createTree(Type empty_flag);
	void clear(){if (root){clear(root);}}
	
	void preOrder() const {
		if (root) {
			std::cout << "PreOder: \n";
			preOrder(root);
		}
	}

	void inOrder() const {
		if (root) {
			std::cout << "InOrder: \n";
			inOrder(root);
		}
	}

	void postOrder() const {
		if (root) {
			std::cout << "postOrder: \n";
			postOrder(root);
		}
	}

private:
	void clear(Node* t) {
		if (t) {
			if (t->left) clear(t->left);
			if (t->right) clear(t->right);
			delete t;
		}
	}

#ifdef RECURSIVE_TRANVERSE
	void preOrder(Node* t) const {
		if (t) {
			std::cout << t->data << " ";
			preOder(t->left);
			preOder(t->right);
		}
	}

	void inOrder(Node* t) const {
		if (t) {
			inOrder(t->left);
			std::cout << t->data <<" ";
			inOrder(t->right);
		}
	}

	void postOrder(Node* t) const {
		if (t) {
			postOrder(t->left);
			postOrder(t->right);
			std::cout << t->data << " ";
		}
	}
#else
	void preOrder(Node* t) const ;
	void inOrder(Node* t) const;
	void postOrder(Node* t) const;
#endif
};

template<class Type>
void BinaryTree<Type>::createTree(Type empty_flag) {
	std::queue<Node*> nodeque;
	Node *tmp;
	Type x, ldata, rdata;

	std::cout << "\nPls. enter root: ";
	std::cin >> x;
	root = new Node(x);
	nodeque.push(root);

	while(!nodeque.empty()) {
		tmp = nodeque.front();
		nodeque.pop();
		
		std::cout << "\nPls. enter left and right child of "<< tmp->data << "(empty with " << empty_flag << "): ";
		std::cin >> ldata >> rdata;
		if (ldata != empty_flag) nodeque.push(tmp->left = new Node(ldata));
		if (rdata != empty_flag) nodeque.push(tmp->right = new Node(rdata));
	}
	std::cout << "Create completed!\n";
}

#ifdef RECURSIVE_TRANVERSE
#else
template<class Type>
void BinaryTree<Type>::preOrder(Node *t) const {
	std::stack<Node*> st;
	Node* tmp;

	st.push(t);
	while(!st.empty()) {
		tmp = st.top();
		st.pop();
		std::cout << tmp->data << " ";
		if (tmp->right) st.push(tmp->right);
		if (tmp->left) st.push(tmp->left);
	}
}

template<class Type>
void BinaryTree<Type>::inOrder(Node *t) const {
	std::stack<stNode> st;
	stNode tmp(t);

	st.push(tmp);
	while(!st.empty()) {
		tmp = st.top();
		st.pop();
		if (++tmp.popTimes == 2) {
			std::cout << tmp.t->data << " ";
			if (tmp.t->right) st.push(stNode(tmp.t->right));
		}
		else {
			st.push(tmp);
			if (tmp.t->left) st.push(stNode(tmp.t->left));
		}
	}
}

template<class Type>
void BinaryTree<Type>::postOrder(Node* t) const {
	std::stack<stNode> st;
	stNode tmp(t);

	st.push(tmp);
	while(!st.empty()) {
		tmp = st.top();
		st.pop();
		if (++tmp.popTimes == 3) {
			std::cout << tmp.t->data << " ";
		}
		else if (tmp.popTimes == 2) {
			st.push(tmp);
			if (tmp.t->right) st.push(stNode(tmp.t->right));
		}
		else {
			st.push(tmp);
			if (tmp.t->left) st.push(stNode(tmp.t->left));
		}
	}
}
#endif

#endif