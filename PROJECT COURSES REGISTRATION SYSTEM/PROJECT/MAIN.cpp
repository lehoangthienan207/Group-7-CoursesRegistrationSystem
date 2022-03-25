//#include <iostream>
//#include <string>
#include "PROJECT.h"
#include "PROJECT.cpp"

//using namespace std;

int main()
{
	fstream input, output;	
	input.open("Student.csv", ios::in);
	while (true)
	{
		//the condition of this loop will be replaced.
		int type;
		//
		//Input csv file
		//
		SignIn *pHead = nullptr;
		//When log in in the system, is there a need to know what type of user beforehand
		//
		//
		cout << "COURSES REGISTRATION SYSTEM BY GROUP 7\n";
		cout << "PLEASE LOG IN\n";

		LogIn(pHead);
		// Needed a show profile function (student or staff or teacher)
		// Needed a log out function
		menuOfGeneral(type);
		doSomething(menuOfGeneral(type),type,pHead);

	}
	input.close();
	return 0;
	
}