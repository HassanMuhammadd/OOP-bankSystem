#pragma once
#include <iostream>
using namespace std;

class Validate {
public:
	static bool validateName(string name) {
		bool valid = true;
		if (name.size() < 5) {   //invalid length:short
			cout << "Name is too short, It must be more than 5 characters.\n";
			valid = false;
		}
		else if (name.size() > 20) { //invalid length:Long
			cout << "Name is too long, it must be less than 20 characters.\n";
			valid = false;
		}
		else {	
			//if valid length ->Check alphabet
		for (int i = 0; i < name.size(); i++) {
			if (name[i] >= 'a' && name[i] <= 'z') {
				valid = true;
			}
			else if (name[i] >= 'A' && name[i] <= 'Z') {
				valid = true;
			}
			else {
				cout << "Name must only consist of alphabetical characters.\n";
				valid = false;
				break;
			}

		}

		}
		return valid;
	}
	static bool validatePassword(string pw) {
		bool valid = true;
		if (pw.size() < 8) {	//short password
			valid = false;
			cout << "Your Password is short,it must be more than 8 characters.\n";
		}
		else if (pw.size() > 20) {//long password
			valid = false;
			cout << "Your Password is long,it must be less than 20 characters.\n";

		}
		else
			valid = true;

		return valid;
	}
	static bool validateBalance(double balance) {
		bool valid = true;
		if (balance < 1500) {
			cout << "The minimum balance can't be less than 1500.\n";
			valid = false;
		}
		return valid;
	}
	static bool validateSalary(double salary) {
		bool valid = true;
		if (salary < 5000) {
			cout << "Salary can't be less than 5000.\n";
			valid = false;
		}
		return valid;
	}
};