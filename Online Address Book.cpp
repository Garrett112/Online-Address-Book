#include "addressBookType.h"

void showMenu() {
	addressBookType addressBook;
	addressBook.initEntry();
	int w = 1;
	while (w == 1) {
		cout << "Please Select an Option:" << endl;
		cout << "Enter 1 to Search by Last Name" << endl;
		cout << "Enter 2 to Search by Birth Month" << endl;
		cout << "Enter 3 to Search by Relationship" << endl;
		cout << "Enter 4 to Show all Entries" << endl;
		cout << "Enter 5 to Quit" << endl;
		int choice;
		cin >> choice;
		if (choice == 1) {
			cout << "Enter Last Name: ";
			string InputL;
			cin >> InputL;
			cout << endl;
			addressBook.findPerson(InputL);
		}
		if (choice == 2) {
			cout << "Enter Birth Month (Number 1-12): ";
			int InputM;
			cin >> InputM;
			cout << endl;
			addressBook.findBirthdays(InputM);
		}
		if (choice == 3) {
			cout << "Enter Relationship (Family, Friend, or Business): ";
			string InputR;
			cin >> InputR;
			cout << endl;
			addressBook.findRelationship(InputR);
		}
		if (choice == 4) {
			addressBook.print();
		}
		if (choice == 5) {
			w = 0;
		}
	}
};

int main() {
	showMenu();
}



