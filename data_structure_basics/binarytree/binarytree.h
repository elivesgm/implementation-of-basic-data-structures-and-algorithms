//

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_


namespace data_structure_basics {

template <class Type>
class BinaryTree {
private:
	struct Node {
		Node *left, *right;
		Type data;

		Node () : left(NULL), right (NULL) {}
		Node (const Type &item, l = NULL, r = NULL) : data(item), left(l), right(r) {}
		~Node () {}
	};

	Node *root;

public:
	BinaryTree() : root(NULL) {}
	BinaryTree(const Type & value) {root->data = value;}
	~BinaryTree(){clear();}

	Type getRoot() const {return root->data;}
	Type getLeft() const {return root->left->data;}
	Type getRight() const {return root->right->data;}

	void maketree(const Type& x, BinaryTree& lt, BinaryTree& rt) {
		root = new Node(x, lt.root, rt.root);
		lt.root = NULL;
		rt.root = NULL;
	}

	void preOrder() const {
		if (root) {
			cout << "PreOder: \n";
			preOder(root);
		}
	}

	void inOrder() const {
		if (root) {
			cout << "InOrder: \n";
			inOrder(root);
		}
	}

	void postOrder() const {
		if (root) {
			cout << "postOrder: \n";
			postOrder(root);
		}
	}
private:
	void preOder(Node* t){
		if (t) {
			cout << t->data << " ";
			preOder(t->left);
			preOder(t->right);
		}
	}

	void inOrder(Node* t) {
		if (t) {
			inOrder(t->left);
			cout << t->data <<" ";
			inOrder(t->right);
		}
	}

	void postOrder(Node* t) {
		if (t) {
			postOrder(t->left);
			postOrder(t->right);
			cout << t->data << " ";
		}
	}
};


} // namespace data_structure_basics


#endif