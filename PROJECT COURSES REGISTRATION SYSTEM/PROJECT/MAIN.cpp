#include "PROJECT.h"
#include "PROJECT.cpp"
int main()
{
	SignIn *pStaff = nullptr;
	SignIn *pStaffCurr = nullptr;
	inputSignInStaff(pStaff);
	SignIn *pStudent = nullptr;
	SignIn *pStudentCurr = nullptr;
	SchoolYear *pHead = nullptr;
	SchoolYear *pCurr = pHead;
	ScoreBoardOfStudent *pScoreBoard = nullptr;	
	inputSignInStudent(pStudent);
	GeneralMenu(pStaff,pStudent,pHead,pCurr);
	


	deleteCourses(pHead->pSemester->pCourse);
	deleteClasses(pHead->pClass);
	deleteSemester(pHead->pSemester);
	deleteSchoolYear(pHead);
	deleteSignIn(pStaff);
	deleteSignIn(pStudent);
	return 0;
}