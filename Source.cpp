#include<iostream>
#include<string>
#include<list>
#include<fstream>
#include "Header.h"

using namespace std;

int main() {

	init();

	int action = 0;

	cout << "Hello! What you want to do?" << endl;
	cout << endl;

	do {
		cout << "1. Sign up" << endl;
		cout << "2. Log in" << endl;
		cout << "3. Exit" << endl << endl;

		cout << "Enter action->_ ";
		cin >> action;
		cout << endl;

		switch (action) {
		case 1:
			signUp();
			cout << endl;
			break;
		case 2:
			logIn();
			cout << endl;
			break;
		case 3:
			cout << "Bye ;)" << endl;
			break;
		default:
			cout << "Error! Enter another number!" << endl << endl;		
		}
	
	} while (action != 3);



	system("pause");
	return 0;
}