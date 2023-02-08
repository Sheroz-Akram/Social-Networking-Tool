#include <sstream>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

class NodeAVLL {
	string Data;
	NodeAVL * Left;
	NodeAVL * Right;
	int Height;

public:
	NodeAVL(string Data) {
		this->Data = Data;
		this->Left = NULL;
		this->Right = NULL;
		this->Height = 1;
	}

	void setData(string Data) {
		this->Data = Data;
	}

	void setLeft(NodeAVL * Left) {
		this->Left = Left;
	}

	void setRight(NodeAVL * Right) {
		this->Right = Right;
	}

	void setHeight(int Height) {
		this->Height = Height;
	}

	string getData() {
		return Data;
	}

	NodeAVL * getLeft() {
		return Left;
	}

	NodeAVL * getRight() {
		return Right;
	}

	int getHeight() {
		return Height;
	}
};

// Calculate height
int height(NodeAVL * Node) {
	if (Node == NULL) {
		return 0;
	}
	return Node->getHeight();
}


// Need To Be Done
int max(int a, int b) {
	return (a > b) ? a : b;
}

// New node creation
NodeAVL * newNode(string Data) {
	NodeAVL * node = new NodeAVL(Data);
	return node;
}

// Rotate right
NodeAVL * rightRotate(NodeAVL * y) {
	NodeAVL * x = y->getLeft();
	NodeAVL * T2 = x->getRight();
	x->setRight(y);
	y->setLeft(T2);
	y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);
	x->setHeight(max(height(x->getLeft()), height(x->getRight())) + 1);
	return x;
}

// Rotate left
NodeAVL * leftRotate(NodeAVL * x) {
	NodeAVL * y = x->getRight();
	NodeAVL * T2 = y->getLeft();
	y->setLeft(x);
	x->setRight(T2);

	x->setHeight(max(height(x->getLeft()), height(x->getRight())) + 1);
	y->setHeight(max(height(y->getLeft()), height(y->getRight())) + 1);
	return y;
}

// Get the balance factor of each node
int getBalanceFactor(NodeAVL * N) {
	if (N == NULL)
		return 0;
	return height(N->getLeft()) - height(N->getRight());
}

// Insert a node
NodeAVL * insertNode(NodeAVL * node, string key) {
	// Find the correct postion and insert the node
	if (node == NULL)
		return (newNode(key));

	// Means Key is Smaller than node->key
	if (key.compare(node->getData()) < 0)
		node->setLeft(insertNode(node->getLeft(), key));
	else if (key.compare(node->getData()) > 0)
		node->setRight(insertNode(node->getRight(), key));
	else
		return node;

	// Update the balance factor of each node and
	// balance the tree
	node->setHeight(1 + max(height(node->getLeft()), height(node->getRight())));
	int balanceFactor = getBalanceFactor(node);
	if (balanceFactor > 1) {
		if (key.compare(node->getLeft()->getData()) < 0) {
			return rightRotate(node);
		}
		else if (key.compare(node->getLeft()->getData()) > 0) {
			node->setLeft(leftRotate(node->getLeft()));
			return rightRotate(node);
		}
	}
	if (balanceFactor < -1) {
		if (key.compare(node->getRight()->getData()) > 0) {
			return leftRotate(node);
		}
		else if (key.compare(node->getRight()->getData()) < 0) {
			node->setRight(rightRotate(node->getRight()));
			return leftRotate(node);
		}
	}
	return node;
}

// Node with minimum value
NodeAVL * nodeWithMimumValue(NodeAVL * node) {
	NodeAVL * current = node;
	while (current->getLeft() != NULL)
		current = current->getLeft();
	return current;
}

// Delete a node
NodeAVL * deleteNode(NodeAVL * root, string key) {
	
	cout << root->getData() << " " << key << endl;
	// Find the node and delete it
	if (root == NULL)
		cout << "Freind Not Found !" << endl;
		return root;
	if (key.compare(root->getData()) < 0)
		root->setLeft(deleteNode(root->getLeft(), key));
	else if (key.compare(root->getData()) > 0)
		root->setRight(deleteNode(root->getRight(), key));
	else {
		if ((root->getLeft() == NULL) || (root->getRight() == NULL)) {
			NodeAVL * temp = root->getLeft() ? root->getLeft() : root->getRight();
			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else {
			NodeAVL * temp = nodeWithMimumValue(root->getRight());
			root->setData(temp->getData());
			root->setRight(deleteNode(root->getRight(), temp->getData()));
		}
	}

	if (root == NULL)
		cout << "Freind Not Found !" << endl;
		return root;

	// Update the balance factor of each node and
	// balance the tree
	root->setHeight(1 + max(height(root->getLeft()), height(root->getRight())));
	int balanceFactor = getBalanceFactor(root);
	if (balanceFactor > 1) {
		if (getBalanceFactor(root->getLeft()) >= 0) {
			return rightRotate(root);
		}
		else {
			root->setLeft(leftRotate(root->getLeft()));
			return rightRotate(root);
		}
	}
	if (balanceFactor < -1) {
		if (getBalanceFactor(root->getRight()) <= 0) {
			return leftRotate(root);
		}
		else {
			root->setRight(rightRotate(root->getRight()));
			return leftRotate(root);
		}
	}
	return root;
}

// Print the tree
void printTree(NodeAVL *root) {
	ofstream output;
	output.open("Data.txt", ios::app);
	if (root != nullptr) {
		printTree(root->getLeft());
		output << root->getData() << " , ";
		printTree(root->getRight());
	}
}

int i = 1;
// Print All the tree
void printTreeAll(NodeAVL *root) {
	if (root != nullptr) {
		printTreeAll(root->getLeft());
		cout << i << ". " << root->getData() << endl;
		i++;
		printTreeAll(root->getRight());
	}
}

class AVL {
	NodeAVL * Root;

public:

	AVL() {
		this->Root = NULL;
	}

	NodeAVL * getRoot() {
		return Root;
	}

	void Insert(string Data) {
		Root = insertNode(Root, Data);
	}

	void Delete(string Data) {
		Root = deleteNode(Root, Data);
	}

	void Display() {
		printTree(Root);
	}

	void DisplayAll() {
		i = 1;
		printTreeAll(Root);
	}
};
