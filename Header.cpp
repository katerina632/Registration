#include "Header.h"


const string fileName = "ListOfUsers.txt";

struct User {
	string name;
	string email;
	string password;
};

list<User>listUsers;

void init()
{
	ifstream fin;
	fin.open(fileName);

	bool isOpen = fin.is_open();
	if (isOpen == true) {

		while (!fin.eof()) {
			User tempUsers;

			fin >> tempUsers.name;
			if (tempUsers.name != "") {			
				fin >> tempUsers.email;
				fin >> tempUsers.password;
				listUsers.push_back(tempUsers);
			}
			else {
				break;
			}
		}
	}
	else {
		cout << "Error!" << endl;
	}

	fin.close();
}


void signUp()
{
	ofstream fout;
	fout.open(fileName, fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
	User newUser;
	cout << "\t\tYou want to Sign Up" << endl;
	cout << "Enter user name->_ ";
	cin >> newUser.name;
	fout << newUser.name << endl;

	cout << "Enter email->_ ";
	cin >> newUser.email;
	fout << newUser.email << endl;

	cout << "Enter  password->_ ";
	cin >> newUser.password;
	fout << newUser.password << endl;

	listUsers.push_back(newUser);
	}
	else {
		cout << "Error!" << endl;
	}

	fout.close();

}

void logIn()
{
	string name;
	string password;
	int index = 0;

	cout << "\t\tYou want to Log In" << endl;
	cout << "Enter user name->_ ";
	cin >> name;

	cout << "Enter  password->_ ";
	cin >> password;
	cout << endl;

	bool isEmpty = false;
	if (listUsers.empty()) {

		cout << "The list is empty!" << endl << endl;
	}
	else {
		for (User item : listUsers) {
			if (item.name == name && item.password == password) {
				index++;
				cout << "\t\tHello " << item.name << "!" << endl;			

			}
			else if (item.name != name && item.password != password&& index == 1) {
				isEmpty = true;
			}
		}
		if (isEmpty == true) {
			cout << "User not found!" << endl;
		}
		cout << endl;
	}

} 
	


