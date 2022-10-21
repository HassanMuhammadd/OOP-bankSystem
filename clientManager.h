#pragma once

#include<iostream>
#include<fstream>
#include "client.h"
using namespace std;




class ClientManager {
public:
	static void PrintClientMenu() {
		cout << endl << "===============================\n\n";
		cout << "1.deposit" << endl << "2.withdraw" << endl << "3.transfer to another client" << endl << "4.display info" << endl << "-1.Log out\n";
	}	
	
	/*static Client clientLogin(int id, string password) {
		bool found = false;
		ifstream clientFile;
		clientFile.open("clients.txt");
		string name;
		string pass;
		int oldid;
		double balance;
		Client returns;
		while (clientFile >> name >> oldid >> balance >> pass)
		{
			if (oldid == id && pass==password) {
				found = true;
				returns.setName(name);
				returns.setPassword(pass);
				returns.setBalance(balance);
			}
		}
		if (found)
			return returns;
		else {
			cout << "Client ID not found.\n";
			cout << "Enter Client ID and password: \n";
			cin >> id >> password;
			clientLogin(id, password);
		}
	}
	*/

	
	
};
