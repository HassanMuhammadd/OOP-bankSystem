#pragma once
#include<fstream>
#include "client.h"
#include "employee.h"
#include "admin.h"
#include "clientManager.h"
#include "fileManager.h"
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
			Employee 
				e;
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


int loginChoice;

class screensClass {
public:

	static void runApp() {
		//getting data from files to vectors
		Retrieve::fileToClient();
		Retrieve::fileToEmp();
		Retrieve::fileToAdmin();

		//start
		welcome();
		loginOptions();
		//choosing to login as admin/client/emp
		loginChoice = loginAs();
		//checking if input is invalid
		invalid(loginChoice);
		//logging in as admin or emp or client
		loginScreen(loginChoice);
	}

	static void welcome() {
		cout << "Welcome to ALO bank\n===============================\n";
	}
	static void loginOptions() {
		cout << "Login as: \n\n";
		cout << "1:Admin\n2:Employee\n3:Client\n\n";
	}
	static int loginAs() {
		int choice;
		cin >> choice;
		return choice;
	}

	static void invalid(int c) {
		if (c != 1 && c != 2 && c != 3) {
			cout << "\nInvalid Option.\n\n";
			
		}
	}
	static void loginScreen(int c) {
		if (c == 1) {
			//admin
			cout << "Enter Admin ID and Password: \n";

		}
		if (c == 2) {
			//emp
			cout << "Enter Employee ID and Password: \n";
		}
		if (c == 3) {
			//Client
			cout << "Enter Client ID and Password: \n";
			//client Login
			
		}
	}

	static int clientOptions() {
		int clientChoice;
		cin >> clientChoice;
		return clientChoice;
	}
	static void logOut() {
		screensClass::welcome();
		screensClass::loginOptions();
	}
};


