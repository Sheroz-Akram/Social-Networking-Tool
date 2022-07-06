#include "Student.h"
#include <sstream>
#include <fstream>

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

	// Add a new Post to Time Line
	void AddPost(string Email, string Post) {
		int Index = hashFunction(Email);
		Node<Student> * Head = Table[Index].getHead();
		while (Head != NULL)
		{
			if (Head->getData().getEmail() == Email) {
				Student newData = Head->getData();
				newData.NewPost(Post);
				cout << "New Post is Added to Time line !" << endl;
				Head->setData(newData);
				system("pause");
				return;
			}
			Head = Head->getNext();
		}
		cout << "Account Does Not Found !" << endl;
	}

	Event getNextEvent(string Email) {
		int Index = hashFunction(Email);
		Node<Student> * Head = Table[Index].getHead();
		while (Head != NULL)
		{
			if (Head->getData().getEmail() == Email) {
				return Head->getData().getEvents()->Top();
			}
			Head = Head->getNext();
		}
	}

	void newEvent(string Email) {
		int Index = hashFunction(Email);
		Node<Student> * Head = Table[Index].getHead();
		while (Head != NULL)
		{
			if (Head->getData().getEmail() == Email) {
				Head->getData().NewEvent();
			}
			Head = Head->getNext();
		}
	}

	void RecentTimeline(string Email) {
		int Index = hashFunction(Email);
		Node<Student> * Head = Table[Index].getHead();
		while (Head != NULL)
		{
			if (Head->getData().getEmail() == Email) {
				Head->getData().DisplayTimeline();
			}
			Head = Head->getNext();
		}
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
		string Timeline;
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

			
			
			// Get the Events from the Records
			input >> Temp;
			MaxHeap * Events = new MaxHeap(10);
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
				Events->Insert(Event(Date, Month, Year, Hour, Minute, Description));
			}

			getline(input, Temp);


			Student newStudent(Name, Email, Password, Class, Year, Events);

			// Get the all the Timeline post from the Records
			input >> Temp;

			while (Temp != "...")
			{
				
				getline(input, Timeline, '"');
				input >> Temp;
				input >> Temp;
				newStudent.InsertTimeLine(Timeline);

			}

			newStudent.Display();
			insert(newStudent);

			getline(input, Temp);
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

					// Output all the Events to the File
					if (Head->getData().getEvents() != NULL) {
						Event * outputevents = Head->getData().getEvents()->getEvents();
						int EventSize = Head->getData().getEvents()->getTotal();

						for (int i = 0; i <= EventSize; i++)
						{
							if (outputevents[i].getYear() != 0) {
								output << '"' << " " << outputevents[i].getDate() << " " << outputevents[i].getMonth() << " " << outputevents[i].getYear() << " " << outputevents[i].getHour() << " " << outputevents[i].getMinute() << outputevents[i].getDescription() << '"';
								output << " , ";
							}
						}
					}
					output << "..." << endl;

					string * Timeline = Head->getData().getTimeline();
					int TimeNo = Head->getData().getTimeNumber();

					// Output All the Time Line Posts
					for (int i = 0; i < TimeNo; i++)
					{
						output << '"' << Timeline[i] << '"' << " , ";
					}

					output << "..." << endl;
					
					output << endl;

					Head = Head->getNext();
				}
			}
		}

	}
};