#pragma once
#include <iostream>
#include<fstream>
#include<vector>
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
		bool found = false;
		Client returned;
		for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {

			if (clientIt->getID() == id) {
				return clientIt._Ptr;
			}
		}
		return NULL;
	
	}
	void editclient(string newname, string newpass, int id, double newbalance) {
		searchclient(id)->setName(newname);
		searchclient(id)->setPassword(newpass);
		searchclient(id)->setBalance(newbalance);
	
		/*cout << "Enter The id Of The Client: ";
		int oldid;
		cin >> oldid;
		Client edit = searchclient(oldid);

		ifstream clientFile;
		clientFile.open("clients.txt");

		string oldName, oldPassword;
		int idd;
		double oldBalance;

		//saving new data in temp file
		ofstream tempFile("temp.txt");
		while (clientFile >> oldName >> idd >> oldBalance >> oldPassword) {
			if (idd == oldid) {
				tempFile << newname << " " << newid << " " << newbalance << " " << newpass << endl;
			}
			else {
				tempFile << oldName << " " << idd << " " << oldBalance << " " << oldPassword << endl;
			}

		}
		//restoring data in clients.txt
		ifstream tempOpen("temp.txt");
		ofstream restore("clients.txt");
		string tempName, tempPassword;
		int tempID;
		double tempBalance;
		while (tempOpen >> tempName >> tempID >> tempBalance >> tempPassword) {
			restore << tempName << " " << tempID << " " << tempBalance << " " << tempPassword << endl;
		}
		*/
	}
};

static vector<Employee> allEmployees;
static vector<Employee>::iterator eIt;