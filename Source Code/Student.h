#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Student {
	string Name;
	string Email;
	string Password;
	string Class;
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
	Student(string Name , string Email , string Password , string Class , int Year) {
		this->Name = Name;
		this->Email = Email;
		this->Password = Password;
		this->Class = Class;
		this->Year = Year;
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

	// Display Student Info
	void Display() {
		cout << "Name : " << Name << endl;
		cout << "Email : " << Email << endl;
		cout << "Password : " << Password << endl;
		cout << "Class : " << Class << endl;
		cout << "Year : " << Year << endl;
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