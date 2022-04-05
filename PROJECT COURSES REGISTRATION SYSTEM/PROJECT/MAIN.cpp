#include "PROJECT.h"
#include "PROJECT.cpp"
int main()
{
	SignIn *pStaff = nullptr;
	inputSignInStaff(pStaff);
	SignIn *pStudent = nullptr;
	inputSignInStudent(pStudent);
	SignIn *pCurr = pStudent;
	while (pCurr != nullptr)
	{
		cout << pCurr->ID << " "<< pCurr->Password << " " << pCurr->Name << " " << pCurr->SocialID << " " << pCurr->DoB << " " << pCurr->Gender;
		cout << "\n";
		pCurr = pCurr->pNext;
	}
	return 0;
}