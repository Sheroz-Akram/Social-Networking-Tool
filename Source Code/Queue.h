#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

// Make a Queue with Doubly Linked List
template <typename T>
class Queue {
	Node<T> * Head;
	Node<T> * Tail;

public:


	// Default Contructor
	Queue() {
		this->Head = NULL;
		this->Tail = NULL;
	}

	// Insert At Tail Functionality
	void Enqueue(T Data) {
		Node<T> * newNode = new Node<T>(Data);
		if (Head == NULL) {
			Head = Tail = newNode;
		}
		else {
			Tail->setNext(newNode);
			newNode->setPrevious(Tail);
			Tail = Tail->getNext();
		}
	}

	// Find if the Queue is Empty or not
	bool isEmpty() {
		if (Head == NULL) {
			return true;
		}
		return false;
	}

	// Return the Top Element of the Data

	T Top() {
		return Head->getData();
	}

	// Remove from Head Functionality
	void Dequeue() {
		if (Head == NULL) {
			cout << "Queue is Empty  !" << endl;
		}
		else if (Head == Tail) {
			delete Head;
			Head = Tail = NULL;
		}
		else {
			Node<T> * temp = Head;
			Head = Head->getNext();
			Head->setPrevious(NULL);
			delete temp;
		}
	}
};