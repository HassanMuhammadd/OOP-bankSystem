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
Client* loggedInClient;
Employee* loggedInEmployee;

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
		

		//putting data back to files
		Retrieve::clientToFile();
		Retrieve::empToFile();
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
			int id;
			string password;
		if (c == 1) {
			//admin
			cout << "Enter Admin ID and Password: \n";
			//admin login
			cin >> id >> password;
			if (AdminManager::login(id, password)) {
				AdminManager::PrintAdminMenu();
				AdminOptions();
			}
		}
		if (c == 2) {
			//emp
			cout << "Enter Employee ID and Password: \n";
			cin >> id >> password;
			//emp login
			loggedInEmployee = EmployeeManager::login(id,password,allEmployees);
			//emp menu
			EmployeeManager::PrintMenu();
			EmployeeOptions();
		}
		if (c == 3) {
			//Client app
			cout << "Enter Client ID and Password: \n";
			//client Login
			
			cin >> id >> password;
			loggedInClient = ClientManager::login(id, password, allClients);
			//client menu
			ClientManager::PrintClientMenu();
			clientOptions(loggedInClient);


		}
	}
	static void clientOptions(Client* loggedInClient) {
		int choice;
		cin >> choice;
		double amount;
		if (choice == 1) {
			//deposit
			cout << "Enter amount to deposit: \n";
			cin >> amount;
			loggedInClient->deposit(amount, *loggedInClient, allClients);
			cout << loggedInClient->getBalance();
		}
		if (choice == 2) {
			//withdraw
			cout << "Enter amount to withdraw: \n";
			cin >> amount;
			loggedInClient->withdraw(amount, *loggedInClient, allClients);
			cout << loggedInClient->getBalance();
		}
		if (choice == 3) {
			//transfer to
			cout << "Enter amount and Receiver ID: \n";
			int id;
			cin >> amount >> id;
			loggedInClient->transferTo(amount, *loggedInClient, id, allClients);
			cout << loggedInClient->getBalance();
		}
		if (choice == 4) {
			//display info
			loggedInClient->display();
			cout << "\n\nEnter Y to return to the client menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				ClientManager::PrintClientMenu();
				clientOptions(loggedInClient);
			}
			else {
				return;
			}
		}
		if (choice == 5) {
			//update password
			ClientManager::updatePassword(loggedInClient);
			//back to main page
			ClientManager::PrintClientMenu();
			clientOptions(loggedInClient);
		}
		if (choice == 6) {
			//exit app
			return;
		}
	}

	static void EmployeeOptions() {
		int choice;
		cin >> choice;
		if (choice == 1) {
			Client s;
			string name, password;
			double balance;
			cout << "\nEnter valid Name,Password and balance\n";
			cin >> name >> password >> balance;
			s.setName(name);
			s.setPassword(password);
			s.setBalance(balance);
			s.setID(Filehelper::getlastClient()+1);
			Filehelper::savelast("lastclientid.txt",s.getID());
			loggedInEmployee->Addclient(s);
			
			cout << "\n\nEnter Y to return to the client menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				EmployeeManager::PrintMenu();
				EmployeeOptions();
			}
			else {
				return;
			}
		}
		if (choice == 2) {

			loggedInEmployee->listclient();
			cout << "\n\nEnter Y to return to the client menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				EmployeeManager::PrintMenu();
				EmployeeOptions();
			}
			else {
				return;
			}
		}
		if (choice == 3) {

			string name, password;
			int id;
			double balance;
			cout << "Enter client ID: ";
			cin >> id;
			cout << "Enter Client new name,new password,and newbalance\n";
			cin >> name >> password >> balance;
			loggedInEmployee->editclient(name, password, id, balance);
			cout << "\n\nEnter Y to return to the client menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				EmployeeManager::PrintMenu();
				EmployeeOptions();
			}
			else {
				return;
			}
		}
		if (choice == 4) {
			int id;
			cout << "Enter Client id\n";
			cin >> id;
			loggedInEmployee->searchclient(id)->display();
			
		}
		if (choice == 5) {
			loggedInEmployee->display();
			cout << "\n\nEnter Y to return to the client menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				EmployeeManager::PrintMenu();
				EmployeeOptions();
			}
			else {
				return;
			}
		}
		if (choice == 6) {
			return;
		}
	}

	static void AdminOptions() {
		int choice;
		cin >> choice;
		if (choice == 1) {//add client
			Client s;
			string name, password;
			double balance;
			cout << "\nEnter valid Name,Password and balance\n";
			cin >> name >> password >> balance;
			s.setName(name);
			s.setPassword(password);
			s.setBalance(balance);
			s.setID(Filehelper::getlastClient() + 1);
			Filehelper::savelast("lastclientid.txt", s.getID());
			loggedInEmployee->Addclient(s);

			cout << "\n\nEnter Y to return to the menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				AdminManager::PrintAdminMenu();
				AdminOptions();
			}
			else {
				return;
			}
		}
		if (choice == 2) {//remove client
			int id;
			string password;
			cout << "Enter id and Password\n";
			cin >> id >> password;
			AdminManager::RemoveClient(id, password, allClients);

			cout << "\n\nEnter Y to return to the menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				AdminManager::PrintAdminMenu();
				AdminOptions();
			}
			else {
				return;
			}
		}
		if (choice == 3) {
			int id;
			string password;
			cout << "Enter Client id and Password: \n";
			cin >> id >> password;
			loggedInClient = ClientManager::login(id, password, allClients);
			ClientManager::updatePassword(loggedInClient);

			cout << "\n\nEnter Y to return to the menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				AdminManager::PrintAdminMenu();
				AdminOptions();
			}
			else {
				return;
			}
		}
		if (choice == 4) {
			Employee s;
			string name, password;
			double salary;
			cout << "Enter Employee Name, Password, and Salary:\n";
			cin >> name >> password >> salary;
			s.setName(name);
			s.setPassword(password);
			s.setSalary(salary);
			s.setID(Filehelper::getLastEmp() + 1);
			Filehelper::savelast("lastempid.txt", s.getID());
			mainAdmin.addemployee(s);

			cout << "\n\nEnter Y to return to the menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				AdminManager::PrintAdminMenu();
				AdminOptions();
			}
			else {
				return;
			}
		}
		if (choice == 5) {
			int id;
			string password;
			cout << "Enter id and Password\n";
			cin >> id >> password;
			AdminManager::RemoveEmployee(id, password, allEmployees);

			cout << "\n\nEnter Y to return to the menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				AdminManager::PrintAdminMenu();
				AdminOptions();
			}
			else {
				return;
			}
		}
		if (choice == 6) {
				int id;
				string password;
				cout << "Enter CLient id and Password";
				cin >> id >> password;
				loggedInEmployee = EmployeeManager::login(id, password, allEmployees);
				EmployeeManager::updatePassword(loggedInEmployee);

				cout << "\n\nEnter Y to return to the menu, N to Exit the program. \n";
				char toReturn;
				cin >> toReturn;
				if (toReturn == 'Y' || toReturn == 'y') {
					//back to main page
					AdminManager::PrintAdminMenu();
					AdminOptions();
				}
				else {
					return;
				}

		}
		if (choice == 7) {
			Employee::listclient();
			cout << "\n\nEnter Y to return to the menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				AdminManager::PrintAdminMenu();
				AdminOptions();
			}
			else {
				return;
			}
		}
		if (choice == 8) {
			EmployeeManager::listEmployee();
			cout << "\n\nEnter Y to return to the menu, N to Exit the program. \n";
			char toReturn;
			cin >> toReturn;
			if (toReturn == 'Y' || toReturn == 'y') {
				//back to main page
				AdminManager::PrintAdminMenu();
				AdminOptions();
			}
			else {
				return;
			}
		}
	}

	static void logOut() {
		screensClass::welcome();
		screensClass::loginOptions();
	}
};


