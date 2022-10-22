#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "person.h"
#include "client.h"
#include "admin.h"
#include "employee.h"
#include "fileManager.h"
#include "screensClass.h"
#include "retrieve.h"
using namespace std;



int main() {
	Retrieve::fileToClient();
	Retrieve::fileToEmp();
	Retrieve::fileToAdmin();


	
	system("pause");
	return 0;
}

