#include <iostream>
#include <string>
#include <sstream>
#include "DoublyLinkedList.h"
#include "MaxHeap.h"
#include "AVL.h"


using namespace std;

class Student {
	string Name;
	string Email;
	string Password;
	string Class;
	string * Timeline;
	MaxHeap * Events;
	int Year;
	int TimeNo;
	AVL freinds;

public:

	// Default Contructor
	Student() {
		this->Name = " ";
		this->Email = " ";
		this->Password = " ";
		this->Class = " ";
		this->Year = 0;
		this->Timeline = new string[200];
		TimeNo = 0;
	}

	// Parameterlized Constructor
	Student(string Name , string Email , string Password , string Class , int Year, MaxHeap * Events) {
		this->Name = Name;
		this->Email = Email;
		this->Password = Password;
		this->Class = Class;
		this->Year = Year;
		this->Events = Events;
		cout << "Hello " << endl;
		this->Timeline = new string[200];
		TimeNo = 0;
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


	void setEvents(MaxHeap * Events) {
		this->Events = Events;
	}

	void InsertTimeLine(string Line) {
		Timeline[TimeNo] = Line;
		TimeNo++;
	}

	string * getTimeline() {
		return  Timeline;
	}

	int getTimeNumber() {
		return TimeNo;
	}

	void NewPost(string Post) {
		for (int i = TimeNo; i >= 0; i--)
		{
			Timeline[i + 1] = Timeline[i];
		}
		Timeline[0] = Post;
		TimeNo++;
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

	MaxHeap * getEvents() {
		return Events;
	}

	void NewEvent() {
		Event newEvent;
		newEvent.Read();
		Events->Insert(newEvent);
		Events->Display();
	}

	void DisplayTimeline() {
		cout << "Time Line  : ";
		for (int i = 0; i <= 2 && i <= TimeNo; i++)
		{
			cout << '"' << Timeline[i] << '"' << " , ";
		}
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
		for (int i = 0; i < TimeNo; i++)
		{
			cout << '"'  << Timeline[i] << '"' << " , ";
		}
		cout << "..." << endl;
		freinds.DisplayAll();
		cout << "..." << endl;
	}

	void DisplayFreinds() {
		freinds.DisplayAll();
	}


	void AddFreind(string Email) {
		freinds.Insert(Email);
	}

	void RemoveFreind(string Freind) {
		freinds.Delete(Freind);
	}

	void Output() {
		freinds.Display();
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
		Events = new MaxHeap(100);
	}


	

};