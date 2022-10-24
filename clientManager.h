#pragma once

#include<iostream>
#include<fstream>
#include<vector>
#include "client.h"
using namespace std;




//class ClientManager {
//public:
//	static void PrintClientMenu() {
//		cout << endl << "===============================\n\n";
//		cout << "1.deposit" << endl << "2.withdraw" << endl << "3.transfer to another client" << endl << "4.display info" << endl << "-1.Log out\n";
//	}	
//	
//
//	static Client* login(int id, string password,vector<Client>& allClients) {
//		bool found = false;
//		
//		for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {
//			if (clientIt->getID() == id && clientIt->getPassword() == password) {
//				found = true;
//				return clientIt._Ptr;
//			}
//		}
//		if (!found) {
//			cout << "Invalid Client data\n";
//			cout << "Enter Client ID and Password: \n";
//			int id;
//			string password;
//			login(id, password, allClients);
//		}
//	}
//	
//
//	
//	
//};
