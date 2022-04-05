#include "PROJECT.h"
#include "PROJECT.cpp"
int main()
{
	SignIn *pStaff = nullptr;
	inputSignInStaff(pStaff);
	SignIn *pCurr = pStaff;
	while (pCurr != nullptr)
	{
		cout << pCurr->ID << " " << pCurr->Password << " " << pCurr->Name << " " << pCurr->Email;
		cout << "\n";
		pCurr = pCurr->pNext;
	}
	return 0;
}