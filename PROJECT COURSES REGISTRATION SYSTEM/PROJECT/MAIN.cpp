#include "PROJECT.h"
#include "PROJECT.cpp"
int main()
{
	SignIn *pStaff = nullptr;
	SignIn *pStudent = nullptr;
	inputSignInStaff(pStaff);
	inputSignInStudent(pStudent);
	//nhập thông tin để có thể đăng nhập vào
	SchoolYear *pSchool = nullptr;
	readSchoolYearlist(pSchool);
	readSchoolYearlist(pSchool);
	readSemesterList(pSchool);
	return 0;
}