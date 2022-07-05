#include <iostream>
#include "HashTable.h"


using namespace std;

/* 
This Function Will Display the Main Menu to the Control and get a int from function
If the user enter a wrong input then also display a try again message
*/
int MainMenu() {
	system("CLS");
	cout << "******    MAIN MENU    ******" << endl;
	while (1)
	{
		int Opt = 0;
		cout << "1 - Login" << endl;
		cout << "2 - Create New Account" << endl;
		cout << "3 - Exit the program" << endl;
		cout << "Enter Option : ";
		cin >> Opt;
		if (Opt >= 1 && Opt <= 3) {
			return Opt;
		}
		cout << endl << "Invalid Option Selected !!" << endl << endl;
	}
}

/*
This function will works same as Main Menu except it has more option than main menu
*/
int UserMenu() {
	system("CLS");
	cout << "******    USER MENU    ******" << endl;
	while (1)
	{
		int Opt = 0;
		cout << "1 - Post To Timeline" << endl;
		cout << "2 - Add a new event to the List" << endl;
		cout << "3 - View List of Freinds" << endl;
		cout << "4 - Add or Remove a Freind" << endl;
		cout << "5 - Logout" << endl;
		cout << "Enter Option : ";
		cin >> Opt;
		if (Opt >= 1 && Opt <= 5) {
			return Opt;
		}
		cout << endl << "Invalid Option Selected !!" << endl << endl;
	}
}

int main() {

	// This is a Hash table that will gonna store all the students in it
	// Key used for the Hash Table is the Email Address of the Student
	HashTable Students(100);

	// This is used to store the mail and password of the current login user
	string currentUserMail;
	string currentUserPass;

	// First of We Read All the Data from the File "Data.txt"
	// This will read data and store it into the Hash table according to the Hash Function
	Students.Read();

	system("pause");
	// This Variable is Used to Store all the Option Selected
	int Opt = 0;

	while (Opt != 3)
	{
		Opt = MainMenu();

		if (Opt == 1) {
			system("CLS");
			cout << "******    NEW ACCOUNT    ******" << endl;
			cin.ignore();
			cout << "Enter Email : ";
			getline(cin, currentUserMail);
			cout << "Enter Password : ";
			getline(cin, currentUserPass);
			if (Students.Login(currentUserMail, currentUserPass)) {
				while (Opt != 5)
				{
					Opt = UserMenu();
				}
			}
			else {
				cout << "Invalid User Mail and Password" << endl;
				system("pause");
			}
		}
		else if (Opt == 2) {
			system("CLS");
			cout << "******    NEW ACCOUNT    ******" << endl;
			cin.ignore();
			Student newStudent;
			newStudent.NewStudent();
			Students.insert(newStudent);
			system("pause");
		}
	}


	// At Last we Have to Store the Updated Data to the File "Data.txt"
	//Students.Write();

	return 0;
}