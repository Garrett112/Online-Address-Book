#pragma once
#include <fstream>
#include "extPersonType.h"
#include "orderedLinkedList.h"

class addressBookType : public orderedLinkedList<extPersonType> {
public:
	addressBookType() {
		cursor = nullptr;
	}
	void initEntry() {
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
		ifstream file("Text.txt");
		while (!file.eof()) {
			extPersonType newNode;
			file >> tempFname >> tempLname;
			newNode.setFirstName(tempFname);
			newNode.setLastName(tempLname);
			file >> tempDay >> tempMonth >> tempYear;
			newNode.birthday.setDate(tempMonth, tempDay, tempYear);
			getline(file, tempAddress);
			getline(file, tempAddress);
			newNode.address.setAddress(tempAddress);
			getline(file, tempCity);
			file >> tempState >> tempZip;
			newNode.address.setCity(tempCity);
			newNode.address.setState(tempState);
			newNode.address.setZipcode(tempZip);
			file >> tempPhone >> tempRelation;
			newNode.setPhoneNumber(tempPhone);
			newNode.setRelationship(tempRelation);
			insert(newNode);
		}
	}

	void addEntry(extPersonType E) {
		insert(E);
	}
	void findPerson(string lName) {
		cursor = first;
		while (cursor != nullptr) {
			if (cursor->info.getLastName() == lName) {
				cursor->info.print();
			}
			cursor = cursor->link;
		}
		cursor = nullptr;
	}
	void findBirthdays(int bDayMonth) {
		cursor = first;
		while (cursor != nullptr) {
			if (cursor->info.getBirthMonth() == bDayMonth) {
				cursor->info.print();
			}
			else {}
			cursor = cursor->link;
		}
		cursor = nullptr;
	}
	void findRelationship(string rShip) {
		cursor = first;
		while (cursor != nullptr) {
			if (cursor->info.getRelationship() == rShip) {
				cursor->info.print();
			}
			else {}
			cursor = cursor->link;
		}
		cursor = nullptr;
	}
	void print() {
		cursor = first;
		while (cursor != nullptr) {
			cursor->info.print();
			cursor = cursor->link;
		}
		cursor = nullptr;
	}
	void manualEntry() {
		extPersonType newNode;
		string tempFname;
		string tempLname;
		int tempDay;
		int tempMonth;
		int tempYear;
		string tempAddress;
		string tempAddress1;
		string tempCity;
		string tempState;
		int tempZip;
		string tempPhone;
		string tempRelation;
		string line;
		cout << "Enter First Name: ";
		cin >> tempFname;
		newNode.setFirstName(tempFname);
		cout << endl << "Enter Last Name: ";
		cin >> tempLname;
		newNode.setLastName(tempLname);
		cout << endl << "Enter Birthday (M D Y): ";
		cin >> tempMonth >> tempDay >> tempYear;
		newNode.birthday.setDate(tempMonth, tempDay, tempYear);
		cout << endl << "Enter Street Address: ";
		cin >> tempAddress;
		getline(cin, tempAddress1);
		newNode.address.setAddress(tempAddress + tempAddress1);
		cout << endl << "Enter City: ";
		cin >> tempCity;
		newNode.address.setCity(tempCity);
		cout << endl << "Enter State: ";
		cin >> tempState;
		newNode.address.setState(tempState);
		cout << endl << "Enter Zip Code: ";
		cin >> tempZip;
		newNode.address.setZipcode(tempZip);
		cout << endl << "Enter Phone Number: ";
		cin >> tempPhone;
		newNode.setPhoneNumber(tempPhone);
		cout << endl << "Enter Relationship: ";
		cin >> tempRelation;
		addEntry(newNode);
	}
	void manualRemoveEntry() {
		string lName;
		string fName;
		cout << "Enter Last Name: ";
		cin >> lName;
		cout << endl << "Enter First Name: ";
		cin >> fName;
		cursor = this->first;
		nodeType<extPersonType>* searcher = first;
		while (searcher != nullptr) {
			if (searcher->info.getLastName() == lName && searcher->info.getFirstName() == fName) {
				cout << "Should the Following Entry be Deleted (Y/N)?: " << endl;
				searcher->info.print();
				string choice;
				cin >> choice;
				if (choice == "Y") {
					if (searcher == first) {
						first = first->link;
					}
					else {
						cursor->link = searcher->link;
						if (searcher == last) {
							last = cursor;
						}
					}
					cout << endl << "Entry has been Deleted.";
				}
				else {
					cout << endl << "Entry has not been Deleted. ";
				}
			}
			searcher = searcher->link;
			cursor = cursor->link;
		}

	}
	void saveData() {
		ofstream file("Text1.txt");
		cursor = first;
		while (cursor != nullptr) {
			file << cursor->info.getFirstName() << " " << cursor->info.getLastName() << endl;
			file << cursor->info.birthday.getMonth() << " " << cursor->info.birthday.getDay() << " " << cursor->info.birthday.getYear() << endl;
			file << cursor->info.address.getAddress() << endl;
			file << cursor->info.address.getCity() << endl;
			file << cursor->info.address.getState() << endl;
			file << cursor->info.address.getZip() << endl;
			file << cursor->info.getPhoneNumber() << endl;
			file << cursor->info.getRelationship() << endl;
			cursor = cursor->link;
		}
		file.close();
	}
private:
	nodeType<extPersonType>* cursor;
};
 
