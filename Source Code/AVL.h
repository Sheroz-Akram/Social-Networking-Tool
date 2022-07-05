// AVL tree implementation in C++
#include "Event.h"

#include <iostream>
using namespace std;

template <typename T>
class NodeAVL {
	T Key;
	int Height;
	NodeAVL<T> * Left;
	NodeAVL<T> * Right;

public:

	// Contructor
	NodeAVL(T Key) {
		this->Key = Key;
		this->Left = NULL;
		this->Right = NULL;
		this->Height = 1;
	}


	// Setter and getter

	void setKey(T Key) {
		this->Key = Key;
	}

	void setLeft(NodeAVL<T> * Left) {
		this->Left = Left;
	}

	void setRight(NodeAVL<T> * Right) {
		this->Right = Right;
	}

	void setHeight(int Height) {
		this->Height = Height;
	}

	T getKey() {
		return Key;
	}

	NodeAVL<T> * getLeft() {
		return Left;
	}

	NodeAVL<T> * getRight() {
		return Right;
	}

	int getHeight() {
		return Height;
	}

};

int max(int a, int b);

// Calculate height
int height(NodeAVL<Event> * node) {
	if (node == NULL)
		return 0;
	return node->getHeight();
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

// New node creation
NodeAVL<Event> * newNode(Event key) {
	NodeAVL<Event> * node = new NodeAVL<Event>(key);
	return (node);
}

// Rotate right
NodeAVL<Event> * rightRotate(NodeAVL<Event> * y) {
	NodeAVL<Event> * x = y->getLeft();
	NodeAVL<Event> * T2 = x->getRight();
	x->setRight(y);
	y->setLeft(T2);
	y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);
	x->height = max(height(x->left), height(x->right)) + 1;
	return x;
}

// Rotate left
Node *leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;
	y->left = x;
	x->right = T2;
	x->height = max(height(x->left),
		height(x->right)) +
		1;
	y->height = max(height(y->left),
		height(y->right)) +
		1;
	return y;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N) {
	if (N == NULL)
		return 0;
	return height(N->left) -
		height(N->right);
}

// Insert a node
Node* insertNode(Node *node, int key) {
	// Find the correct postion and insert the node
	if (node == NULL)
		return (newNode(key));
	if (key < node->key)
		node->left = insertNode(node->left, key);
	else if (key > node->key)
		node->right = insertNode(node->right, key);
	else
		return node;

	// Update the balance factor of each node and
	// balance the tree
	node->height = 1 + max(height(node->left),
		height(node->right));
	int balanceFactor = getBalanceFactor(node);
	if (balanceFactor > 1) {
		if (key < node->left->key) {
			return rightRotate(node);
		}
		else if (key > node->left->key) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
	}
	if (balanceFactor < -1) {
		if (key > node->right->key) {
			return leftRotate(node);
		}
		else if (key < node->right->key) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
	}
	return node;
}

// Node with minimum value
Node *nodeWithMimumValue(Node *node) {
	Node *current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

// Delete a node
Node *deleteNode(Node *root, int key) {
	// Find the node and delete it
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if ((root->left == NULL) ||
			(root->right == NULL)) {
			Node *temp = root->left ? root->left : root->right;
			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else {
			Node *temp = nodeWithMimumValue(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right,
				temp->key);
		}
	}

	if (root == NULL)
		return root;

	// Update the balance factor of each node and
	// balance the tree
	root->height = 1 + max(height(root->left),
		height(root->right));
	int balanceFactor = getBalanceFactor(root);
	if (balanceFactor > 1) {
		if (getBalanceFactor(root->left) >= 0) {
			return rightRotate(root);
		}
		else {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	if (balanceFactor < -1) {
		if (getBalanceFactor(root->right) <= 0) {
			return leftRotate(root);
		}
		else {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}

// Print the tree
void printTree(Node *root) {
	if (root != nullptr) {
		printTree(root->left);
		cout << root->key << " , ";
		printTree(root->right);
	}
}