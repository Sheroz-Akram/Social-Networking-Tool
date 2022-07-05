#include <iostream>

using namespace std;

template <typename T>
class Node {
	T Data;
	Node<T> * Next;
	Node<T> * Previous;

public:


	// Send Data to our Contructor that will be Saved in the Node
	Node(T Data) {
		this->Data = Data;
		this->Next = NULL;
		this->Previous = NULL;
	}

	// Setter and Getter

	void setData(T Data) {
		this->Data = Data;
	}

	void setNext(Node<T> * Next) {
		this->Next = Next;
	}

	void setPrevious(Node<T> * Previous) {
		this->Previous = Previous;
	}

	T getData() {
		return Data;
	}

	Node<T> * getNext() {
		return Next;
	}

	Node<T> * getPrevious() {
		return Previous;
	}

};

template <typename T>
class DoublyLinkedList {
	Node<T> * Head;
	Node<T> * Tail;

public:

	// Default Contructor
	DoublyLinkedList() {
		this->Head = NULL;
		this->Tail = NULL;
	}

	// Function to Insert Data into The List
	void Insert(T Data) {
		Node<T> * newNode = new Node<T>(Data);
		
		// In the Case if List is Empty Insert Directly to the Head
		if (Head == NULL) {
			Head = newNode;
			Tail = newNode;
		}

		// In The Case of 1 or more nodes already existed
		else {
			Tail->setNext(newNode);
			newNode->setPrevious(Tail);
			Tail = Tail->getNext();
		}
	}

	// Return Head 
	Node<T> * getHead() {
		return Head;
	}

	void Display(string ErrorMessage) {
		if (Head == NULL) { 
			cout << ErrorMessage << endl;
		}
		else {
			Node<T> * temp = Head;
			while (temp != NULL) {
				temp->Display();
				temp = temp->getNext();
			}
		}
	}
};