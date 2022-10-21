#pragma once
#include <iostream>
#include <vector>
#include "person.h"
#include "screensClass.h"


using namespace std;

//finished
class Client : public Person {
private:
	double balance = 0;
public:
	Client() {

	}
	Client(string name, string password, double balance) :Person(name, password) {
		setBalance(balance);
	}
	//setter & getter
	void setBalance(double balance) {
		if (Validate::validateBalance(balance))
			this->balance = balance;
		else {
			cout << "Enter a new balance: ";
			double b;
			cin >> b;
			setBalance(b);
		}
	}
	double getBalance() {
		return balance;
	}

	//other functionalities

	void deposit(double amount) {
		balance += amount;
	}
	void withdraw(double amount) {
		if (amount <= balance) {
			balance -= amount;
			cout << amount << " Withdrawn successfully!\n";
		}
		else {
			cout << "Error, Your balance is not enough to complete this transaction." << endl;
			cout << "Do you want to Withdraw another amount? (Y/N)\n";
			char choice;
			cin >> choice;
			if (choice == 'Y' || choice == 'y') {
				cout << "Enter amount to withdraw : ";
				double a;
				cin >> a;
				withdraw(a);
			}
			else {
				cout << "Going back. \n";
			}

		}
	}
	void checkBalance() {
		cout << "Your current balance is: " << balance << endl;
	}

	void transferTo(double amount, Client& reciever) {
		if (amount <= balance) {
			balance -= amount;
			reciever.deposit(amount);
		}
		else {
			cout << "Error, Your balance is not enough to complete this transaction." << endl;
			cout << "Enter another balance to transfer it to another Client: ";
			double a;
			cin >> a;
			transferTo(a, reciever);
		}
	}
	void display() {
		Person::display();
		cout << "Current Balance: " << getBalance() << endl;
	}
};

static vector<Client> allClients;
static vector<Client>::iterator clientIt;