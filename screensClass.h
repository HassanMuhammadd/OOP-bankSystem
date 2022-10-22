#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include "client.h"
#include "clientManager.h"

using namespace std;
/*
int loginChoice;

class screensClass {
public:

	static void runApp() {
		welcome();
		loginOptions();
		loginChoice = loginAs();
		invalid(loginChoice);
		loginScreen(loginChoice);
	}

	static void welcome() {
		cout << "Welcome to ALO bank\n===============================\n";
	}
	static void loginOptions() {
		cout << "Login as: \n\n";
		cout << "1:Admin\n2:Employee\n3:Client\n";
	}
				
	static int loginAs() {
		int choice;
		cin >> choice;
		return choice;
	}
	static void invalid(int c) {
		if (c != 1 && c != 2 && c != 3) {
			cout << "Invalid Option.\n";
			loginAs();
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
			int id;
			string password;
			cin >> id >> password;
			//client options
			ClientManager::PrintClientMenu();
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
*/