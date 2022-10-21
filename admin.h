#pragma once
#include <iostream>
#include <vector>
#include "person.h"
#include "employee.h"
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