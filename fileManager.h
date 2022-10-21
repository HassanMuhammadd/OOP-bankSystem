#pragma once
#include "dataSourceInterface.h"
#include"fileHelper.h"

class FileManager : public DataSourceInterface {
public:
	static void addClient(Client c) {
		Filehelper::saveclient(c);	
	}
	static void addEmployee(Employee e) {
		Filehelper::saveEmployee(e);
	}

	static void getAllClients() {
		Filehelper::getAllClients();	
	}
	static void getAllEmployees() {
		Filehelper::getAllEmployees();
	}
	static void getAllAdmins() {
		Filehelper::getAdmin();
	}

	static void removeAllClients() {
		ofstream clientFile("clients.txt");
		clientFile << "";
	}
	static void removeAllEmployees() {
		ofstream empFile("employees.txt");
		empFile << "";
	}
	static void removeAllAdmins() {
		ofstream adminFile("admins.txt");
		adminFile << "";
	}
};