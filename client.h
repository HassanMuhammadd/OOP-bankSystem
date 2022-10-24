#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include "person.h"
#include "screensClass.h"


using namespace std;


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

	void deposit(double amount,Client c,vector<Client>&allClients) {

		for (int i = 0; i < allClients.size(); i++) {
			if (c.getID() == allClients[i].getID()) {
				allClients[i].setBalance(c.getBalance() + amount);
			}
		}
		

	}
	void withdraw(double amount, Client c, vector<Client>& allClients) {

		for (int i = 0; i < allClients.size(); i++) {
			if (c.getID() == allClients[i].getID()) {
				if (c.getBalance() >= amount) {
					allClients[i].setBalance(allClients[i].getBalance() - amount);
					cout << amount << " Withdrawn successfully!\n";
					
				}
				else {
					cout << "Error, Your balance is not enough to complete this transaction." << endl;
					cout << "Enter another amount to withdraw: \n";
					double amount;
					cin >> amount;
					withdraw(amount,c,allClients);
				}
			}
		}
		 
	}
	void transferTo(double amount, Client& sender, int recieverID, vector<Client>& allClients) {

		for (int i = 0; i < allClients.size(); i++) {
			if (sender.getID() == allClients[i].getID()) {

					//if sender = receiver
				if (recieverID == allClients[i].getID()) {
					cout << "Reciever ID cannot be the same as sender ID\n";
					cout << "Please enter another receiver ID: \n";
					int id;
					cin >> id;
					transferTo(amount, sender, id, allClients);
				}

				if (sender.getBalance() >= amount) {

					//search for receiver
					bool found;
					for (int j = 0; j < allClients.size(); j++) { 
						found = false;
						if (recieverID == allClients[j].getID()) {
							found = true;
						}

						//transfer to receiver if found
					if (found) {
						allClients[i].setBalance(sender.getBalance() - amount);
						allClients[j].setBalance(allClients[j].getBalance() + amount);
						break;
						}
					}
					//if not found prompt user for another receiver
					if (!found) {
						cout << "Reciever ID is incorrect\n";
						cout << "Please enter another receiver ID: \n";
						int id;
						cin >> id;
						transferTo(amount, sender, id,allClients);
					}
				}
			}
		}
	}
	void checkBalance() {
		cout << "Your current balance is: " << balance << endl;
	}
	void display() {
		cout << "\n\n";
		Person::display();
		cout << "Current Balance: " << getBalance() << endl;
	}

};

static vector<Client> allClients;
static vector<Client>::iterator clientIt;

class ClientManager {
public:
	static void PrintClientMenu() {
		cout << endl << "===============================\n\n";
		cout << "1.deposit" << endl << "2.withdraw" << endl << "3.transfer to another client" << endl << "4.display info" << endl <<"5.Update Password\n" << "6.Exit\n";
	}


	static Client* login(int id, string password, vector<Client>& allClients) {
		bool found = false;

		for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {
			if (clientIt->getID() == id && clientIt->getPassword() == password) {
				found = true;
				return clientIt._Ptr;
			}
		}
		if (!found) {
			cout << "Invalid Client data\n";
			cout << "Enter Client ID and Password: \n";
			int id;
			string password;
			cin >> id >> password;
			login(id, password, allClients);
		}
	}


	static void updatePassword(Client* loggedInClient) {
		cout << "Enter your new Password: ";
		string password;
		cin >> password;
		if (password.size() >= 8) {
		loggedInClient->setPassword(password);
		}
		else {
			cout << "Password is too short\n";
			cout << "Enter new Password: ";
			cin >> password;
			loggedInClient->setPassword(password);
		}
	}

};

