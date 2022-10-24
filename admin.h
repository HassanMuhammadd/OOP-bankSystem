#pragma once
#include <iostream>
#include <vector>
#include "person.h"
#include "employee.h"
#include "client.h"
using namespace std;


class Admin : public Employee {
public:
	Admin() {

	}
	Admin(string name, string password, double salary) :Employee(name, password, salary) {

	}

	void addemployee(Employee& e) {
		allEmployees.push_back(e);
	}
	Employee* searchemployee(int id) {
		for (eIt = allEmployees.begin(); eIt != allEmployees.end(); eIt++) {
			if (eIt->getID() == id)
				return eIt._Ptr;
		}
		return NULL;
	}
	void listEmployee() {
		for (int i = 0; i < allEmployees.size(); i++) {
			Employee e = allEmployees[i];
			e.display();
		}
	}
};

Admin mainAdmin;

class AdminManager {
public:
	static bool login(int id, string password) {
		if (id == 1111 && password == "19071910") {
			return true;
		}
		cout << "Invalid data.\n";
		cout << "Enter Admin ID and Password: \n";
		cin >> id >> password;
		login(id, password);
	}
	static void PrintAdminMenu() {
		cout << endl << "===============================\n\n";
		cout << "\n1.Add Client\n" << "2.Remove Client\n" << "3.Change Client Password\n" << "4.Add Employee\n" << "5.Remove Employee\n" << "6.Change Employee Password\n" <<"7.List Clients\n" << "8.List Employees\n"<<"9.Exit\n";
		cout << endl << "===============================\n\n";
	}

	static void RemoveClient(int id, string password, vector<Client>& allClients) {
		bool found = false;
		for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {
			if (clientIt->getID() == id && clientIt->getPassword() == password) {
				found = true;
				allClients.erase(clientIt);
				break;
			}
		}
		if (!found) {
			cout << "Client Not found. \n";
		}
	}
	static void RemoveEmployee(int id, string password, vector<Employee>& allEmployees) {
		bool found = false;
		for (auto i = allEmployees.begin(); i != allEmployees.end(); i++) {
			if (i->getID() == id && i->getPassword() == password) {
				found = true;
				allEmployees.erase(i);
				break;
			}
		}
		if (!found) {
			cout << "Employee not found. \n";
		}
	}
};
