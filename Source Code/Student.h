#include <iostream>
#include "Queue.h"
#include <string>
#include <sstream>
#include "MaxHeap.h"


using namespace std;

class Student {
	string Name;
	string Email;
	string Password;
	string Class;
	Queue<string> * Timeline;
	MaxHeap * Events;
	int Year;

public:

	// Default Contructor
	Student() {
		this->Name = " ";
		this->Email = " ";
		this->Password = " ";
		this->Class = " ";
		this->Year = 0;
	}

	// Parameterlized Constructor
	Student(string Name , string Email , string Password , string Class , int Year , Queue<string> * Timeline , MaxHeap * Events) {
		this->Name = Name;
		this->Email = Email;
		this->Password = Password;
		this->Class = Class;
		this->Year = Year;
		this->Timeline = Timeline;
		this->Events = Events;
	}

	// Setter and Getters

	void setName(string Name) {
		this->Name = Name;
	}

	void setEmail(string Email) {
		this->Email = Email;
	}

	void setPassword(string Password) {
		this->Password = Password;
	}

	void setClass(string Class) {
		this->Class = Class;
	}

	void setYear(int Year) {
		this->Year = Year;
	}

	void setTime(Queue<string> * Timeline) {
		this->Timeline = Timeline;
	}

	void setEvents(MaxHeap * Events) {
		this->Events = Events;
	}


	string getName() {
		return Name;
	}

	string getEmail() {
		return Email;
	}

	string getPassword() {
		return Password;
	}

	string getClass() {
		return Class;
	}

	int getYear() {
		return Year;
	}

	Queue<string> * getTimeline() {
		return Timeline;
	}

	MaxHeap * getEvents() {
		return Events;
	}

	// Display Student Info
	void Display() {
		cout << Name << endl;
		cout << Email << endl;
		cout << Password << endl;
		cout << Class << " " << Year << endl;

		// Display All the Events
		Events->Display();

		// Display All the Time line Posts
		while (!Timeline->isEmpty())
		{
			cout << '"'  << Timeline->Top() << '"' << " , ";
			Timeline->Dequeue();
		}

		cout << "..." << endl;
	}


	// We use to create a function to get Data from the user
	void NewStudent() {
		cout << "Enter Name : ";
		getline(cin, Name);
		cout << "Enter Email : ";
		getline(cin, Email);
		cout << "Enter Password : ";
		getline(cin, Password);
		cout << "Enter Class : ";
		cin >> Class;
		cout << "Enter Year : ";
		cin >> Year;

	}


	

};