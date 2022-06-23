#include <iostream>

using namespace std;

int MainMenu() {
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

int main() {

	MainMenu();

	return 0;
}