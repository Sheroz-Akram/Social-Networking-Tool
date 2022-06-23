#include <iostream>
using namespace std;

/* 
This Function Will Display the Main Menu to the Control and get a int from function
If the user enter a wrong input then also display a try again message
*/
int MainMenu() {
  cout << "******    MAIN MENU    ******" << endl;
  while (1) {
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
This function will works same as Main Menu except it has more option than main
menu
*/
int UserMenu() {
  cout << "******    USER MENU    ******" << endl;
  while (1) {
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
  MainMenu();

  return 0;
}
