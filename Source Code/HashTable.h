#include "DoublyLinkedList.h"
#include "Student.h"
#include <sstream>
#include <fstream>
#include "MaxHeap.h"

using namespace std;

class HashTable {
	int Capacity;
	DoublyLinkedList<Student> * Table;

public:

	// Constructor
	HashTable(int Capacity) {
		this->Capacity = Capacity;
		Table = new DoublyLinkedList<Student>[Capacity];
	}

	// Hash Function
	int hashFunction(string Key) {
		int hashVal = 0, len = Key.length();
		for (int i = 0; i<len; i++) {
			hashVal += Key[i];
		}
		return hashVal % Capacity;
	}

	// Void Insert Data
	void insert(Student Data) {
		int Index = hashFunction(Data.getEmail());

		// We then have to check whether a same email account is created or not
		Node<Student> * Head = Table[Index].getHead();
		while (Head != NULL)
		{
			if (Head->getData().getEmail() == Data.getEmail()) {
				cout << "Same email account is already created !" << endl;
				return;
			}
			Head = Head->getNext();
		}

		// We use chaining to solve the problem of collision of same indexs
		Table[Index].Insert(Data);

		cout << "New Record is Added !" << endl;
	}

	int Login(string Email , string Password) {
		int Index = hashFunction(Email);
		Node<Student> * Head = Table[Index].getHead();
		while (Head != NULL)
		{
			if (Head->getData().getEmail() == Email && Head->getData().getPassword() == Password) {
				return 1;
			}
			Head = Head->getNext();
		}
		return 0;
	}

	// Display the Data from Key
	int Display(string Key) {
		int Index = hashFunction(Key);
		Node<Student> * Head = Table[Index].getHead();
		while (Head != NULL)
		{
			if (Head->getData().getEmail() == Key) {
				Head->getData().Display();
				return 1;
			}
			Head = Head->getNext();
		}
		return 0;
	}


	// Read all the Data from the File
	void Read() {
		ifstream input;
		input.open("Data.txt");

		string Name;
		string Email;
		string Password;
		string Class;
		int Date;
		int Month;
		int Year;
		int Hour;
		int Minute;
		string Description;
		int YearEvent;
		string Temp;

		while (getline(input,Name))
		{
			// Get the Student Info
			getline(input, Email);
			getline(input, Password);
			input >> Class;
			input >> Year;
			getline(input, Temp);
			Student(Name, Email, Password, Class, Year).Display();
			cout << endl;
			insert(Student(Name, Email, Password, Class, Year));
			cout << endl;

			input >> Temp;

			// Get the Events from the Records
			while (Temp != "...")
			{
				input >> Date;
				input >> Month;
				input >> YearEvent;
				input >> Hour;
				input >> Minute;
				getline(input, Description , '"');
				input >> Temp;
				input >> Temp;

				Event(Date, Month, Year, Hour, Minute, Description).Display();
				cout << endl;
				

			}

			getline(input, Temp);
			cout << Temp << endl;
			getline(input, Temp);

			cout << endl << endl;

		}

	}

	// Store the Data to a File
	void Write() {
		ofstream output;
		output.open("Data.txt", 'w');

		for (int i = 0; i < Capacity; i++)
		{
			if (Table[i].getHead() != NULL) {
				Node<Student> * Head = Table[i].getHead();
				while (Head != NULL)
				{
					Student Data = Head->getData();
					output << Data.getName() << endl;
					output << Data.getEmail() << endl;
					output << Data.getPassword() << endl;
					output << Data.getClass() << " " << Data.getYear() << endl;
					output << endl;

					Head = Head->getNext();
				}
			}
		}

	}
};