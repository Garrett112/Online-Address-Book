#pragma once
#include <fstream>
#include "extPersonType.h"

class addressBookType {
public:
	addressBookType() {
		length = 0;
		maxLength = 200;
	}
	void initEntry() {
		int i = 0;
		string tempFname;
		string tempLname;
		int tempDay;
		int tempMonth;
		int tempYear;
		string tempAddress;
		string tempCity;
		string tempState;
		int tempZip;
		string tempPhone;
		string tempRelation;
		string line;
		ifstream file("AddressBookData.txt");
		while (i < 6) {
			cout << i << endl;
			file >> tempFname >> tempLname;
			addressList[i].setFirstName(tempFname);
			addressList[i].setLastName(tempLname);
			file >> tempDay >> tempMonth >> tempYear;
			addressList[i].birthday.setDate(tempMonth, tempDay, tempYear);
			getline(file, tempAddress);
			getline(file, tempAddress);
			addressList[i].address.setAddress(tempAddress);
			getline(file, tempCity);
			file >> tempState >> tempZip;
			addressList[i].address.setCity(tempCity);
			addressList[i].address.setState(tempState);
			addressList[i].address.setZipcode(tempZip);
			file >> tempPhone >> tempRelation;
			addressList[i].setPhoneNumber(tempPhone);
			addressList[i].setRelationship(tempRelation);
			++length;
			++i;
		}
	}

	void addEntry(extPersonType E) {
		if (length < maxLength) {
			length++;
			addressList[length] = E;
		}
		else {
			cout << "Array has reached it's maximum capacity." << endl;
		}
	}
	void findPerson(string lName) {
		for (int i = 0; i <= length; ++i) {
			if (addressList[i].getLastName() == lName) {
				addressList[i].print();
			}
		}
	}
	void findBirthdays(int bDayMonth) {
		for (int i = 0; i <= length; ++i) {
			if (addressList[i].getBirthMonth() == bDayMonth) {
				addressList[i].print();
			}
			else {}
		}
	}
	void findRelationship(string rShip) {
		for (int i = 0; i <= length; ++i) {
			if (addressList[i].getRelationship() == rShip) {
				addressList[i].print();
			}
			else {}
		}
	}
	void print() {
		for (int i = 0; i < length; ++i) {
			addressList[i].print();
		}
	}
	void sortEntries() {
		for (int c = 1; c < length; c++) {
			int i = c;
			bool placeFound = false;
			while (i > 0 && !placeFound) {
				if (addressList[i].getLastName() < addressList[i - 1].getLastName()) {
					extPersonType temp = addressList[i];
					addressList[i].setLastName(addressList[i - 1].getLastName());
					addressList[i - 1] = temp;
					i--;
				}
				else {
					placeFound = true;
				}
			}
		}
	}
private:
	extPersonType addressList[15];
	int length;
	int maxLength;
};

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

