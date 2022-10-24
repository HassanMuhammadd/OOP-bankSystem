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
	static void listclient() {
		for (int i = 0; i < allClients.size(); i++) {
			Client s = allClients[i];
			cout << "Client name: " << s.getName() << ", ID: " << s.getID() << ", Balance: " << s.getBalance() << endl;
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

class EmployeeManager {
public:
	static void	PrintMenu() {
		cout << endl << "===============================\n\n";
		cout << "1.Add Client\n" << "2.List Clients\n" << "3.Update Client password\n" << "4.Search For Client\n" << "5.Display Employee Info\n" << "6.Exit\n";
	}
	static Employee* login(int id, string password, vector<Employee>& allEmployees) {
		bool found = false;
		for (eIt= allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getID() == id && eIt->getPassword() == password) {
				found = true;
				return eIt._Ptr;
			}
		}
			if (!found) {
				cout << "Invalid Employee data\n";
				cout << "Enter Employee ID and Password: \n";
				int id;
				string password;
				cin >> id >> password;
				login(id, password, allEmployees);
			}
	}

	static void updatePassword(Employee* loggedInEmployee) {
		cout << "Enter your new Password: ";
		string password;
		cin >> password;
		if (password.size() >= 8) {
			loggedInEmployee->setPassword(password);
		}
		else {
			cout << "Password is too short\n";
			cout << "Enter new Password: ";
			cin >> password;
			loggedInEmployee->setPassword(password);
		}
	}

	static void listEmployee() {
		for (int i = 0; i < allEmployees.size(); i++) {
			allEmployees[i].display();
		}
	}
};