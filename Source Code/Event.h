#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Event {
	int Date;
	int Month;
	int Year;
	int Hour;
	int Minute;
	string Description;

public:

	// Default Constructor
	Event() {
		this->Date = 0;
		this->Month = 0;
		this->Year = 0;
		this->Hour = 0;
		this->Minute = 0;
		this->Description = " ";
	}

	// Parameterlized Contructor
	Event(int Date, int Month, int Year, int Hour, int Minute, string Description) {
		this->Date = Date;
		this->Month = Month;
		this->Year = Year;
		this->Hour = Hour;
		this->Minute = Minute;
		this->Description = Description;
	}

	// getter and setter

	void setDate(int Date) {
		this->Date = Date;
	}

	void setMonth(int Month) {
		this->Month = Month;
	}

	void setYear(int Year) {
		this->Year = Year;
	}

	void setHour(int Hour) {
		this->Hour = Hour;
	}

	void setMinute(int Minute) {
		this->Minute = Minute;
	}

	void setDescription(string Description) {
		this->Description = Description;
	}

	int getDate() {
		return Date;
	}

	int getMonth() {
		return Month;
	}

	int getYear() {
		return Year;
	}

	int getHour() {
		return Hour;
	}

	int getMinute() {
		return Minute;
	}

	string getDescription() {
		return Description;
	}

	void Read() {
		cout << "Enter Date : ";
		cin >> Date;
		cout << "Enter Month : ";
		cin >> Month;
		cout << "Enter Year : ";
		cin >> Year;
		cout << "Enter Hour : ";
		cin >> Hour;
		cout << "Enter Minute : ";
		cin >> Minute;
		cin.ignore();
		cout << "Enter Description : ";
		getline(cin, Description);
		Description = " " + Description + " ";
	}

	void DisplaySmall() {
		cout << '"' << " " << Date << " " << Month << " " << Year << " " << Hour << " " << Minute << " " << Description << " " << '"';
	}

	void Display() {
		cout << "Date : " << Date << "/" << Month << "/" << Year << endl;
		cout << "Time : " << Hour << " : " << Minute << endl;
		cout << "Description : " << Description << endl;
	}

};