#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "person.h"
using namespace std;


class Employee : public Person {
protected:
	double salary;
public:
	Employee() {
	}
	Employee(string name, string password, double salary) :Person(name, password) {
		setSalary(salary);
	}

	//setter & getter

	void setSalary(double salary) {
		if (Validate::validateSalary(salary))
			this->salary = salary;
		else {
			cout << "Enter a new salary: ";
			double s;
			cin >> s;
			setSalary(s);
		}
	}
	double getSalary() {
		return salary;
	}

	//other functionalities

	void display() {
		Person::display();
		cout << "Salary: " << getSalary()<<endl;
		cout << "=========================\n";
	}
	void Addclient(Client& c) {
		allClients.push_back(c);
	}
	void listclient() {
		for (int i = 0; i < allClients.size(); i++) {
			Client s = allClients[i];
			cout << "Client name: " << s.getName() << ", ID: " << s.getID() << ", Password: " << s.getPassword() << ", Balance: " << s.getBalance() << endl;
			cout << "===============================\n";
		}
	}
	Client* searchclient(int id) {
		
		for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {
			if (clientIt->getID() == id) {
				return clientIt._Ptr;
			}
		}

		return NULL;
	
	}
	void editclient(string newname, string newpass, int id, double newbalance) {
		if (searchclient(id)) {

		searchclient(id)->setName(newname);
		searchclient(id)->setPassword(newpass);
		searchclient(id)->setBalance(newbalance);
		}
		else {
			cout << "Client not found.\n";
			cout << "Enter Client ID: \n";
			int Newid;
			cin >> Newid;
			editclient(newname, newpass, Newid, newbalance);
		}
		}
};

static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;