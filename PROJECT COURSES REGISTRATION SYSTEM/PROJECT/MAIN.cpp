#include "PROJECT.h"
#include "PROJECT.cpp"
int main()
{
	SignIn *pStaff = nullptr;
	inputSignInStaff(pStaff);
	SignIn *pStudent = nullptr;
	inputSignInStudent(pStudent);
	SignIn *pCurr = pStudent;
	
	GeneralMenu();






	deleteSignIn(pStaff);
	deleteSignIn(pStudent);
	return 0;
}