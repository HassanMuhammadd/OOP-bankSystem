#pragma once
#include<fstream>
#include "client.h"
#include "employee.h"
#include "admin.h"
using namespace std;

class Retrieve {
public:

	//pushing data from file to vector and vector to file
	static void clientToFile() {
		ofstream clientFile;
		clientFile.open("clients.txt");
		for (int i = 0; i < allClients.size(); i++) {
			clientFile << allClients[i].getName() << " " << allClients[i].getID() << " " << allClients[i].getPassword() << " " << allClients[i].getBalance() << endl;
		}
		clientFile.close();
	}
	static void empToFile() {
		ofstream empFile;
		empFile.open("employees.txt");
		for (int i = 0; i < allEmployees.size(); i++) {
			empFile << allEmployees[i].getName() << " " << allEmployees[i].getID() << " " << allEmployees[i].getPassword() << " " << allEmployees[i].getSalary() << endl;
		}
		empFile.close();
	}

	static void fileToClient() {
		ifstream clientFile;
		clientFile.open("clients.txt");
		string name, password;
		int id;
		double balance;
		while (clientFile >> name >> id >> password >> balance) {
			Client c;
			c.setName(name);
			c.setID(id);
			c.setPassword(password);
			c.setBalance(balance);
			allClients.push_back(c);
		}
	}
	static void fileToEmp() {
		ifstream empFile;
		empFile.open("employees.txt");
		string name, password;
		int id;
		double salary;
		while (empFile >> name >> id >> password >> salary) {
			Employee e;
			e.setName(name);
			e.setID(id);
			e.setPassword(password);
			e.setSalary(salary);
			allEmployees.push_back(e);
		}
	}
	static void fileToAdmin() {
		ifstream file;
		file.open("admins.txt");
		string name, password;
		int id;
		double salary;
		file >> name >> id >> salary >> password;
		mainAdmin.setName(name);
		mainAdmin.setID(id);
		mainAdmin.setSalary(salary);
		mainAdmin.setPassword(password);
	}
};