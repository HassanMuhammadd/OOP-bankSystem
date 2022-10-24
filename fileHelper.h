#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "client.h"
#include "employee.h"
using namespace std;
class Filehelper {


public:
	static void savelast(string fileName, int id) {
		ofstream file;
		file.open(fileName);
		file << id;
		file.close();
	}
	static int getlastClient() {
		ifstream file;
		file.open("lastclientid.txt");
		int id;
		file >> id;
		file.close();
		return id;
	}
	static void saveclient(Client c) {
		int id = getlastClient();
		ofstream file;
		file.open("clients.txt", ios::app);
		file << c.getName() << " " << id + 1 << ' ' << c.getPassword() << " " << c.getBalance()<<endl;
		file.close();
		savelast("lastclientid.txt", id + 1);
	}
	static int getLastEmp() {
		ifstream file;
		file.open("lastempid.txt");
		int id;
		file >> id;
		file.close();
		return id;
	}
	static void saveEmployee(Employee e) {
		int id = getLastEmp();
		ofstream file;
		file.open("employees.txt", ios::app);
		file << e.getName() << " " << id + 1 << " " << e.getPassword() << " " << e.getSalary() << endl;
		file.close();
		savelast("lastempid.txt", id + 1);
	}

	static void clearClientsFile() {
		ofstream clientsFile,idFile;
		clientsFile.open("clients.txt");
		clientsFile << " ";
	}
	static void clearEmployeesFile() {
		ofstream empFile;
		empFile.open("employees.txt");
		empFile << " ";
	}

	static void getAllClients() {
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
	static void getAllEmployees() {
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
	static void getAdmin() {
		ifstream adminFiles("admins.txt");
		string name, password;
		double salary;
		int id;
		//take input from txt file
		while (adminFiles >> name >> id >> salary >> password) {
			mainAdmin.setName(name);
			mainAdmin.setID(id);
			mainAdmin.setPassword(password);
			mainAdmin.setSalary(salary);
		}

	}
};
